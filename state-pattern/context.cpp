#include "./context.h"
#include "state.h"


void context::setState(state*s){
    this->_state = s;
}

state* context::getState(){
    return this->_state;
}
