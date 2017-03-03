//
//  Observer.hpp
//  OOP_HOMEWORK1_SIR
//
//  Created by Marius Ilie on 03/03/2017.
//  Copyright © 2017 Marius Ilie @ FMI 143. All rights reserved.
//

#ifndef Observer_hpp
#define Observer_hpp

class Observable;

class Observer {
    friend class Observable;
    
protected:
    Observable *observedSubject;
    
public:
    virtual void update(){};
};

#endif /* Observer_hpp */
