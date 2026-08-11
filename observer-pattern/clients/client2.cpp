#include "../headers/observer.h"
#include "../headers/WeatherStation.h"
#include <iostream>

class client2 : public Observer{
    WeatherStation* ws = nullptr;

    double temperature = 0;

    public:
    client2(WeatherStation*ws){
        this->ws =ws;
        ws->registerObserver(this);
    }

    
     void update(double temperature, double humidity, double heat_index) override{
        this->temperature = temperature;
        std::string message = "[client2] temperature : " + std::to_string(temperature)+"\n";
        std::cout<<message<<std::flush;
    }
};