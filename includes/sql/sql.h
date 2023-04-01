#ifndef SQL_H
#define SQL_H

#include "../table/table.h"
#include "../parser/parser.h"
using namespace std;

class SQL{
public:
    SQL(){ }
    SQL(const string& name){ batch(name); }
    // ~SQL(){ drop_table(); }

    Table command(const string& command);
    vectorl select_recnos() const { return _table.select_recnos(); }
    // void drop_table(const string& table_name = "");
    void run();
    void batch(const string& file_name);
    
private:
    vectorstr _names;
    Table _table;
    Table get_sql_command(mmap_ss& ptree, const string& command);
};

#endif //SQL_H