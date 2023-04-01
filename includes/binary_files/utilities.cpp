#include "utilities.h"
using namespace std;

bool file_exists(const char filename[]){
    const bool debug = false;
    fstream f;
    f.open(filename, std::fstream::in | std::fstream::binary);

    if (f.fail()){
        if (debug) cout << "file_exists(): File does NOT exist: " << filename << endl;
        return false;
    }

    if (debug) cout << "file_exists(): File DOES exist: " << filename << endl;
    f.close();
    return true;
}

void open_fileRW(fstream& f, const char filename[]){
    const bool debug = false;
    // Opening a nonexistent file for in|out|app causes a fail()
    // so if the file does not exist, create it by opening it for output:
    if (!file_exists(filename)){
        f.open(filename, std::fstream::out | std::fstream::binary);

        if (f.fail()){
            if (debug) cout << "open_fileRW failed: " << filename << endl;
            throw("file failed to create.");
        }

        else {
            if (debug) cout << "open_fileRW: file created successfully: " << filename << endl;
        }
    }

    else {
        f.open(filename, std::fstream::in | std::fstream::out | std::fstream::binary);

        if (f.fail()){
            if (debug) cout << "open_fileRW failed: " << filename << endl;
            throw("file failed to open.");
        }
    }
}

void open_fileW(fstream& f, const char filename[]){
    const bool debug = false;   
    f.open(filename, std::fstream::out | std::fstream::binary);

    if (f.fail()){
        if (debug) cout << "open_fileW failed: " << filename << endl;
        throw("file failed to open.");
    }
}