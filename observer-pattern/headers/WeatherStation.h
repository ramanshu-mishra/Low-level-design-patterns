#pragma once
#include <climits>
#include "./subject.h"


class WeatherStation : public Subject {
private:
    double temperature = INT_MIN;
    double humidity = INT_MIN;
    double heat_index = 0;
    void record_Temperature(); 
    void record_humidity();
    void record_headIndex();
    void notifyObservers() override;
    public:
    double get_temperature();
    double get_humidity();
    double get_head_index();
    

    WeatherStation(); 
};