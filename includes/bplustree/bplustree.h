#ifndef BPLUSTREE_H
#define BPLUSTREE_H
    
#include "btree_array_funcs.h"
using namespace std;

template <class T>
class BPlusTree{
public:
    class Iterator{
    public:
        friend class BPlusTree;
        Iterator(BPlusTree<T>* _it = nullptr, int _key_ptr = 0): it(_it), key_ptr(_key_ptr) { }

        T operator *(){
            assert(it != nullptr);
            return it->data[key_ptr];
        }   

        Iterator operator ++(int un_used){
            assert(it != nullptr);
            Iterator hold = it;

            if (++key_ptr >= it->data_count){
                key_ptr = 0;
                it = it->next;
            }
            return hold;
        }

        Iterator operator ++(){
            assert(it != nullptr);

            if (++key_ptr >= it->data_count){
                key_ptr = 0;
                it = it->next;
            }
            return *this;
        }                 

        friend bool operator ==(const Iterator& lhs, const Iterator& rhs) { return (lhs.it == rhs.it && lhs.key_ptr == rhs.key_ptr); }
        friend bool operator !=(const Iterator& lhs, const Iterator& rhs) { return !(lhs == rhs); }
        bool is_null() { return !it; }
        void info() { cout << endl << "Iterator info: " << endl << "it: " << *it << endl << "key_ptr: " << key_ptr << endl; }

        void print_Iterator(){
            if (it){
                cout << "Iterator: ";
                print_array(it->data, it->data_count, key_ptr);
            }
            else
                cout << "Iterator: nullptr, key_ptr: " << key_ptr << endl;
        }

    private:
        BPlusTree<T>* it;
        int key_ptr;
    };

    BPlusTree(bool dups = false) : dups_ok(dups), data_count(0), child_count(0), next(nullptr) { };
    BPlusTree(T *a, int size, bool dups = false);

    // Big 3
    BPlusTree(const BPlusTree<T>& other);
    ~BPlusTree();
    BPlusTree<T>& operator =(const BPlusTree<T>& RHS);

    void insert(const T& entry);         // Insert entry into the tree
    void remove(const T& entry);         // Remove entry from the tree
    void clear_tree();                   // Clear this object (delete all nodes etc.)
    void copy_tree(const BPlusTree<T>& other); // Copy other into this object
    void copy_tree(const BPlusTree<T>& other, BPlusTree<T>*& last_node);

    bool contains(const T& entry) const; // True if entry can be found
    T& get(const T& entry);              // Return a reference to entry
    const T& get(const T& entry) const;  // Return a reference to entry
    T& get_existing(const T& entry);     // Return a reference to entry
    Iterator find(const T& key);         // Return an iterator to this key. NULL if not there.
    Iterator lower_bound(const T& key);  // Return first that goes NOT BEFORE key entry or next if does not exist: >= entry
    Iterator upper_bound(const T& key);  // Return first that goes AFTER key exist or not, the next entry > entry

    int size() const;                    // Count the number of elements
    bool empty() const;                  // True if the tree is empty
    bool is_valid();
    string in_order();
    string pre_order();
    string post_order();

    void print_tree(int level = 0, ostream &outs = cout) const;

    friend ostream& operator <<(ostream& outs, const BPlusTree<T>& print_me){
        print_me.print_tree(0, outs);
        return outs;
    }

    Iterator begin() { return Iterator(get_smallest_node()); }
    Iterator end() { return Iterator(); }

    ostream& list_keys(Iterator from = nullptr, Iterator to = nullptr){
        if (!from) from = begin();
        if (!to) to = end();

        for (Iterator it = from; it != to; ++it)
            cout << *it << " ";

        return cout;
    }

private:
    static const int MINIMUM = 1;
    static const int MAXIMUM = 2 * MINIMUM;

    bool dups_ok;                       // True if duplicate keys are allowed
    int data_count;                     // Number of data elements
    int child_count;                    // Number of children
    T data[MAXIMUM + 1];                // Keys
    BPlusTree* subset[MAXIMUM + 2];     // Subtrees
    BPlusTree* next;

    bool is_leaf() const { return child_count == 0; } // True if this is a leaf node

    T* find_ptr(const T& entry);        // Return a pointer to this key. NULL if not there.

    // Insert element functions
    void loose_insert(const T& entry);  // Allow MAXIMUM+1 data elements in the root
    void fix_excess(int i);             // Fix excess in child i

    // Remove element functions:
    void loose_remove(const T& entry);  // Allow MINIMUM-1 data elements in the root
    BPlusTree<T>* fix_shortage(int i);  // Fix shortage in child i and return the smallest key in this subtree
    BPlusTree<T>* get_smallest_node();

    void get_smallest(T& entry);        // entry := leftmost leaf
    void get_biggest(T& entry);         // entry := rightmost leaf
    void remove_biggest(T& entry);      // Remove the biggest child of tree->entry
    void transfer_left(int i);          // Transfer one element LEFT from child i
    void transfer_right(int i);         // Transfer one element RIGHT from child i
    BPlusTree<T>* merge_with_next_subset(int i); // Merge subset i with  i+1
};

template <class T>
BPlusTree<T>::BPlusTree(T *a, int size, bool dups) : dups_ok(dups), data_count(0), child_count(0), next(nullptr){
    for (int i = 0; i < size; ++i)
        insert(*(a+i));
}

// Big 3
template <class T>
BPlusTree<T>::BPlusTree(const BPlusTree<T>& other){
    copy_tree(other);
}

template <class T>
BPlusTree<T>::~BPlusTree(){
    clear_tree();
}

template <class T>
BPlusTree<T>& BPlusTree<T>::operator =(const BPlusTree<T>& RHS){
    if (this == &RHS)
        return *this;
        
    clear_tree();
    copy_tree(RHS);
    return *this;
}

// Insert entry into the tree
template <class T>
void BPlusTree<T>::insert(const T& entry){
    loose_insert(entry);

    if (data_count > MAXIMUM){
        BPlusTree<T>* temp = new BPlusTree<T>(dups_ok);
        copy_array(temp->data, data, temp->data_count, data_count);
        copy_array(temp->subset, subset, temp->child_count, child_count);
        data_count = 0;
        child_count = 1;
        subset[0] = temp;
        fix_excess(0);
    }
}

// Remove entry from the tree
template <class T>
void BPlusTree<T>::remove(const T& entry){
    loose_remove(entry);

    if (data_count == 0 && child_count == 1){
        BPlusTree<T>* temp = subset[0];
        copy_array(data, temp->data, data_count, temp->data_count);
        copy_array(subset, temp->subset, child_count, temp->child_count);
        temp->data_count = 0;
        temp->child_count = 0;
        delete temp; // This will trigger the destructor
    }
}

// Clear this object (delete all nodes etc.)
template <class T>
void BPlusTree<T>::clear_tree(){
    for (int i = child_count-1; i >= 0; --i, --child_count){
        subset[i]->clear_tree();
        delete subset[i];
    }
    data_count = 0;
    next = nullptr;
}

// Copy other into this object
template <class T>
void BPlusTree<T>::copy_tree(const BPlusTree<T>& other){
    BPlusTree<T>* last_node = nullptr;
    copy_tree(other, last_node);
}

template <class T>
void BPlusTree<T>::copy_tree(const BPlusTree<T>& other, BPlusTree<T>*& last_node){
    dups_ok = other.dups_ok;
    child_count = other.child_count;
    copy_array(data, other.data, data_count, other.data_count);
    next = nullptr;

    for (int i = 0; i < other.child_count; ++i){
        subset[i] = new BPlusTree<T>();   
        subset[i]->copy_tree(*other.subset[i], last_node);
    }

    if (other.is_leaf()){
        if (last_node)
            last_node->next = this;

        last_node = this;
    }
}

// True if entry can be found
template <class T>
bool BPlusTree<T>::contains(const T& entry) const{
    int i = first_ge(data, data_count, entry);

    if (is_leaf()){
        if (i < data_count && !(entry < data[i]))
            return true;

        return false;
    }

    else {
        if (i < data_count && !(entry < data[i]))
            return subset[i+1]->contains(entry);

        return subset[i]->contains(entry);
    }
}

// Return a reference to entry
template <class T>
T& BPlusTree<T>::get(const T& entry){
    if (!contains(entry))
        insert(entry);

    return get_existing(entry);
}

// Return a reference to entry
template <class T>
const T& BPlusTree<T>::get(const T& entry) const{
    if (!contains(entry))
        assert(entry != T() && "What the ...?");

    return get_existing(entry);
}

// Return a reference to entry
template <class T>
T& BPlusTree<T>::get_existing(const T& entry){
    return *find_ptr(entry);
}

// Return an iterator to this key. NULL if not there.
template <class T>
typename BPlusTree<T>::Iterator BPlusTree<T>::find(const T& key){
    int i = first_ge(data, data_count, key);
    bool found = i < data_count && !(key < data[i]);

    if (is_leaf()){
        if (found)
            return Iterator(this, i);

        return Iterator();
    }

    else {
        if (found)
            return subset[i+1]->find(key);

        return subset[i]->find(key);
    }
}

// Return first that goes NOT BEFORE key entry or next if does not exist: >= entry
template <class T>
typename BPlusTree<T>::Iterator BPlusTree<T>::lower_bound(const T& key){
    int i = first_ge(data, data_count, key);

    if (is_leaf()){
        Iterator it = begin();

        for (; it != end(); ++it){
            if (!(*it < key))
                break;
        }
        return it;
    }

    else {
        if (i < data_count && !(key < data[i]))
            return subset[i+1]->lower_bound(key);

        return subset[i]->lower_bound(key);
    }     
}

// Return first that goes AFTER key exist or not, the next entry > entry
template <class T>
typename BPlusTree<T>::Iterator BPlusTree<T>::upper_bound(const T& key){
    int i = first_ge(data, data_count, key);

    if (is_leaf()){
        Iterator it = begin();

        for (; it != end(); ++it){
            if (!(*it <= key))
                break;
        }
        return it;
    }

    else {
        if (i < data_count && !(key < data[i]))
            return subset[i+1]->upper_bound(key);

        return subset[i]->upper_bound(key);
    }   
}

// Count the number of elements
template <class T>
int BPlusTree<T>::size() const{
    int count = data_count;

    for (int i = 0; i < child_count; ++i)
        count += subset[i]->size();

    return count;
}

// True if the tree is empty
template <class T>
bool BPlusTree<T>::empty() const{
    return data_count == 0 && child_count == 0;   
}

template <class T>
bool BPlusTree<T>::is_valid(){
    if (data_count > MAXIMUM || child_count > MAXIMUM+1 || (!is_leaf() && (data_count < MINIMUM || child_count != data_count+1)))
        return false;

    for (int i = 0; i <= data_count; ++i){
        if (i < data_count-1 && data[i] > data[i+1])
            return false;

        if (!is_leaf()){
            if (i < data_count && (data[i] < subset[i]->data[subset[i]->data_count-1] || data[i] > subset[i+1]->data[0]))
                return false;

            return subset[i]->is_valid();
        }
    }
    return true;
}

template <class T>
string BPlusTree<T>::in_order(){
    string str = "";

    for (int i = 0; i <= data_count; ++i){
        if (!is_leaf())
            str += subset[i]->in_order();

        if (i < data_count)
            str += to_string(data[i]) + "|";
    }
    return str;
}

template <class T>
string BPlusTree<T>::pre_order(){
    string str = "";

    for (int i = 0; i <= data_count; ++i){
        if (i < data_count)
            str += to_string(data[i]) + "|";
  
        if (!is_leaf())
            str += subset[i]->pre_order();
    }
    return str;
}

template <class T>
string BPlusTree<T>::post_order(){
    string str = "";
    
    for (int i = 0; i <= data_count; ++i){
        if (!is_leaf())
            str += subset[i]->post_order(); 

        if (i-1 >= 0)
            str += to_string(data[i-1]) + "|";
    }
    return str;
}

template <class T>
void BPlusTree<T>::print_tree(int level, ostream &outs) const{
    for (int i = data_count; i >= 0; --i){
        if (i < data_count){
            if (i == data_count-1){
                if (next)
                    outs << string(4*level,' ') << "^" << endl;

                outs << string(4*level,' ') << "\u23B4" << endl; // ⎴
            }

            outs << string(4*level,' ') << data[i] << endl;

            if (i == 0)
                outs << string(4*level,' ') << "\u23B5" << endl; // ⎵
        }

        if (!is_leaf())
            subset[i]->print_tree(level+1, outs);
    }
}

// Return a pointer to this key. NULL if not there.
template <class T>
T* BPlusTree<T>::find_ptr(const T& entry){
    int i = first_ge(data, data_count, entry);
    bool found = i < data_count && !(entry < data[i]);

    if (is_leaf()){
        if (found)
            return &data[i];

        return nullptr;
    }

    else {
        if (found)
            return subset[i+1]->find_ptr(entry);

        return subset[i]->find_ptr(entry);
    }
}

// Allow MAXIMUM+1 data elements in the root
template <class T>
void BPlusTree<T>::loose_insert(const T& entry){
    int i = first_ge(data, data_count, entry);
    bool found = i < data_count && !(entry < data[i]);

    if (is_leaf()){
        if (found){
            if (dups_ok) // Update data[i] for map and mmap
                data[i] = data[i] + entry;

            else
                data[i] = entry;
        }

        else
            insert_item(data, i, data_count, entry);
    }

    else {
        if (found){
            subset[i+1]->loose_insert(entry);

            if (subset[i+1]->data_count > MAXIMUM)
                fix_excess(i+1);  
        }

        else {
            subset[i]->loose_insert(entry);
  
            if (subset[i]->data_count > MAXIMUM)
                fix_excess(i);   
        }
    }
}

// Fix excess in child i
template <class T>
void BPlusTree<T>::fix_excess(int i){
    T entry;
    BPlusTree<T>* temp = new BPlusTree<T>(dups_ok);
    split(subset[i]->data, subset[i]->data_count, temp->data, temp->data_count);
    split(subset[i]->subset, subset[i]->child_count, temp->subset, temp->child_count);
    detach_item(subset[i]->data, subset[i]->data_count, entry);
    insert_item(data, i, data_count, entry);
    insert_item(subset, i+1, child_count, temp);

    if (subset[i]->is_leaf()){
        insert_item(subset[i+1]->data, 0, subset[i+1]->data_count, entry);
        subset[i+1]->next = subset[i]->next;   
        subset[i]->next = subset[i+1];
    }
}

// Allow MINIMUM-1 data elements in the root
template <class T>
void BPlusTree<T>::loose_remove(const T& entry){
    int i = first_ge(data, data_count, entry);
    bool found = i < data_count && !(entry < data[i]);

    if (is_leaf()){
        if (found){
            T val;  
            delete_item(data, i, data_count, val);
        }
    }

    else {
        if (found){
            subset[i+1]->loose_remove(entry);

            if (subset[i+1]->data_count < MINIMUM){
                BPlusTree<T>* temp = fix_shortage(i+1);
                int j = first_ge(data, data_count, entry);
                int k = first_ge(temp->data, temp->data_count, entry);

                if (j+1 < child_count && j < data_count && !(entry < data[j]))
                    subset[j+1]->get_smallest(data[j]);

                else if (k+1 < temp->child_count && k < temp->data_count && !(entry < temp->data[k]))
                    temp->subset[k+1]->get_smallest(temp->data[k]);
            }                             
  
            else if (i < data_count)
                subset[i+1]->get_smallest(data[i]);
        }

        else {
            subset[i]->loose_remove(entry);   

            if (subset[i]->data_count < MINIMUM)
                fix_shortage(i);
        }
    }
}

// Fix shortage in child i and return the smallest key in this subtree
template <class T>
BPlusTree<T>* BPlusTree<T>::fix_shortage(int i){
    if (i+1 < child_count && subset[i+1]->data_count > MINIMUM)
        transfer_left(i); 

    else if (i-1 >= 0 && subset[i-1]->data_count > MINIMUM)
        transfer_right(i);

    else if (i-1 >= 0 && subset[i-1]->data_count <= MINIMUM)
        return merge_with_next_subset(i-1);

    else if (i+1 < child_count && subset[i+1]->data_count <= MINIMUM)
        return merge_with_next_subset(i);

    else
       cout << "How did I get here?" << endl; // Simplify this later

    return subset[i];
}

template <class T>
BPlusTree<T>* BPlusTree<T>::get_smallest_node(){
    if (!is_leaf())
        return subset[0]->get_smallest_node();
    
    return this;
}

// entry := leftmost leaf
template <class T>
void BPlusTree<T>::get_smallest(T& entry){
    if (!is_leaf())
        subset[0]->get_smallest(entry);
    
    else
        entry = data[0];
}

// entry := rightmost leaf
template <class T>
void BPlusTree<T>::get_biggest(T& entry){
    if (!is_leaf())
        subset[child_count-1]->get_biggest(entry);
    
    else
        entry = data[data_count-1];
}

// Remove the biggest child of tree->entry
template <class T>
void BPlusTree<T>::remove_biggest(T& entry){
    if (!is_leaf()){
        subset[child_count-1]->remove_biggest(entry);
        
        if (subset[child_count-1]->data_count < MINIMUM)
            fix_shortage(child_count-1);
    }

    else 
        detach_item(data, data_count, entry);    
}

// Transfer one element LEFT from child i
template <class T>
void BPlusTree<T>::transfer_left(int i){
    if (!subset[i+1]->is_leaf()){
        attach_item(subset[i]->data, subset[i]->data_count, data[i]);
        delete_item(subset[i+1]->data, 0, subset[i+1]->data_count, data[i]);
        BPlusTree<T>* temp = nullptr;
        delete_item(subset[i+1]->subset, 0, subset[i+1]->child_count, temp);
        attach_item(subset[i]->subset, subset[i]->child_count, temp);
    }

    else {
        T entry;
        delete_item(subset[i+1]->data, 0, subset[i+1]->data_count, entry); 
        attach_item(subset[i]->data, subset[i]->data_count, entry);
        data[i] = subset[i+1]->data[0];
    }
}

// Transfer one element RIGHT from child i
template <class T>
void BPlusTree<T>::transfer_right(int i){
    if (!subset[i-1]->is_leaf()){
        insert_item(subset[i]->data, 0, subset[i]->data_count, data[i-1]);
        detach_item(subset[i-1]->data, subset[i-1]->data_count, data[i-1]);
        BPlusTree<T>* temp = nullptr;
        detach_item(subset[i-1]->subset, subset[i-1]->child_count, temp);
        insert_item(subset[i]->subset, 0, subset[i]->child_count, temp);
    }

    else {
        detach_item(subset[i-1]->data, subset[i-1]->data_count, data[i-1]);
        insert_item(subset[i]->data, 0, subset[i]->data_count, data[i-1]);
    }   

}

// Merge subset i with i+1
template <class T>
BPlusTree<T>* BPlusTree<T>::merge_with_next_subset(int i){
    T entry;
    delete_item(data, i, data_count, entry);

    if (!subset[i]->is_leaf())
        attach_item(subset[i]->data, subset[i]->data_count, entry);

    merge(subset[i]->data, subset[i]->data_count, subset[i+1]->data, subset[i+1]->data_count);
    merge(subset[i]->subset, subset[i]->child_count, subset[i+1]->subset, subset[i+1]->child_count);
    BPlusTree<T>* temp = nullptr; 
    delete_item(subset, i+1, child_count, temp);

    if (subset[i]->is_leaf())
        subset[i]->next = temp->next;

    delete temp;
    return subset[i];
}

#endif //BPLUSTREE_H