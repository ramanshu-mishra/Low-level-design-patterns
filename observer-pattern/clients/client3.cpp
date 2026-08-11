#include "../headers/observer.h"
#include "../headers/WeatherStation.h"
#include <cstdio>
#include <iostream>
#include <string>

class client3 : public Observer{
    WeatherStation* ws = nullptr;

    double heat_idx = 0;

    public:

    client3(WeatherStation*ws){
        this->ws =ws;
        ws->registerObserver(this);
    }

    void update(double temperature, double humidity, double heat_index) override{
        this->heat_idx= heat_index;
        std::string message = "client[3] heat_index : " + std::to_string(heat_index)+"\n";
        std::cout<<message<<std::flush;
    }
};