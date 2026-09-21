#pragma once
#include "./base.h"

class decorator : public base{
    base*_b;
    public:
        string getParentDescription(){
            return _b->getDescription();
        }
        ll getParentCost(){
            return _b->getCost();
        }
    protected:
        void setParent(base*b){
            this->_b = b;
        }
};