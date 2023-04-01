#ifndef PARSER_H
#define PARSER_H

#include "../table/typedefs.h"
using namespace std;

class Parser{
public:
    Parser();
    Parser(char str[]);

    void set_string(char str[]);
    void make_table();
    void build_keyword_list();
    long get_column(const string& token);
    bool get_parse_tree();

    // Accessors and mutators
    mmap_ss parse_tree() const { return _ptree; }
    bool fail() const { return !_flag; }

private:
    char _buffer[MAX_BUFFER];
    static int _table[MAX_ROWS][MAX_COLUMNS];

    vectorstr _inputq;
    map_sl _keywords;
    mmap_ss _ptree;
    bool _flag;
    enum keys { MAKE = 1, TABLE, INSERT, INTO, SELECT, FIELDS, VALUES, FROM, STAR, WHERE, SYMBOL };
    // enum keys { MAKE = 1, TABLE, INSERT, INTO, SELECT, FIELDS, VALUES, FROM, STAR, WHERE, LPAREN_OP, RPAREN_OP, RELATIONAL_OP, LOGICAL_OP, SYMBOL };
};

#endif //PARSER_H