#include "decorator_parent.h"

class deco3 : public decorator{
     public:
    deco3(base*b){
        setParent(b);
    }
    string getDescription(){
        return this->getParentDescription() + " + deco3";
    }
    ll getCost(){
        return this->getParentCost() + 30;
    }
};
