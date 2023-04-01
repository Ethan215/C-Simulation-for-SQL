#include "stokenize.h"
using namespace std;

int STokenizer::_table[MAX_ROWS][MAX_COLUMNS];

STokenizer::STokenizer(){
    char str[] = "";
    set_string(str);
    make_table(_table);
}

STokenizer::STokenizer(char str[]){
    set_string(str);
    make_table(_table);
}

bool STokenizer::done(){
    return _pos > strlen(_buffer);
}

bool STokenizer::more(){
    return !done();
}

STokenizer& operator >> (STokenizer& s, TokenS& t){
    string str = "";
    int type = 0;
    s.get_token(type, str);
    t = TokenS(str, type);
    return s;
}

void STokenizer::set_string(char str[]){
    _pos = 0;
    for (int i = _pos; i < strlen(str); ++i)
        _buffer[i] = str[i];
    _buffer[strlen(str)] = '\0';
}

void STokenizer::make_table(int _table[][MAX_COLUMNS]){
    init_table(_table);
    
    for (int i = 0; i <= 8; ++i){
        if (i == 0 || i == 6 || i == 7)
            mark_fail(_table, i);
        else
            mark_success(_table, i);
    }

    mark_cells(0, _table, ALPHA, 1);
    mark_cells(0, _table, DIGITS, 2);
    mark_cells(0, _table, OTHERS, 3);
    mark_cells(0, _table, OPERATORS, 4);
    mark_cells(0, _table, PUNC, 5);
    mark_cell(0, _table, '\"', 6);

    mark_cells(1, _table, ALPHA, 1);
    mark_cells(2, _table, DIGITS, 2);
    mark_cells(3, _table, OTHERS, 3);
    mark_cells(4, _table, OPERATORS, 4);

    mark_cells(6, _table, ALPHA, 7);
    mark_cells(6, _table, DIGITS, 7);
    mark_cells(6, _table, OTHERS, 7);
    mark_cells(6, _table, SPACES, 7); 
    mark_cells(7, _table, ALPHA, 7);
    mark_cells(7, _table, DIGITS, 7);
    mark_cells(7, _table, OTHERS, 7);
    mark_cells(7, _table, SPACES, 7);
    mark_cell(7, _table, '\"', 8);
}

bool STokenizer::get_token(int& end_state, string& token){
    int initial_pos = _pos;
    int final_pos = _pos;

    // i = row (state)
    // j = column (input)
    for (int i = end_state, j = _buffer[_pos]; _pos < strlen(_buffer) && _table[i][j] != -1; i = _table[i][j], j = _buffer[++_pos]){
        if (is_success(_table, _table[i][j])){
            end_state = _table[i][j];
            final_pos = _pos;
        }

        if (j < 0 || j > MAX_COLUMNS)   //Unknown characters
            break;
    }

    if (end_state > 0){
        for (int i = initial_pos; i <= final_pos; ++i)
            token += _buffer[i];
        _pos = final_pos + 1;           //Reset the position to the position after the last successful state
        return true;
    }
    token += _buffer[_pos++];           //Increment the position to the next position
    return false;
}