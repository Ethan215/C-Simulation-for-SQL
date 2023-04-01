#ifndef MULTIMAP_H
#define MULTIMAP_H

#include "bplustree.h"
using namespace std;

template <typename K, typename V>
struct MPair{
    K key;
    vector<V> value_list;

    //--------------------------------------------------------------------------------
    /*  
     *  MPair CTORs: must have these CTORs:
     *  - default CTOR / CTOR with a key and no value: this will create an empty vector
     *  - CTOR with a key and a vector of values (to replace value_list)
     *  - CTOR with a key AND a value: pushes the value into the value_list
     */
    //--------------------------------------------------------------------------------
    MPair(const K& k = K()) : key(k) { }
    MPair(const K& k, const vector<V>& vlist) : key(k), value_list(vlist) { }
    MPair(const K& k, const V& v) : key(k) { value_list.push_back(v); }
    //--------------------------------------------------------------------------------
    
    friend bool operator ==(const MPair<K, V>& lhs, const MPair<K, V>& rhs){ return lhs.key == rhs.key; }
    friend bool operator <(const MPair<K, V>& lhs, const MPair<K, V>& rhs){ return lhs.key < rhs.key; }
    friend bool operator >(const MPair<K, V>& lhs, const MPair<K, V>& rhs){ return lhs.key > rhs.key; }
    friend bool operator <=(const MPair<K, V>& lhs, const MPair<K, V>& rhs){ return lhs.key <= rhs.key; }

    friend MPair<K, V> operator +(const MPair<K, V>& lhs, const MPair<K, V>& rhs){
        MPair<K, V> result(lhs.key, lhs.value_list);

        for (int i = 0; i < rhs.value_list.size(); ++i)
            result.value_list += rhs.value_list[i];

        return result;
    }

    friend ostream& operator <<(ostream& outs, const MPair<K, V>& print_me){
        outs << print_me.key << ": [";

        for (int i = 0; i < print_me.value_list.size(); ++i){
            outs << print_me.value_list[i];

            if (i < print_me.value_list.size()-1)
                outs << " ";
        }
        outs << "]" << endl;
        return outs;
    }
};

template <typename K, typename V>
class MMap{
public:
    typedef BPlusTree<MPair<K, V> > map_base;
    class Iterator{
    public:
        friend class MMap;
        Iterator(typename map_base::Iterator it = typename map_base::Iterator()) : _it(it) { }

        Iterator operator ++(int unused){ 
            Iterator hold = _it++;
            return hold;
        }

        Iterator operator ++(){
            ++_it;
            return *this;
        }

        MPair<K, V> operator *() { return *_it; }
        friend bool operator ==(const Iterator& lhs, const Iterator& rhs) { return lhs._it == rhs._it; }
        friend bool operator !=(const Iterator& lhs, const Iterator& rhs) { return lhs._it != rhs._it; }

    private:
        typename map_base::Iterator _it;
    };

    MMap(bool dups = false) : mmap(map_base(dups)) { }

    // Iterators
    Iterator begin() { return Iterator(mmap.begin()); }
    Iterator end() { return Iterator(mmap.end()); }
    Iterator lower_bound(const K& key) { return Iterator(mmap.lower_bound(key)); }
    Iterator upper_bound(const K& key) { return Iterator(mmap.upper_bound(key)); }

    // Capacity
    int size() const { return mmap.size(); }
    bool empty() const { return mmap.empty(); }
    bool is_valid() { return mmap.is_valid(); }

    // Element Access
    vector<V>& operator [](const K& key);
    vector<V>& at(const K& key);
    const vector<V>& operator [](const K& key) const;
    const vector<V>& at(const K& key) const;

    // Modifiers
    void insert(const K& k, const V& v) { mmap.insert(MPair<K, V>(k, v)); }
    void erase(const K& key) { mmap.remove(key); }
    void clear() { mmap.clear_tree(); }

    // Operations:
    vector<V>& get(const K& key) { return mmap.get(key).value_list; }
    Iterator find(const K& key) { return Iterator(mmap.find(key)); }
    bool contains(const K& key) const { return mmap.contains(key); }
    int count(const K& key) { return mmap.get_existing(key).value_list.size(); }

    friend ostream& operator <<(ostream& outs, const MMap<K, V>& print_me){
        outs << print_me.mmap << endl;
        return outs;
    }

    // Function to print mmap as a table
    void print_lookup(){
        for (MMap<K, V>::Iterator it = begin(); it != end(); ++it)
            cout << setw(10) << (*it).key << " :" << setw(5) << " " << (*it).value_list << endl;
    }

private:
    BPlusTree<MPair<K, V> > mmap;
};

template <typename K, typename V>
vector<V>& MMap<K, V>::operator [](const K& key){
    return at(key);    
}

template <typename K, typename V>
vector<V>& MMap<K, V>::at(const K& key){
    return mmap.get(key).value_list;
}

template <typename K, typename V>
const vector<V>& MMap<K, V>::operator [](const K& key) const{
    return at(key);
}

template <typename K, typename V>
const vector<V>& MMap<K, V>::at(const K& key) const{
    return mmap.get(key).value_list;
}

#endif //MULTIMAP_H