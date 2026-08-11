#include "../subject.h"
#include "../observer.h"



void Subject::registerObserver(Observer*ob){
    this->observers.insert(ob);
}

void Subject::removeObserver(Observer*ob){
    this->observers.erase(ob);
}

