#pragma once 
#include <unordered_set>


class Observer;

class Subject{
    protected:
    std::unordered_set<Observer*>observers;
    virtual void notifyObservers()=0;
    public:
    void registerObserver(Observer*ob);
    void removeObserver(Observer*ob);
};