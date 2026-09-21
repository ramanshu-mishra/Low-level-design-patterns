#pragma once 
#include "./state.h"
class context{
    private:
        state*_state = nullptr;
    public:
        void setState(state*);
        state* getState();
};