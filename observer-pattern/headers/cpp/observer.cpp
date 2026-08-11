#include "../observer.h"


void Observer::subscribe(Subject*sb){
    sb->registerObserver(this);
}

void Observer::unsubscribe(Subject*sb){
    sb->removeObserver(this);
}

