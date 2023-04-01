#ifndef TOKENS_H
#define TOKENS_H

#include "constants.h"
using namespace std;

class TokenS{
public:
    TokenS();
    TokenS(string str, int type);
    friend ostream& operator <<(ostream& outs, const TokenS& t);
    int type() const;
    string type_string() const;
    string token_str() const;

private:
    string _token;
    int _type;
};

#endif //TOKENS_H