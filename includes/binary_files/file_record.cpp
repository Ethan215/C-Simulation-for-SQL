#include "file_record.h"
using namespace std;

long FileRecord::write(fstream &outs){
    outs.seekg(0, outs.end);
    long pos = outs.tellp();   
    outs.write(&_record[0][0], sizeof(_record));
    return pos / sizeof(_record);
}

long FileRecord::read(fstream &ins, long recno){
    long pos = recno * sizeof(_record);
    ins.seekg(pos, ins.beg);
    ins.read(&_record[0][0], sizeof(_record));

    for (_size = 0; _record[_size][0] != '\0'; ++_size) { }
    return ins.gcount();
}

vector<string> FileRecord::get_record() const{
    vector<string> result;

    for (int i = 0; i < _size; ++i)
        result.push_back(_record[i]);
    
    return result;   
}

ostream& operator <<(ostream& outs, const FileRecord& r){
    for (int i = 0; i < r._size ; ++i)
        outs << setw(25) << r._record[i];

    return outs;
}