#include "decorator_parent.h"

class deco2 : public decorator{
     public:
    deco2(base*b){
        setParent(b);
    }
    string getDescription(){
        return this->getParentDescription() + " + deco2";
    }
    ll getCost(){
        return this->getParentCost() + 20;
    }
};
