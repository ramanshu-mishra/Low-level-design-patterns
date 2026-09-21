#include "./context.h"
#include "./state.h"
#include "chrono"
#include "thread"


int main(){
    context* _context = new context();
    state* red = new state("red", _context);
    state* yellow = new state("yellow", _context);
    state* green = new state("green", _context);

    red->set_next_state(*green);
    yellow->set_next_state(*red);
    green->set_next_state(*yellow);


    _context->setState(red);
    while(true){
        _context->getState()->action();
         auto nextInterval = std::chrono::seconds(2);
        auto nextRun = std::chrono::steady_clock::now();
        std::this_thread::sleep_until(nextRun+nextInterval);

    }
    

    return 0;
}