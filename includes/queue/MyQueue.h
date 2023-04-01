#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>
#include <iomanip>
#include "../linked_list_functions/linkedlistfunctionsTemplated.h"
using namespace std;

template <typename T>
class Queue{
public:
    class Iterator{
    public:
        friend class Queue;                     //Give access to list to access _ptr
        Iterator(){ _ptr = NULL; }              //Default CTOR
        Iterator(node<T>* p){ _ptr = p; }       //Point Iterator to where p is pointing to

        bool is_null(){ return _ptr == NULL; }  //True if _ptr is NULL

        //Dereference operator                      
        T& operator *(){
            assert(_ptr != NULL && "_ptr is NULL");
            return _ptr->_item;
        }   

        //True if left != right
        friend bool operator !=(const Iterator &left, const Iterator &right){
            return (left._ptr != right._ptr);
        }

        //True if left == right
        friend bool operator ==(const Iterator &left, const Iterator &right){
            return !(left != right);
        }

        //Member operator: ++it = new_value
        Iterator& operator ++(){
            assert(_ptr != NULL && "_ptr is NULL");
            _ptr = _ptr->_next;
            return *this;
        }                 

        //Friend operator: it++
        friend Iterator operator ++(Iterator &it, int unused){
            assert(it._ptr != NULL && "_ptr is NULL");
            Iterator hold = it;
            it._ptr = it._ptr->_next;
            return hold;
        }

    private:
        node<T>* _ptr;  //Pointer being encapsulated
    };

    Queue();
    Queue(const Queue<T>& copyMe);
    ~Queue();
    Queue<T>& operator =(const Queue<T>& RHS);

    bool empty();
    T front();
    T back();
    void push(T item);
    T pop();

    Iterator begin() const; //Iterator to the head node
    Iterator end() const;   //Iterator to NULL
    void print_pointers();
    int size() const { return _size; }

    template<typename TT>
    friend ostream& operator <<(ostream& outs, const Queue<TT>& printMe);

private:
    node<T>* _front;
    node<T>* _rear;
    int _size;
};

template <typename T>
Queue<T>::Queue(){
    _front = nullptr;
    _rear = nullptr;
    _size = 0;
}

template <typename T>
Queue<T>::Queue(const Queue<T>& copyMe){
    _size = copyMe._size;
    _front = nullptr;
    _rear = _copy_list(_front, copyMe._front);
}

template <typename T>
Queue<T>::~Queue(){
    _clear_list(_front); 
    _rear = nullptr;
}

template <typename T>
Queue<T>& Queue<T>::operator =(const Queue<T>& RHS){
    if (this == &RHS)
        return *this;

    if (_front)
        _clear_list(_front);

    _size = RHS._size;
    _rear = _copy_list(_front, RHS._front);
    return *this;
}

template <typename T>
bool Queue<T>::empty(){
    return _front == nullptr; 
}

template <typename T>
T Queue<T>::front(){
    return _front->_item;
}

template <typename T>
T Queue<T>::back(){
    return _rear->_item;
}

template <typename T>
void Queue<T>::push(T item){
    ++_size;
    _rear = _insert_after(_front, _rear, item);
}

template <typename T>
T Queue<T>::pop(){
    if (_front)
        --_size;
    
    T x = _delete_node(_front, _front);

    if (!_front)
        _rear = _front;

    return x;
}

template <typename T>
typename Queue<T>::Iterator Queue<T>::begin() const{
    return Iterator(_front);  
}

template <typename T>
typename Queue<T>::Iterator Queue<T>::end() const{
    return Iterator(nullptr);  
}

template <typename T>
void Queue<T>::print_pointers(){
    cout << "Head->";

    for (node<T>* w = _front; w != nullptr; w = w->_next)
        cout << "<-" << *(w->_item) << "->" << " "; 
        
    cout << "|||\n";
}

template<typename TT>
ostream& operator <<(ostream& outs, const Queue<TT>& printMe){
    outs << "Queue:";
    _print_list(printMe._front);
    return outs;
}

#endif //MYQUEUE_H