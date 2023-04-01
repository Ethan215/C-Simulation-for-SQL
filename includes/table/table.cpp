#include "table.h"
using namespace std;

long Table::Serial = 0;

Table::Table(){
    _name = "";
    _recno = -1;
}

Table::Table(const string& name){
    _name = name;
    _recno = -1;

    fstream f;
    FileRecord r;
    open_fileRW(f, (_name + "_fields").c_str());
    r.read(f, 0);
    set_fields(r.get_record());
    f.close();

    open_fileRW(f, (_name + ".tbl").c_str());

    for (long i = 0, bytes = r.read(f, i); bytes > 0; bytes = r.read(f, ++i)){
        _recnos += ++_recno;
        reindex(r.get_record());
    }
    f.close();
}

// Create a new table. What if the table already exists? Reset?
Table::Table(const string& name, const vectorstr& field_names){
    _name = name;
    _recno = -1;

    set_fields(field_names);

    fstream f;
    FileRecord r(field_names);
    open_fileW(f, (_name + "_fields").c_str());
    r.write(f);
    f.close();

    open_fileW(f, (_name + ".tbl").c_str());
    f.close();
}

// Table::~Table(){
//     for (int i = 1; i <= Serial; ++i){
//         string str = "_select_table_" + to_string(i);
//         remove((str + ".tbl").c_str());
//         remove((str + "_fields").c_str());
//     }
// }

void Table::insert_into(const vectorstr& field_values){
    fstream f;
    FileRecord r(field_values);
    open_fileRW(f, (_name + ".tbl").c_str());
    _recno = r.write(f);
    _recnos += _recno;
    reindex(field_values);
    f.close();  
}

Table Table::select_all(const vectorstr& field_names){
    if (field_names.size() == 0)
        return *this;
    
    _fields = field_names;
    return vector_to_table();
}

Table Table::select(const vectorstr& fields, const string& field_name, const string& op, const string& field_value){
    _fields = fields;
    _recnos = set_recnos(field_name, op, field_value);
    return vector_to_table();
}

Table Table::select(const vectorstr& fields, const Queue<Token*>& postfix_q){
    _fields = fields;
    _recnos = rpn(postfix_q);
    return vector_to_table();
}

Table Table::select(const vectorstr& fields, const vectorstr& input_v){
    Queue<Token*> infix = set_infix(input_v);
    ShuntingYard sy(infix);
    Table temp = select(fields, sy.postfix());

    for (Queue<Token*>::Iterator it = infix.begin(); it != infix.end(); ++it)
        delete *it;

    return temp;
}

ostream& operator <<(ostream& outs, const Table& t){
    fstream f;
    FileRecord r;
    open_fileRW(f, (t._name + "_fields").c_str());
    r.read(f, 0);

    if (t._name != "")
        cout << "Table name: " << t._name << ", records: " << t._recno+1 << endl << setw(25) << "record" <<  r << endl;
        
    f.close();

    open_fileRW(f, (t._name + ".tbl").c_str());

    for (long i = 0, bytes = r.read(f, i); bytes > 0; bytes = r.read(f, ++i))
        cout << setw(25) << i << r << endl;

    f.close();
    return outs;
}

void Table::set_fields(const vectorstr& field_names){
    for (int i = 0; i < field_names.size(); ++i){
        _field_names += field_names[i];
        _map[field_names[i]] += i;
        _indices += mmap_sl(true);
    }
}

void Table::reindex(const vectorstr& field_values){
    for (int i = 0; i < field_values.size(); ++i)
        _indices[i][field_values[i]] += _recno;
}

vectorl Table::set_operator(const mmap_sl::Iterator& begin, const mmap_sl::Iterator& end){
    vectorl result;

    for (mmap_sl::Iterator it = begin; it != end; ++it)
        result += (*it).value_list; // typeof(*it) is MPair<string, long>

    return result;
}

vectorl Table::set_recnos(const string& field_name, const string& op, const string& field_value){
    mmap_sl index = _indices[_map[field_name]];

    if (op == "=")
        return index[field_value];

    else if (op == "<")
        return set_operator(index.begin(), index.lower_bound(field_value));

    else if (op == ">")
        return set_operator(index.upper_bound(field_value), index.end());

    else if (op == "<=")
        return set_operator(index.begin(), index.upper_bound(field_value));

    else if (op == ">=")
        return set_operator(index.lower_bound(field_value), index.end());
    
    else {
        cout << "How did I get here?" << endl;
        return vectorl();
    }
}

Table Table::vector_to_table(){
    fstream f;
    FileRecord r;
    Table temp("_select_table_" + to_string(++Serial), _fields);
    open_fileRW(f, (_name + ".tbl").c_str());

    for (int i = 0; i < _recnos.size(); ++i){
        r.read(f, _recnos[i]);
        vectorstr v = r.get_record();
        vectorstr list; 

        for (int j = 0; j < _fields.size(); ++j)
            list += v[_map[_fields[j]]]; // Kinda tricky

        temp.insert_into(list);
    }
    f.close();
    return temp;    
}

vectorl Table::rpn(const Queue<Token*>& postfix_q){
    Queue<Token*> queue = postfix_q;
    Stack<Token*> stack;
    Stack<vectorl> results;

    while (queue.size() != 0){
        Token* w = queue.pop();

        switch (w->TypeOf()){
            case TOKENSTR:
                stack.push(w);
                break;

            case RELATIONAL: {
                string temp = stack.pop()->Get();
                results.push(set_recnos(stack.pop()->Get(), w->Get(), temp));
                break;  
            }

            case LOGICAL: {
                vectorl v1 = results.pop();
                vectorl v2 = results.pop();
                vectorl temp;
                
                if (w->Get() == "and")
                    v_intersection(v1, v2, temp);

                else // or
                    v_union(v1, v2, temp);      

                results.push(temp);
                break;
            }
            default:
                break;
        }
    }
    return results.pop();
}

Queue<Token*> Table::set_infix(const vectorstr& input_v){
    Queue<Token*> infix;
    
    for (int i = 0; i < input_v.size(); ++i){
        string str = input_v[i];

        if (str == "=" || str == "<" || str == ">" || str == "<=" || str == ">=")
            infix.push(new Relational(str));

        else if (str == "and" || str == "or")
            infix.push(new Logical(str));
        
        else if (str == "(")
            infix.push(new LParen());

        else if (str == ")")
            infix.push(new RParen());    

        else
            infix.push(new TokenStr(str));   
    }
    return infix;
}