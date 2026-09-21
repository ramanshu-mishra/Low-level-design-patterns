#include "./base.h"

class base2: public base{
    string getDescription() override{
        return "base2";
    }
    ll getCost() override{
        return 20;
    }
};