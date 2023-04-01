#include "state_machine_functions.h"
using namespace std;

void init_table(int _table[][MAX_COLUMNS]){
    for (int i = 0; i < MAX_ROWS; ++i){
        for (int j = 0; j < MAX_COLUMNS; ++j)
            _table[i][j] = -1;
    }
}

void mark_success(int _table[][MAX_COLUMNS], int state){
    _table[state][0] = 1; 
}

void mark_fail(int _table[][MAX_COLUMNS], int state){
    _table[state][0] = 0;     
}

bool is_success(int _table[][MAX_COLUMNS], int state){
    return _table[state][0] == 1;
}
 
void mark_cells(int row, int _table[][MAX_COLUMNS], int from, int to, int state){
    for (int j = from; j <= to; ++j)
        _table[row][j] = state;
}

void mark_cells(int row, int _table[][MAX_COLUMNS], const char columns[], int state){
    for (int i = 0; i < strlen(columns); ++i){
        int j = columns[i];
        _table[row][j] = state;
    }
}

void mark_cell(int row, int _table[][MAX_COLUMNS], int column, int state){
    _table[row][column] = state;
}

void print_table(int _table[][MAX_COLUMNS]){
    for (int i = 0; i < MAX_ROWS; ++i){
        for (int j = 0; j < MAX_COLUMNS; ++j)
            cout << _table[i][j] << " ";
        cout << endl << endl;
    }
}

void show_string(char s[], int _pos){
    cout << s << setw(10) << "pos: " << _pos << endl
        << setw(_pos+1) << "^" << endl;
}