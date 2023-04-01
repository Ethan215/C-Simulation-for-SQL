#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <iomanip>
#include "../linked_list_functions/linkedlistfunctionsTemplated.h"
using namespace std;

template <typename T>
class Stack{
public:
    class Iterator{
    public:
        friend class Stack;                     //Give access to list to access _ptr
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

    Stack();
    Stack(const Stack<T>& copyMe);
    ~Stack();
    Stack<T>& operator =(const Stack<T>& RHS);
    T top();
    bool empty();
    void push(T item);
    T pop();
    template<typename TT>
    friend ostream& operator <<(ostream& outs, const Stack<TT>& printMe);
    Iterator begin() const; //Iterator to the head node
    Iterator end() const;   //Iterator to NULL
    int size() const { return _size; }

private:
    node<T>* _top;
    int _size;
};

template <typename T>
Stack<T>::Stack(){
    _top = nullptr;
    _size = 0;
}

template <typename T>
Stack<T>::Stack(const Stack<T>& copyMe){
    _size = copyMe._size;
    _top = _copy_list(copyMe._top);
}

template <typename T>
Stack<T>::~Stack(){
    _clear_list(_top);        
}

template <typename T>
Stack<T>& Stack<T>::operator =(const Stack<T>& RHS){
    if (this == &RHS)
        return *this;

    if (_top)
        _clear_list(_top);

    _size = RHS._size;
    _top = _copy_list(RHS._top);
    return *this;
}

template <typename T>
T Stack<T>::top(){
    return _top->_item;
}

template <typename T>
bool Stack<T>::empty(){
    return _top == nullptr;      
}

template <typename T>
void Stack<T>::push(T item){
    ++_size;
    _insert_head(_top, item);
}

template <typename T>
T Stack<T>::pop(){
    if (_top)
        --_size;

    return _delete_node(_top, _top);
}

template<typename TT>
ostream& operator <<(ostream& outs, const Stack<TT>& printMe){
    outs << "Stack:";
    _print_list(printMe._top);
    return outs;
}

template <typename T>
typename Stack<T>::Iterator Stack<T>::begin() const{
    return Iterator(_top);    
}

template <typename T>
typename Stack<T>::Iterator Stack<T>::end() const{
    return Iterator(nullptr);    
}

#endif //MYSTACK_H