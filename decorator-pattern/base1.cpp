#include "./base.h"

class base1: public base{
    string getDescription() override{
        return "base1";
    }
    ll getCost() override{
        return 10;
    }
};