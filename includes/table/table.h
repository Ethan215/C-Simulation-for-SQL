#ifndef TABLE_H
#define TABLE_H

#include "typedefs.h"
using namespace std;

class Table{
public:
    Table();
    Table(const string& name);
    Table(const string& name, const vectorstr& field_names);
    // ~Table();   // Clean up files

    void insert_into(const vectorstr& field_values);
    Table select_all(const vectorstr& field_names = vectorstr());
    Table select(const vectorstr& fields, const string& field_name, const string& op, const string& field_value);
    Table select(const vectorstr& fields, const Queue<Token*>& postfix_q);
    Table select(const vectorstr& fields, const vectorstr& input_v);

    friend ostream& operator <<(ostream& outs, const Table& t);

    vectorstr get_fields() const { return _field_names; }
    vectorl select_recnos() const { return _recnos; }

private:
    string _name;           // table's name
    vectorstr _field_names; // vector of field_names (columns) used in SQL
    long _recno;            // last record number
    static long Serial;           // global serial number for smaller tables

    map_sl _map;            // Map field_names (columns) to the row indices of _indices
    vector<mmap_sl> _indices;
    vectorl _recnos;        // vector of record_numbers (indices)
    vectorstr _fields;      // vector of field_names (columns) used in Table

    void set_fields(const vectorstr& field_names);  // Set field_names
    void reindex(const vectorstr& field_values);    // Set field_values.

    vectorl set_operator(const mmap_sl::Iterator& begin, const mmap_sl::Iterator& end);
    vectorl set_recnos(const string& field_name, const string& op, const string& field_value);
    Table vector_to_table();
    vectorl rpn(const Queue<Token*>& postfix_q);
    Queue<Token*> set_infix(const vectorstr& input_v);
};

#endif //TABLE_H