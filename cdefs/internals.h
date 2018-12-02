typedef unsigned char bool;

// ---------------------------------------------------------------------------
// C++ structs (as observed)

// std::string
struct STDString {
  char *s;
  // actual layout near the string pointer's address:
  //     int length, int capacity, int refcount, char string[length], \0
  //
  // to "free": refcount--; if (refcount < 0) free(s - 12) (potentially dangerous)
  // to "create":
  //   buf = malloc(length + 13)
  //   (int*)(buf) = (int*)(buf + 4) = length
  //   (int*)(buf + 8) = 0
  //   memcpy(buf + 12, string, length + 1)
  //   return buf + 12
};

// std::vector
struct STDVector { // length = v.finish - v.start / sizeof(elem_type)
  void *start; // points at the first element
  void *finish; // points _after_ the last element
  void *endOfStorage; // _after_ end of storage
};

// std::_Hashtable
struct STDHashtable {
  void *buckets;
  int bucket_count;
  void *before_begin;
  int element_count;
  float max_load_factor;
  int next_resize;
};

// std::unordered_map
struct STDUMap {
  struct STDHashtable t;
};

// std::unordered_set
struct STDUSet {
  struct STDHashtable t;
};

// std::deque<>::iterator
struct DIterator {
  int cur;
  int first;
  int last;
  int node;
};

// std::deque
struct STDDeque {
  int map;
  int mapSize;
  struct DIterator start;
  struct DIterator finish;
};

// std::function
struct STDFunction {
  void *ptr;
  int delta;
  void *manager;
  void *invoker;
};

// std::pair<uint, void*>
struct SortedVecElement {
  unsigned int key;
  void *obj;
};

// std::pair<Label*, Label*>
struct LabelPair {
  struct Label *first;
  struct Label *second;
};

// ---------------------------------------------------------------------------
// protobuf-related

struct RepeatedPtrField {
  void **elements;
  int current_size;
  int allocated_size;
  int total_size;
};

struct RepeatedField_int {
  int32_t *elements;
  int current_size;
  int total_size;
};
