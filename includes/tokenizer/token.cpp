#include "token.h"
using namespace std;

TokenS::TokenS(){
    _token = "";
    _type = 0;
}

TokenS::TokenS(string str, int type){
    _token = str;
    _type = type;
}

ostream& operator <<(ostream& outs, const TokenS& t){
    outs << "|" << t._token << "|\n";
    return outs;
}

int TokenS::type() const{
    return _type;
}

string TokenS::type_string() const{
    switch (_type){
        case TOKEN_ALPHA:
            return "ALPHA";
        case TOKEN_DIGIT:
            return "DIGIT";
        case TOKEN_OTHERS:
            return "OTHERS";
        case TOKEN_OPERATOR:
            return "OPERATOR";
        case TOKEN_PUNC:
            return "PUNC";
        case TOKEN_SPECIAL:
            return "SPECIAL";
        default:
            return "UNKNOWN";
    }    
}

string TokenS::token_str() const{
    return _token;
}