#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_COLUMNS = 256;
const int MAX_ROWS = 100;
const int MAX_BUFFER = 200;

const char ALPHA[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char DIGITS[] = "0123456789";
const char OTHERS[] = "?/.':;|\\]}[{+-_&^%$#@!~`"; // No ','
const char OPERATORS[] = "><=";
const char PUNC[] = "*()";
const char SPACES[] = {' ', '\t', '\n', '\0'};

enum TOKEN_TYPES { TOKEN_ALPHA = 1, TOKEN_DIGIT, TOKEN_OTHERS, TOKEN_OPERATOR, TOKEN_PUNC, TOKEN_SPECIAL = 8 };
enum TOKENS { TOKENSTR = 1, RELATIONAL, LOGICAL, LPAREN = 5, RPAREN };   

#endif //CONSTANTS_H