#ifndef FTOKENIZE_H
#define FTOKENIZE_H

#include <fstream>
#include "stokenize.h"
using namespace std;

class FTokenizer
{
public:
    const int MAX_BLOCK = MAX_BUFFER;
    FTokenizer(char* fname);
    TokenS next_token();
    int pos();              //returns the value of _pos
    int block_pos();        //returns the value of _blockPos
    bool more();            //returns the current value of _more
    friend FTokenizer& operator >> (FTokenizer& f, TokenS& t);

private:
    bool get_new_block();   //gets the new block from the file
    ifstream _f;            //file being tokenized
    STokenizer _stk;        //the STokenizer object to tokenize current block
    int _pos;               //current position in the file
    int _blockPos;          //current position in the current block
    bool _more;             //false if last token of the last block
                            // has been processed and now we are at
                            // the end of the last block.
};

#endif //FTOKENIZE_H