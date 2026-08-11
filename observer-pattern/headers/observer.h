#pragma once 
#include "./subject.h"



class Observer{
    void subscribe(Subject*sb);
    void unsubscribe(Subject*sb);
    public:
    virtual void update(double, double, double)=0;

};