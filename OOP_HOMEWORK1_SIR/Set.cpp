//
//  Set.cpp
//  OOP_HOMEWORK1_SIR
//
//  Created by Marius Ilie on 03/03/2017.
//  Copyright © 2017 Marius Ilie @ FMI 143. All rights reserved.
//

#include "Set.hpp"
#include <stdlib.h>
#include <string.h>

#pragma mark - SetObserver
template <typename T> void SetObserver<T>::update()
{
    Set<T>* subject = static_cast<SetObserver*>(observedSubject);
    if (subject != 0)
    {
        T* array = subject->getValues();
        int length = sizeof(array)/sizeof(*array);
        
        subject->setLength(length);
        subject->sortSet();
        subject->removeDuplicates();
    }
    
    cout << "\nNotifier: Set updated\n";
}
#pragma mark -

template<typename T>
bool isNumeric()
{
    if(typeid(int) == typeid(T))
        return true;
    
    if(typeid(double) == typeid(T))
        return true;
    
    if(typeid(float) == typeid(T))
        return true;
    
    if(typeid(long) == typeid(T))
        return true;
    
    return false;
}

#pragma mark - Sort values array
template<typename T> int Set<T>::compareElements(const void *a, const void *b) {
    if(isNumeric<T>()) return (*(T*)a - *(T*)b);
    else if(typeid(T) == typeid(char*)) return strcmp((char*)a, (char*)b);
    else return 0;
}

template<typename T> void Set<T>::sortSet() {
    qsort(this->values, this->_length, sizeof(int), this->compareElements);
}

#pragma mark - Check if element exists
template<typename T> bool Set<T>::elementExists(T value) {
    for(int i = 0; i < this->_length; i++) {
        if(this->values[i] == value)
            return true;
    }
    
    return false;
}

template<typename T> void Set<T>::removeDuplicates() {
    int *current , *end = this->values + this->_length - 1;
    
    for ( current = this->values + 1; this->values < end; this->values++, current = this->values + 1 )
    {
        while ( current <= end )
        {
            if ( *current == *this->values )
            {
                *current = *end--;
            }
            else
            {
                current++;
            }
        }
    }
}

#pragma mark - Accessors: getters and setters
#pragma mark Length
template<typename T> int Set<T>::getLength() {
    return this->_length;
}

template<typename T> void Set<T>::setLength(int length) {
    this->_length = length;
}

#pragma mark ValuesArray
template<typename T> T* Set<T>::getValues() {
    return this->values;
}

template<typename T> void Set<T>::setValues(T* newValuesArray) {
    this->values = newValuesArray;
    notifyObservers();
}

#pragma mark - Operators
//MARK: +=
template<typename T> void Set<T>::push(const T value)
{
    T* temp = new int[this->_length+1];
    
    std::copy(
              this->values,
              this->values + this->_length,
              temp
              );
    
    delete[] this->values;
    this->values = temp;
    
    notifyObservers();
}

template<typename T> Set<T>& Set<T>::operator+= (const T value) {
    push(value);
}

//MARK: -= and =
template<typename T> T&& Set<T>::pop() {
    if(this->_length > 0)
    {
        T popValue = this->values[this->_length];
        
        T* temp = new int[this->_length-1];
        
        std::copy(
                  this->values,
                  this->values + this->_length,
                  temp
                  );
        
        delete[] this->values;
        this->values = temp;
        
        notifyObservers();
        
        return popValue;
    }
    
    return NULL;
}

template<typename T> void Set<T>::operator-= (T&& popValue) {
    popValue = this->pop();
}

template<typename T> void Set<T>::operator= (T&& popValue) {
    popValue = this->pop();
}

template<typename T> Set<T>& Set<T>::operator= (const T* newValuesArray) {
    this->setValues(newValuesArray);
}

//MARK: []
template<typename T> T Set<T>::operator[] (const int index) {
    return this->values[index];
}

template<typename T> Set<T>& Set<T>::operator+ (const Set<T>& set2) {
    Set<T> newSet = new Set<T>(this->_length + (*set2)->getLength());
    
    for(int i=0; i<this->_length; i++) {
        newSet += this->values[i];
    }
    
    for(int i=0; i<(*set2)->getLength(); i++) {
        newSet += (*set2)[i];
    }
    
    return newSet;
}

//MARK: < and >
template<typename T> bool Set<T>::operator< (const Set<T>& set2) {
    if((*set2)->getLength() < this->_length)
        return true;
    return false;
}

template<typename T> bool Set<T>::operator> (const Set<T>& set2) {
    if((*set2)->getLength() > this->_length)
        return true;
    return false;
}

//MARK: << and >>
template<typename T> std::ostream& operator << (std::ostream& out, const Set<T>& set2) {
    
}
