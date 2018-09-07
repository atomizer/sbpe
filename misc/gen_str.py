# the goal is to produce universal definitions for all platforms
# current version produces approximately same output for win and linux
# ida makes garbage from mac version for some reason, so can't check

# usage:
#   using IDA, open mvmmoclient
#   menu: File -> Produce file -> Create C header file
#   place mvmmoclient.h here
#   python gen_str.py mvmmoclient.h
#   place generated.h in ../cdefs/, proto.json in ..

import re
import json
import sys

DEFINE = re.compile(r'#define ([^ ]+) (.*)')
TYPEDEF_FUN = re.compile(r'typedef \w+ \(\*(\w+)\)\(.*\);')
TYPEDEF = re.compile(r'typedef (.*?) ([^ ]+);')
SFORWARD = re.compile(r'struct (.*);')

ALIGN = re.compile(r' __attribute__\(\(aligned\(\d+\)\)\)')
SNAME = r'[A-Z][A-Za-z0-9]?[A-Za-z0-9_]*(?:::[A-Z][A-Za-z_]*)*(?:<.*?>)?'
SDEF = 'struct(?: __cppobj)? ({0})(?: : ({0})(?::\\d+)?)?\n'.format(SNAME)
SDEF = re.compile(SDEF)

STLINE = re.compile(r'^  (.+?) ([a-zA-Z0-9_\[\]\*\.\(\)]+);\n')

ENUM = re.compile('enum ({0}) : (.*)'.format(SNAME))

COMPLEXTYPE = re.compile(r'([^<]+)<(.*)>$')

GENERIC = ('void,bool,char,short,int,long,long long,float,double,' +
           'unsigned int,unsigned short,' +
           'unsigned char,unsigned long long').split(',')

defines = {'*const ': '*'}
types = {}
for g in GENERIC:
    types[g] = g
parents = {}
seenstructs = {}
forwards = set()

# supported std:: struct types
STD = {
    'string': 'String',
    'basic_string': 'String',
    'vector': 'Vector',
    'unordered_map': 'UMap',
    'deque': 'Deque',
    'function': 'Function',
    'unordered_set': 'USet'
}


def ignore(name):
    ignored = [
        'XDL_', 'SDL_',
        '__', '_Unwind', 'SjLj',
        'StaticDescriptorInitializer_',
        'Logging', 'Severity',  # win-specific
        'VARENUM', 'HWND', 'HINSTANCE', 'FARPROC', 'DIR', 'WSAData',
        'Elf64_', 'CSteamID', 'CCallback',  # linux-specific
    ]
    for x in ignored:
        if name.startswith(x):
            return True
    if '__lambda' in name:
        return True
    return False


def safeName(n):
    return n.replace(':', '_').split('<')[0]


def doLine(line, st, out=sys.stdout):
    if st == 'out':
        # #define
        m = DEFINE.match(line)
        if m is not None:
            defines[m[1]] = m[2]
            return st
        # typedef
        m = TYPEDEF_FUN.match(line)
        if m is not None:
            if ignore(m[1]):
                return st
            types[m[1]] = m[1]
            out.write(line)
            return st
        m = TYPEDEF.match(line)
        if m is not None:
            srct = m[1]
            if srct in types:
                srct = types[srct]
            tname = m[2]
            if tname[0] == '*':
                tname = tname[1:]
                srct += ' *'
            if tname.endswith('_t'):  # skip base type redefs (int32_t etc.)
                return st
            types[tname] = srct
            return st
        # struct forward
        m = SFORWARD.match(line)
        if m is not None:
            if ignore(m[1]):
                return 'out'
            sname = m[1]
            mn = COMPLEXTYPE.match(sname)
            if mn is not None:
                sname = mn[1]
            if safeName(sname) in forwards:
                return st
            else:
                forwards.add(safeName(sname))
            m2 = re.match(SNAME, sname)
            if m2 is not None:
                types[sname] = 'struct ' + sname
                out.write('struct {};\n'.format(safeName(sname)))
            return st
        # struct
        m = SDEF.match(line)
        if m is not None:
            if ignore(m[1]):
                return 'out'
            sname = m[1]
            mn = COMPLEXTYPE.match(sname)
            if mn is not None:
                sname = mn[1]
                if sname in seenstructs:
                    # out.write('// skipped {}\n'.format(m[1]))
                    return 'out'
                seenstructs[sname] = True
            types[sname] = 'struct ' + sname
            out.write('struct {0} {{\n'.format(safeName(sname)))
            if m[2] is not None:  # add prototype
                out.write('  struct {0} as{0};\n'.format(safeName(m[2])))
            return 'inStruct'
        # enum
        m = ENUM.match(line)
        if m is not None:
            if ignore(m[1]):
                return 'out'
            types[m[1]] = 'enum ' + m[1]
            out.write('enum {0} {{\n'.format(safeName(m[1])))
            return 'inEnum'
        pass

    if st[0:2] == 'in':
        if line[0] == '}':
            out.write(line)
            return 'out'
        if line[0] == '{':
            return st

    if st == 'inEnum':
        out.write(line)
        return st

    if st == 'inStruct':
        m = STLINE.match(line)
        if m is None:
            raise Exception('unmatched STLINE: ' + line)

        lname = m[2]
        if lname[-1] == '_':
            lname = lname[:-1]
        lname = lname.replace('_[', '[')

        ltype = m[1]
        if ltype.startswith('const '):
            ltype = ltype[6:]

        if ltype in types:
            ltype = types[ltype]

        m = COMPLEXTYPE.match(ltype)
        comment = ''
        if m is not None:
            tp = m[1].split('::')
            if tp[0] == 'std':
                if tp[1] in STD:
                    ltype = 'struct STD' + STD[tp[1]]
                    if not tp[1].endswith('string'):
                        comment = m[2]
                else:
                    raise Exception('unknown std type: ' + tp[1])
            elif tp[0] == 'google':
                if tp[2] == 'RepeatedPtrField':
                    ltype = 'struct RepeatedPtrField'
                    comment = m[2]
                elif tp[2] == 'RepeatedField':
                    ltype = 'struct RepeatedField_' + m[2]
                else:
                    raise Exception('unknown google type: ' + ltype)
            else:
                ltype = m[1]
                comment = m[2]

        if ltype[-1] == '*':
            ltype = ltype[:-1].strip()
            lname = '*' + lname

        if ltype in types:
            ltype = types[ltype]
        else:
            beg = ltype.split(' ')[0]
            if beg not in ['struct', 'enum'] and ltype.endswith('_t') is False:
                if lname.startswith('*'):
                    comment = ltype
                    ltype = 'void'
                else:
                    print('WARNING: unknown type: {} {}'.format(ltype, lname))
                    ltype = '// ' + ltype

        if lname.startswith('(**_vptr') or lname.startswith('baseclass_'):
            ltype = 'void'
            lname = '*classptr'

        out.write('  {0} {1};'.format(safeName(ltype), lname))
        if comment:
            out.write(' // ' + comment)
        out.write('\n')
        return st
    return st


def protochain(name, chain=None):
    if chain is None:
        chain = []
    p = parents[name]
    chain.insert(0, p)
    if p in parents:
        return protochain(p, chain)
    else:
        chain.reverse()
        return chain


def main(hpath):
    with open(hpath, 'r') as f:
        with open('generated.h', 'w') as of:
            state = 'out'
            while 1:
                s = f.readline()
                if s == '':
                    break
                for k in defines:
                    s = s.replace(k, defines[k])
                s = ALIGN.sub('', s)

                state = doLine(s, state, out=of)
                m = re.match(SDEF, s)
                if m is None or m[2] is None:
                    continue
                child = m[1]
                parent = m[2]
                parents[child] = parent

    pchains = {}
    for child in parents:
        pchains[child] = protochain(child)

    castable = {}
    for child in pchains:
        chain = pchains[child]
        for p in chain:
            if p not in castable:
                castable[p] = []
            castable[p].append(child)
            castable[p].sort()

    with open('proto.json', 'w') as f:
        json.dump({'chains': pchains, 'castable': castable}, f,
                  sort_keys=True, indent=2, separators=(',', ': '))


if __name__ == '__main__':
    main(sys.argv[1])
