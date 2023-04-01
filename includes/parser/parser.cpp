#include "parser.h"
using namespace std;

int Parser::_table[MAX_ROWS][MAX_COLUMNS];

Parser::Parser(){
    char str[] = "";
    make_table();
    build_keyword_list();
    set_string(str);
}

Parser::Parser(char str[]){
    make_table();
    build_keyword_list();
    set_string(str);
}

void Parser::set_string(char str[]){
    _inputq.clear();
    strcpy(_buffer, str);
    STokenizer stk(_buffer);
    TokenS t;
    stk >> t;

    while (stk.more()){
        string type = t.type_string();

        if (t.type() >= TOKEN_ALPHA && t.type() <= TOKEN_PUNC)
            _inputq += t.token_str();

        else if (t.type() == TOKEN_SPECIAL){
            string temp = t.token_str();
            temp.erase(0, 1);
            temp.erase(temp.size()-1, 1);
            _inputq += temp;
        }
        t = TokenS();
        stk >> t;
    }
    _flag = get_parse_tree();
}

void Parser::make_table(){
    init_table(_table);

    mark_cell(0, _table, MAKE, 1);
    mark_cell(1, _table, TABLE, 2);
    mark_cell(0, _table, INSERT, 1);
    mark_cell(1, _table, INTO, 2);
    mark_cell(0, _table, SELECT, 3);

    mark_cell(2, _table, SYMBOL, 4);
    mark_cell(4, _table, FIELDS, 5);
    mark_cell(4, _table, VALUES, 7);
    mark_cell(5, _table, SYMBOL, 6);
    mark_cell(6, _table, SYMBOL, 6);
    mark_cell(7, _table, SYMBOL, 8);
    mark_cell(8, _table, SYMBOL, 8);

    mark_cell(3, _table, STAR, 9);      // "select *"
    mark_cell(3, _table, SYMBOL, 12);   // "select FIELDS"
    mark_cell(12, _table, SYMBOL, 12);
    mark_cell(9, _table, FROM, 10);
    mark_cell(12, _table, FROM, 10);
    mark_cell(10, _table, SYMBOL, 11);
    
    mark_cell(11, _table, WHERE, 13);
    mark_cell(13, _table, SYMBOL, 14);
    mark_cell(14, _table, SYMBOL, 14);

    // conditions without parentheses
    // mark_cell(13, _table, SYMBOL, 14);
    // mark_cell(14, _table, RELATIONAL_OP, 15);
    // mark_cell(15, _table, SYMBOL, 16);
    // mark_cell(16, _table, LOGICAL_OP, 17);
    // mark_cell(17, _table, SYMBOL, 14);

    // // conditions with parentheses
    // mark_cell(13, _table, LPAREN_OP, 18);
    // mark_cell(17, _table, LPAREN_OP, 18);

    // mark_cell(18, _table, SYMBOL, 19);
    // mark_cell(19, _table, RELATIONAL_OP, 20);
    // mark_cell(20, _table, SYMBOL, 21);
    // mark_cell(21, _table, LOGICAL_OP, 22);
    // mark_cell(22, _table, SYMBOL, 19);

    // mark_cell(21, _table, RPAREN_OP, 23);
    // mark_cell(23, _table, LOGICAL_OP, 13);  // Go back to "where"
    
    for (int i = 0; i <= 14; ++i){
        if (i == 6 || i == 8 || i == 11 || i == 14 || i == 23)
            mark_success(_table, i);

        else
            mark_fail(_table, i);
    }
}

void Parser::build_keyword_list(){
    vectorstr keywords = {"make", "table", "insert", "into", "select", "fields", "values", "from", "*", "where"};
    // vectorstr keywords = {"make", "table", "insert", "into", "select", "fields", "values", "from", "*", "where", "(", ")"};

    for (int i = 0; i < keywords.size(); ++i)
        _keywords[keywords[i]] += i+1;  
}

long Parser::get_column(const string& token){
    if (_keywords.contains(token))
        return _keywords[token];

    // if (token == "=" || token == "<" || token == ">" || token == "<=" || token == ">=")
    //     return RELATIONAL_OP;

    // if (token == "and" || token == "or")
    //     return LOGICAL_OP;

    return SYMBOL;
}   

bool Parser::get_parse_tree(){
    _ptree.clear();
    int state = 0;
    
    for (int i = 0; i < _inputq.size() && state != -1; ++i){
        string token = _inputq[i];
        state = _table[state][get_column(token)];

        switch (state){
            case 1:
            case 3:
                _ptree["command"] += token;
                break;

            case 4:
            case 11:
                _ptree["table_name"] += token;
                break;

            case 6:
                _ptree["col"] += token;
                break;

            case 9:
            case 12:
                _ptree["fields"] += token;
                break;

            case 8:
                _ptree["values"] += token;
                break;

            case 13: {
                string temp = "yes";
                _ptree["where"] += temp;
                break;
            }

            case 14: 
            // case 15: case 16: case 17: case 18: case 19: case 20: case 21: case 22: case 23:
                _ptree["condition"] += token;
                break;

            default:
                break;
        }
    }
    return is_success(_table, state);
}