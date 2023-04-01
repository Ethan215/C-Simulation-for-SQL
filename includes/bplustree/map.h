#ifndef MAP_H
#define MAP_H

#include "bplustree.h"
using namespace std;

template <typename K, typename V>
struct Pair{
    K key;
    V value;

    Pair(const K& k = K(), const V& v = V()) : key(k), value(v) { }
    friend bool operator ==(const Pair<K, V>& lhs, const Pair<K, V>& rhs){ return lhs.key == rhs.key; } 
    friend bool operator <(const Pair<K, V>& lhs, const Pair<K, V>& rhs){ return lhs.key < rhs.key; }
    friend bool operator >(const Pair<K, V>& lhs, const Pair<K, V>& rhs){ return lhs.key > rhs.key; }
    friend bool operator <=(const Pair<K, V>& lhs, const Pair<K, V>& rhs){ return lhs.key <= rhs.key; }
    friend Pair<K, V> operator +(const Pair<K, V>& lhs, const Pair<K, V>& rhs){ return rhs; }

    friend ostream& operator <<(ostream& outs, const Pair<K, V>& print_me){
        outs << print_me.key << ":" << print_me.value;
        return outs;
    }
};

template <typename K, typename V>
class Map{
public:
    typedef BPlusTree<Pair<K, V> > map_base;
    class Iterator{
    public:
        friend class Map;
        Iterator(typename map_base::Iterator it = typename map_base::Iterator()) : _it(it) { }

        Iterator operator ++(int unused){ 
            Iterator hold = _it++;
            return hold;
        }

        Iterator operator ++(){
            ++_it;
            return *this;
        }

        Pair<K, V> operator *() { return *_it; }
        friend bool operator ==(const Iterator& lhs, const Iterator& rhs) { return lhs._it == rhs._it; }
        friend bool operator !=(const Iterator& lhs, const Iterator& rhs) { return lhs._it != rhs._it; }

    private:
        typename map_base::Iterator _it;
    };

    Map(bool dups = false) : key_count(0), map(map_base(dups)) { }

    // Iterators
    Iterator begin() { return Iterator(map.begin()); }
    Iterator end() { return Iterator(map.end()); }
    Iterator lower_bound(const K& key) { return Iterator(map.lower_bound(key)); }
    Iterator upper_bound(const K& key) { return Iterator(map.upper_bound(key)); }

    // Capacity
    int size() const { return map.size(); }
    bool empty() const { return map.empty(); }
    bool is_valid() { return map.is_valid(); }

    // Element access
    V& operator [](const K& key);
    V& at(const K& key);
    const V& at(const K& key) const;

    // Modifiers
    void insert(const K& k, const V& v) { map.insert(Pair<K, V>(k, v)); }
    void erase(const K& key) { map.remove(key); }
    void clear() { map.clear_tree(); }

    // Operations:
    V get(const K& key) { return map.get(key).value; }
    Iterator find(const K& key) { return Iterator(map.find(key)); }
    bool contains(const Pair<K, V>& target) const { return map.contains(target); }
    int count(const K& key) { return size(); }

    friend ostream& operator <<(ostream& outs, const Map<K, V>& print_me){
        outs << print_me.map << endl;
        return outs;
    }

private:
    int key_count; // Not needed?
    BPlusTree<Pair<K, V> > map;
};

template <typename K, typename V>
V& Map<K, V>::operator [](const K& key){
    return at(key);
}

template <typename K, typename V>
V& Map<K, V>::at(const K& key){
    return map.get(key).value;
}

template <typename K, typename V>
const V& Map<K, V>::at(const K& key) const{
    return map.get(key).value;
}

#endif //MAP_H