#include "./state.h"
#include "./context.h"

#include <iostream>



void state::action(){
    std::cout<<this->state_name<<"\n";
    
    change_state();
}

void state::change_state(){
    (this->_context)->setState(this->next_state);
}

void state::set_next_state(state& s){
    this->next_state = &s;
}