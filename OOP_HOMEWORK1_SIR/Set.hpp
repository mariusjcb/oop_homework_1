//
//  Set.hpp
//  OOP_HOMEWORK1_SIR
//
//  Created by Marius Ilie on 03/03/2017.
//  Copyright © 2017 Marius Ilie @ FMI 143. All rights reserved.
//

#ifndef Set_hpp
#define Set_hpp

#include "Observer.cpp"
#include <iostream>

template <typename T>
class SetObserver: public Observer
{
public:
    SetObserver(): Observer(){};
    void update();
};

template <typename T>
class Set: public Observable {
    int _length = 0;
    T* values = new T[_length];
    
    int compareElements (const void*, const void*);
    void sortSet();
    bool elementExists(T);
    void removeDuplicates();
    
    friend class SetObserver<T>;
    
public:
    int getLength();
    void setLength(int);
    
    T* getValues();
    void setValues(T*);
    
    void push(const T);
    T&& pop();
    
    Set<T>& operator+= (const T); // push
    void operator-= (T&&); // pop
    void operator= (T&&); // pop
    
    Set<T>& operator= (const T*); // Set = [1,2,3,5,1,3] -> Set.values == [1,2,3,5]
    
    T operator[] (const int); // Access values element by index
    Set<T>& operator+ (const Set<T>&); // Reunion
    bool operator< (const Set<T>&); // Cmp length
    bool operator> (const Set<T>&); // Cmp length
    
    void insert(T); // insert last element -> push
    void insert(T, int); // insert element values[index]=value
    void remove(T); // remove element by value
    void remove(int); // remove element by index
    int find(T); // find element by value and return index
    T find(int); // find element by index and return value
    
    bool isEmpty();
    
    T* getEvenNumbers();
    T* getOddNumbers();
    
    Set();
    Set(int); // Set(length)
    Set(const Set<T>&); // Set(copy_ref)
    
    ~Set();
};

#endif /* Set_hpp */
