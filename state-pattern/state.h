#pragma once
#include <string>

class context;

class state{
    public:
        state(std::string s, context*c): _context(c) , state_name(s) {}
        virtual void action();
        void change_state();
        void set_next_state(state&);
    private:
    std::string state_name;
    context*_context = nullptr;
    state*next_state;
};