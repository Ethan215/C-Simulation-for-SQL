#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include "../binary_files/file_record.h"
#include "../bplustree/map.h"
#include "../bplustree/multimap.h"
#include "../tokenizer/ftokenize.h"
#include "../shunting_yard/shunting_yard.h"
using namespace std;

typedef vector<string> vectorstr;
typedef vector<long> vectorl;
typedef Map<string, long> map_sl;
typedef MMap<string, long> mmap_sl;
typedef MMap<string, string> mmap_ss;

#endif //TYPEDEFS_H