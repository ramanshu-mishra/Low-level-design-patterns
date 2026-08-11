#include "../headers/observer.h"
#include "../headers/WeatherStation.h"
#include <iostream>


class client1 : public Observer{
    WeatherStation* ws = nullptr;

    double humidity = 0;

    public:

    client1(WeatherStation*ws){
        this->ws =ws;
        ws->registerObserver(this);
    }

    void update(double temperature, double humidity, double heat_index) override{
        this->humidity = humidity;
        std::string message = "[client1] humidity : " + std::to_string(humidity)+"\n";
        std::cout<<message<<std::flush;
    }

};