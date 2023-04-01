#ifndef TOKEN_H
#define TOKEN_H

#include "../tokenizer/constants.h"
using namespace std;

class Token{
public:
    Token();
    virtual ~Token();
    friend ostream& operator <<(ostream& outs, const Token* token);
    friend ostream& operator <<(ostream& outs, const Token& token);
    virtual void Print(ostream& outs = cout) const = 0;
    virtual TOKENS TypeOf() const = 0;
    virtual string Get() const = 0;
};

bool compare(const Token* t1, const Token* t2);

#endif //TOKEN_H