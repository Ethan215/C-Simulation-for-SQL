#ifndef BTREE_ARRAY_FUNCTIONS_H
#define BTREE_ARRAY_FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>
#include "../stl_utils/vector_utilities.h"
using namespace std;

template <class T>
T maximal(const T& a, const T& b);                      // Return the larger of the two items

template <class T>
void swap(T& a, T& b);                                  // Swap the two items

template <class T>
int index_of_maximal(T data[], int n);                  // Return index of the largest item in data

template <class T>
void ordered_insert(T data[], int& n, T entry);         // Insert entry into the sorted array data with length n

template <class T>
int first_ge(const T data[], int n, const T& entry);    // Return the first element in data that is not less than entry

template <class T>
void attach_item(T data[], int& n, const T& entry);     // Append entry to the right of data

template <class T>
void insert_item(T data[], int i, int& n, T entry);     // Insert entry at index i in data

template <class T>
void detach_item(T data[], int& n, T& entry);           // Remove the last element in data and place it in entry

template <class T>
void delete_item(T data[], int i, int& n, T& entry);    // Delete item at index i and place it in entry

template <class T>
void merge(T data1[], int& n1, T data2[], int& n2);     // Append data2 to the right of data1

template <class T>
void split(T data1[], int& n1, T data2[], int& n2);     // Move n/2 elements from the right of data1 and move to data2

template <class T>
void copy_array(T dest[], const T src[], int& dest_size, int src_size); // Copy src[] into dest[]

template <class T>
void print_array(const T data[], int n, int pos = -1);  // Print array data

template <class T>
bool is_gt(const T data[], int n, const T& item);       // item > all data[i]

template <class T>
bool is_le(const T data[], int n, const T& item);       // item <= all data[i]

// Return the larger of the two items
template <class T>
T maximal(const T& a, const T& b){
    if (a > b)
        return a;
    return b;
}

// Swap the two items
template <class T>
void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

// Return index of the largest item in data
template <class T>
int index_of_maximal(T data[], int n){
    int index = 0;

    for (int i = 0; i < n; ++i){
        if (data[i] > data[index])
            index = i;
    }
    return index;
}

// Insert entry into the sorted array data with length n
template <class T>
void ordered_insert(T data[], int& n, T entry){
    int i = first_ge(data, n, entry);
    insert_item(data, i, n, entry);
}

// Return the first element in data that is not less than entry
template <class T>
int first_ge(const T data[], int n, const T& entry){
    for (int i = 0; i < n; ++i){
        if (!(data[i] < entry)) // Use !(<) instead of >=
            return i;           // in case class T does not have == operator
    }
    return n;
}

// Append entry to the right of data
template <class T>
void attach_item(T data[], int& n, const T& entry){
    data[n] = entry;
    ++n;
}

// Insert entry at index i in data
template <class T>
void insert_item(T data[], int i, int& n, T entry){
    for (int j = n; j > i; --j)
        data[j] = data[j-1];

    data[i] = entry;
    ++n;
}

// Remove the last element in data and place it in entry
template <class T>
void detach_item(T data[], int& n, T& entry){
    --n;
    entry = data[n];
}

// Delete item at index i and place it in entry
template <class T>
void delete_item(T data[], int i, int& n, T& entry){
    entry = data[i];
    --n;

    for (int j = i; j < n; ++j)
        data[j] = data[j+1];
}

// Append data2 to the right of data1
template <class T>
void merge(T data1[], int& n1, T data2[], int& n2){
    for (int i = 0; i < n2; ++n1, ++i)
        data1[n1] = data2[i];
    
    n2 = 0;
}

// Move n/2 elements from the right of data1 and move to data2
template <class T>
void split(T data1[], int& n1, T data2[], int& n2){
    n2 = n1/2;
    
    for (int i = n2-1; i >= 0; --i, --n1)
        data2[i] = data1[n1-1];
}

// Copy src[] into dest[]
template <class T>
void copy_array(T dest[], const T src[], int& dest_size, int src_size){
    dest_size = src_size;

    for (int i = 0; i < dest_size; ++i)
        dest[i] = src[i];
}

// Print array data
template <class T>
void print_array(const T data[], int n, int pos){
    cout << "[ ";

    for (int i = pos; i < n; ++i){
        cout << data[i];

        if (i < n-1)
            cout << " ";
    }
    cout << "]" << endl;
}

// item > all data[i]
template <class T>
bool is_gt(const T data[], int n, const T& item){
    return !is_le(data, n, item);
}

// item <= all data[i]
template <class T>
bool is_le(const T data[], int n, const T& item){
    for (int i = 0; i < n; ++i){
        if (item > data[i])
            return false;
    }
    return true;
}

#endif //BTREE_ARRAY_FUNCTIONS_H