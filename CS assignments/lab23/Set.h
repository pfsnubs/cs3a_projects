#pragma once
#ifndef SET_H
#define SET_H
#include <iostream>
using namespace std;

template <class T>
class Set
{
public:
    Set(); // create a set with capacity 10
    Set(int capacity); // create a set with capacity
    Set(const Set<T>& source); // copy constructor
    ~Set();  // destructor

    void insert(T item);  // insert item into the set
    void remove(T item); // remove item from the set
    bool full(); // return true, if set is full
    bool exist(T item) const;  // return true, if item is in the set
    void print(); // print all elements in the set

    void operator +=(const Set<T>& source);
    void operator =(const Set<T>& source);

    int getSize() const; // get size 
    int getCapacity() const; // get capacity 

    // create a new set by adding two sets s1 and s2
    //friend Set<T> operator +(const Set<T>& s1, const Set<T>& s2);

    // Apparently
    friend Set<T> operator +(const Set<T>& s1, const Set<T>& s2) {
        // create a set adding s2 to the back of s1
        int totalCap = s1.getCapacity() + s2.getCapacity();
        int totalSize = s1.getSize() + s2.getSize();
        T* newItems = new T[totalCap];

        // create new heap for set
        Set<T>* newSet = new Set<T>(totalCap);

        // insert s1 first into newSet
        for (int i = 0; i < s1.getSize(); i++) {
            (*newSet).insert(s1.items[i]);
        }

        // insert s2 after into newSet
        for (int i = 0; i < s2.getSize(); i++) {
            (*newSet).insert(s2.items[i]);
        }
        return *newSet;
    };

private:
    T* items;
    int size;       // number of *inserted* items in the array 'items'
    int capacity;   // the *actual* size of items
};




#endif
