#ifndef VECTOR_UTILITIES_H
#define VECTOR_UTILITIES_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <typeinfo>
using namespace std;

template <typename T>
ostream& operator <<(ostream& outs, const vector<T>& list);

template <typename T>
bool search(const vector<T>& list, const T& findme);

template <typename T>
vector<T>& operator +=(vector<T>& list, const T& addme);

template <typename T>
vector<T>& operator +=(vector<T>& v1, const vector<T>& v2);

template <typename T>
void v_union(vector<T>& v1, vector<T>& v2, vector<T>& result);

template <typename T>
void v_intersection(vector<T>& v1, vector<T>& v2, vector<T>& result);

template <typename T>
bool is_digit(const T& val);

template <typename T>
ostream& operator <<(ostream& outs, const vector<T>& list){
    for (int i = 0; i < list.size(); ++i)
        outs << list[i] << " ";

    return outs;   
}

template <typename T>
bool search(const vector<T>& list, const T& findme){
    for (int i = 0; i < list.size(); ++i){
        if (list[i] == findme)
            return true;
    }
    return false;
}

template <typename T>
vector<T>& operator +=(vector<T>& list, const T& addme){
    list.push_back(addme);
    return list;
}

template <typename T>
vector<T>& operator +=(vector<T>& v1, const vector<T>& v2){
    for (int i = 0; i < v2.size(); ++i)
        v1.push_back(v2[i]);

    return v1;
}

template <typename T>
void v_union(vector<T>& v1, vector<T>& v2, vector<T>& result){
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(result));
}

template <typename T>
void v_intersection(vector<T>& v1, vector<T>& v2, vector<T>& result){
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(result));
}

template <typename T>
bool is_digit(const T& val){
    if (typeid(val) == typeid(string)){
        for (int i = 0; i < val.size(); ++i){
            if (!isdigit(val[i]))
                return false;
        }
        return true;
    }
    return false;
}

#endif //VECTOR_UTILITIES_H