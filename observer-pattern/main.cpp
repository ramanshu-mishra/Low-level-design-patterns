#include "./headers/WeatherStation.h"
#include "./clients/client1.cpp"
#include "./clients/client2.cpp"
#include "./clients/client3.cpp"
#include <condition_variable>
#include <mutex>
#include <iostream>

int main(){
    WeatherStation*w = new WeatherStation();
    client1* cl1 = new client1(w);
    client2* cl2 = new client2(w);
    client3* cl3 = new client3(w);

    


    std::mutex dummy_mutex;
    std::condition_variable cv;

    // 2. Lock the mutex
    std::unique_lock<std::mutex> lock(dummy_mutex);

    // 3. Sleep forever (since no one will ever call cv.notify_all())
    cv.wait(lock);

    // This line will never be reached
    return 0;
    
    std::cout << "Main thread exiting.\n";
    return 0;
};