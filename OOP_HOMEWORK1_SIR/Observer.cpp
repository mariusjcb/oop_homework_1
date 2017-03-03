//
//  Observer.cpp
//  OOP_HOMEWORK1_SIR
//
//  Created by Marius Ilie on 03/03/2017.
//  Copyright © 2017 Marius Ilie @ FMI 143. All rights reserved.
//

#include "Observer.hpp"
#include <iostream>
using namespace std;

#include <list>
class Observable {
private:
    std::list<Observer* const> observers;
    
public:
    ~Observable()
    {
        std::list<Observer * const>::iterator iterator = observers.begin();
        
        while (iterator != observers.end())
        {
            delete *iterator;
            iterator = observers.erase(iterator);
        }
    }
    
    void addObserver(Observer * const observer)
    {
        observer->observedSubject = this;
        observers.push_back(observer);
    }
    
    void removeObserver(Observer * const observer)
    {
        observers.remove(observer);
        delete observer;
    }
    
    void notifyObservers()
    {
        std::list<Observer * const>::iterator iterator = observers.begin();
        
        while (iterator != observers.end())
        {
            (*iterator)->update();
            iterator++;
        }
    }
};
