#include "decorator_parent.h"

class deco1 : public decorator{
    public:
    deco1(base*b){
        setParent(b);
    }
    string getDescription(){
        return this->getParentDescription() + " + deco1";
    }
    ll getCost(){
        return this->getParentCost() + 10;
    }
};
