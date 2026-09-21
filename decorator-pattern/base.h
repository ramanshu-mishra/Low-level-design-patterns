#pragma once 
#include "string"
using namespace std;
#define ll long long

class base{ 
    public:
    virtual string getDescription()=0;

    virtual ll getCost()=0;
};