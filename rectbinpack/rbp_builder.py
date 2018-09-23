import cffi

SRCLIST = 'Rect.cpp MaxRectsBinPack.cpp'.split()


def readfile(path):
    with open(path, 'r') as f:
        return f.read()


ffibuilder = cffi.FFI()

ffibuilder.cdef(readfile('rbp.h'))

ffibuilder.set_source(
    '_rbp', readfile('rbp.cpp'), source_extension='.cpp', sources=SRCLIST)

if __name__ == '__main__':
    ffibuilder.compile()
