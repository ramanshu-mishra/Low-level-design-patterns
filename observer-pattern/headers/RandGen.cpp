#include "./RandGen.h"
#include <random>

extern "C" double randGen(double a, double b){
    std::random_device rd;
    
    std::mt19937 gen{rd()};
    
    std::uniform_real_distribution<double>distrib{a, b};

    double r = distrib(gen);
    return r;
};