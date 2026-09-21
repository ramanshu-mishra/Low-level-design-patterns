#include "./base1.cpp"
#include "./base2.cpp"
#include "./deco1.cpp"
#include "./deco2.cpp"
#include "./deco3.cpp"
#include <iostream>
#include <vector>


int main(){
    base* b1 = new base1();
    base* b2 = new base2();
    base* b3 = new deco1(b1);
    base* b4 = new deco2(b3);
    base* b5 = new deco3(b4);
    base* b6 = new deco3(new deco1(new deco2(b2)));

    vector<base*>v{b1,b2,b3,b4,b5,b6};

    for(auto&a: v){
        cout<<"description: "<<a->getDescription()<<" and cost: "<<a->getCost()<<"\n";
    }

}