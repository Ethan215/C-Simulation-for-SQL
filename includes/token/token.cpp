#include "token.h"
using namespace std;

Token::Token(){ }

Token::~Token(){ }

ostream& operator <<(ostream& outs, const Token* token){
    outs << *token;
    return outs;
}

ostream& operator <<(ostream& outs, const Token& token){
    token.Print();
    return outs;
}

void Token::Print(ostream& outs) const{
    outs << "Token: DON'T @#$%^&* call me again!";
}

bool compare(const Token* t1, const Token* t2){
    if (t1->TypeOf() == LOGICAL && t2->TypeOf() == LOGICAL){
        if (t1->Get() == "and" && t2->Get() == "or")
            return true;
        
        return t1->Get() == t2->Get();
    }
    return t1->TypeOf() < t2->TypeOf(); // If t1 < t2, t1 is RELATIONAL, pop it and push it to the postfix queue.
}