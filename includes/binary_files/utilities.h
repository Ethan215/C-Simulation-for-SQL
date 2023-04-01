#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

bool file_exists(const char filename[]);
void open_fileRW(fstream& f, const char filename[]);    // Open the file for reading and writing.
void open_fileW(fstream& f, const char filename[]);     // Open the file for writing.

#endif //UTILITIES_H