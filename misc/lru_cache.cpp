/*
Design and implement a data structure for LRU (Least Recently Used) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.
The LRU Cache will be initialized with an integer corresponding to its capacity. Capacity indicates the maximum number of unique keys it can hold at a time.

Definition of “least recently used” : An access to an item is defined as a get or a set operation of the item. “Least recently used” item is the one with the oldest access time.

Example :

Input : 
         capacity = 2
         set(1, 10)
         set(5, 12)
         get(5)        returns 12
         get(1)        returns 10
         get(10)       returns -1
         set(6, 14)    this pushes out key = 5 as LRU is full. 
         get(5)        returns -1 

*/

#include <bits/stdc++.h>
 
list<pair<int, int>> ll;
 
unordered_map<int, list<pair<int, int>>::iterator> hh;
 
int cap;
 
void print(list<pair<int, int>> ll) { 
    for(auto it = ll.begin(); it != ll.end(); ++it) 
        cout << it->first << ":" << it->second << endl;
}
 
LRUCache::LRUCache(int capacity) {
    cap = capacity;
    hh.clear();
    ll.clear();
}
 
int LRUCache::get(int key) {
    if(hh.find(key) == hh.end()) {
        return -1;
    }
    list<pair<int, int>>::iterator it = hh[key];
    pair<int, int> p = make_pair(it->first, it->second);
    ll.erase(it);
    hh.erase(key);
    ll.push_front(p);
    hh[key] = ll.begin();
    return p.second;
}
 
void LRUCache::set(int key, int value) {
    if(cap == ll.size()) {
        if(hh.find(key) != hh.end()) {
            list<pair<int, int>>::iterator it = hh[key];
            ll.erase(it);
            hh.erase(key);
        } else {
            pair<int, int> p = ll.back();
            hh.erase(p.first);
            ll.pop_back();
        }
    }
    if(hh.find(key) != hh.end()) {
        list<pair<int, int>>::iterator it = hh[key];
        ll.erase(it);
        hh.erase(key);
    }
    ll.push_front(make_pair(key, value));
    hh[key] = ll.begin();
}