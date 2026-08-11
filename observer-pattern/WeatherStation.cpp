#include "./headers/WeatherStation.h"
#include "./headers/RandGen.h"
#include "headers/observer.h"
#include <chrono>
#include <climits>
#include <cmath>
#include <thread>



using namespace std;


void WeatherStation::notifyObservers()  {
  for(Observer*ob: observers){
    ob->update(temperature, humidity, heat_index);
  }
}

void WeatherStation::record_Temperature()  {
  auto interval = std::chrono::seconds(2);
  auto nextRun = std::chrono::steady_clock::now();

  while (true) {
    nextRun += interval;
    double temp = randGen(10, 50);
    temperature = temp;
    record_headIndex();
    this->notifyObservers();
    std::this_thread::sleep_until(nextRun);
  }
}

void WeatherStation::record_humidity(){
    auto interval = std::chrono::seconds(3);
  auto nextRun = std::chrono::steady_clock::now();

  while (true) {
    nextRun += interval;
    double hum = randGen(20, 80);
    humidity = hum;
    record_headIndex();
    this->notifyObservers();
    std::this_thread::sleep_until(nextRun);
  }
}

void WeatherStation::record_headIndex(){
  double heat_idx =  16.923 + 1.85212 * 10-1 * temperature + 5.37941 * humidity - 1.00254 * 10-1 *
temperature * humidity + 9.41695 * 10-3 * temperature*temperature + 7.28898 * 10-3 * humidity*humidity + 3.45372 *
10-4 * temperature*temperature * humidity - 8.14971 * 10-4 * temperature * humidity*humidity + 1.02102 * 10-5 * temperature*temperature *
humidity*humidity - 3.8646 * 10-5 * temperature*temperature*temperature + 2.91583 * 10-5 * pow(humidity,3) + 1.42721 * 10-6
* pow(temperature, 3) * humidity + 1.97483 * 10-7 * temperature * pow(humidity, 3) - 2.18429 * 10-8 * pow(temperature, 3) * pow(humidity,2)
+ 8.43296 * 10-10 * pow(temperature, 2)* pow(humidity, 3) - 4.81975 * 10-11 * pow(temperature, 3) * pow(humidity, 3);

heat_index = heat_idx;
}




WeatherStation::WeatherStation() {
  std::thread t1(&WeatherStation::record_Temperature, this);
  std::thread t2(&WeatherStation::record_humidity, this);
  t1.detach();
  t2.detach();
}


double WeatherStation::get_temperature(){
  return temperature;
}

double WeatherStation::get_humidity(){
  return humidity;
}

double WeatherStation::get_head_index(){
  return heat_index;
}
