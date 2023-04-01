#include "ftokenize.h"
using namespace std;

FTokenizer::FTokenizer(char* fname){
    _f.open(fname);  //string = const char* NOT char*

    if (_f.fail()){
        cout << "Input file opening failed.\n";
        exit(1);
    }
    _pos = 0;
    _blockPos = 0;
    _more = get_new_block();
}

TokenS FTokenizer::next_token(){
    TokenS t;
    _stk >> t;

    // Not used
    _pos += t.token_str().size(); 
    _blockPos += t.token_str().size(); 

    if (_stk.done())
        _more = get_new_block();

    return t;
}

bool FTokenizer::more(){
    return _more;
}

int FTokenizer::pos(){
    return _pos;
}

int FTokenizer::block_pos(){
    return _blockPos;
}

FTokenizer& operator >> (FTokenizer& f, TokenS& t){
    t = f.next_token();
    return f;
}

bool FTokenizer::get_new_block(){
    if (_f){    //NOT EOF
        _blockPos = 0;
        char buffer[MAX_BLOCK];
        _f.read(buffer, MAX_BLOCK-1);
        buffer[_f.gcount()] = '\0';
        _stk.set_string(buffer);
        cout << "----- New Block -------------------- [" << _f.gcount() <<  "] bytes\n";  
        return true;
    }
    _f.close();
    cout << "*** END OF FILE ***\n";
    return false;
}