#ifndef LINKED_LIST_FUNCTIONS_H
#define LINKED_LIST_FUNCTIONS_H

#include "../node/node.h"
#include <cassert>
using namespace std;

//Linked List General Functions:
template <typename T>
void _print_list(node<T>* head);

//recursive fun! :)
template <typename T>
void _print_list_backwards(node<T> *head);

//return ptr to key or NULL
template <typename T>
node<T>* _search_list(node<T>* head, T key);

template <typename T>
node<T>* _insert_head(node<T> *&head, T insert_this);

//insert after ptr: insert head if marker null
template <typename T>
node<T>* _insert_after(node<T>*& head, node<T> *after_this, T insert_this);

//insert before ptr: insert head if marker null
template <typename T>
node<T>* _insert_before(node<T>*& head, node<T>* before_this, T insert_this);

//ptr to previous node
template <typename T>
node<T>* _previous_node(node<T>* prev_to_this);

//delete, return item
template <typename T>
T _delete_node(node<T>*& head, node<T>* delete_this);

//duplicate the list...
template <typename T>
node<T>* _copy_list(node<T>* head);

//duplicate the list, return pointer to last node in dest... 
//     use this function in your queue big three 
template <typename T>
node<T> *_copy_list(node<T> *&dest, node<T> *src);

//delete all the nodes
template <typename T>
void _clear_list(node<T>*& head);

//_item at this position
template <typename T>
T& _at(node<T>* head, int pos);

template <typename T>
void _print_list(node<T>* head){
    cout << "Head->";

    for (node<T>* w = head; w != nullptr; w = w->_next)
        cout << *w << " ";

    cout << "|||\n";
}

template <typename T>
void _print_list_backwards(node<T> *head){
    if (head == nullptr){
        cout << "|||";
        return;
    }

    _print_list_backwards(head->_next);
    cout << *head << " ";

    if (head->_prev == nullptr)
        cout << "<-Head\n";  
}

template <typename T>
node<T>* _search_list(node<T>* head, T key){
    for (node<T>* w = head; w != nullptr; w = w->_next){
        if (w->_item == key)
            return w;
    }
    return nullptr;
}

template <typename T>
node<T>* _insert_head(node<T> *&head, T insert_this){
    node<T>* temp = new node<T>(insert_this, head);

    if (head != nullptr)
        head->_prev = temp;

    head = temp;
    return head;
}
                               
template <typename T>
node<T>* _insert_after(node<T>*& head, node<T> *after_this, T insert_this){
    if (head == nullptr)
        return _insert_head(head, insert_this);

    node<T>* temp = new node<T>(insert_this, after_this->_next, after_this);
    node<T>* w = after_this->_next;

    if (w != nullptr)
        w->_prev = temp;

    after_this->_next = temp;
    return temp;  
}

template <typename T>
node<T>* _insert_before(node<T>*& head, node<T>* before_this, T insert_this){
    if (head == nullptr || head == before_this)
        return _insert_head(head, insert_this);

    return _insert_after(head, before_this->_prev, insert_this);      
}

template <typename T>
node<T>* _previous_node(node<T>* prev_to_this){
    return prev_to_this->_prev;
}

template <typename T>
T _delete_node(node<T>*&head, node<T>* delete_this){
    if (head == nullptr)
        return T();

    if (head == delete_this){
        head = delete_this->_next;
        
        if (head != nullptr)
            head->_prev = nullptr;
    }

    else {
        node<T>* temp = delete_this->_prev;
        temp->_next = delete_this->_next;
        node<T>* w = temp->_next;
        
        if (w != nullptr)
            w->_prev = temp;
    }

    T val = delete_this->_item;
    delete delete_this;
    return val;
}

template <typename T>
node<T>* _copy_list(node<T>* head){
    node<T>* temp = nullptr;
    _copy_list(temp, head);
    return temp;
}

template <typename T>
node<T>* _copy_list(node<T>* &dest, node<T> *src){
    _clear_list(dest);
    node<T>* temp = dest;

    for (node<T>* w = src; w != nullptr; w = w->_next)
        temp = _insert_after(dest, temp, w->_item);

    return temp;
}

template <typename T>
void _clear_list(node<T>*& head){
    node<T>* temp;

    for (node<T>* w = head; w != nullptr; w = temp){
        temp = w->_next;
        delete w;
    }

    head = nullptr;
}

template <typename T>
T& _at(node<T>* head, int pos){
    assert(pos >= 0 && "pos is out-of-range!");
    node<T>* w = head;

    for (int i = 0; i < pos; ++i, w = w->_next)
        assert(w != nullptr && "pos is out-of-range!");

    return w->_item;
}

#endif //LINKED_LIST_FUNCTIONS_H