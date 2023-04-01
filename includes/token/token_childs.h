#ifndef TOKEN_CHILDS_H
#define TOKEN_CHILDS_H

#include "token.h"
using namespace std;

class TokenStr : public Token{
public:
    TokenStr(){ _val = ""; }
    TokenStr(const string& value){ _val = value; }
    ~TokenStr(){ }
    void Print(ostream &outs = cout) const { outs << "[" << _val << "]"; }
    TOKENS TypeOf() const { return TOKENSTR; }
    string Get() const { return _val; }

private:
    string _val;
};

class Relational : public Token{
public:
    Relational(){ _val = ""; }
    Relational(const string& value){ _val = value; }
    ~Relational(){ }
    void Print(ostream &outs = cout) const { outs << "[" << _val << "]"; }
    TOKENS TypeOf() const { return RELATIONAL; }
    string Get() const { return _val; }

private:
    string _val;
};

class Logical : public Token{
public:
    Logical(){ _val = ""; }
    Logical(const string& value){ _val = value; }
    ~Logical(){ }
    void Print(ostream &outs = cout) const { outs << "[" << _val << "]"; }
    TOKENS TypeOf() const { return LOGICAL; }
    string Get() const { return _val; }

private:
    string _val;
};

class LParen : public Token{
public:
    LParen(){ }
    ~LParen(){ }
    void Print(ostream &outs = cout) const { outs << "[L]"; }
    TOKENS TypeOf() const { return LPAREN; }
    string Get() const { return "("; }
};

class RParen : public Token{
public:
    RParen(){ } 
    ~RParen(){ }
    void Print(ostream &outs = cout) const { outs << "[R]"; }
    TOKENS TypeOf() const { return RPAREN; }
    string Get() const { return ")"; }
};
#endif //TOKEN_CHILDS_H