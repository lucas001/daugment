#include "adProbabilityParams.h"

float adProbabilityParams::binomialDistribution(float pSuccess , float range){
    std::default_random_engine generator;
    std::binomial_distribution<int> distribution(pSuccess,range);

    float number = distribution(generator);
    return number/range;
}

float adProbabilityParams::poissonDistribution(int mean){
    std::default_random_engine generator;
    std::poisson_distribution<int> distribution(mean);

    float number = distribution(generator);
    return number;
}

float adProbabilityParams::uniformDistribution(int beginInter, int endInter){
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(beginInter,endInter);

    float number = distribution(generator);
    return number/(float)endInter;
}

float adProbabilityParams::normalDistribution(float med, float stdDev){
    std::default_random_engine generator;
    std::normal_distribution<float> distribution(med,stdDev);

    float number = distribution(generator);
    return number;
}

float adProbabilityParams::exponentialDistribution(float x){
    std::default_random_engine generator;
    std::exponential_distribution<float> distribution(x);

    float number = distribution(generator);
    return number;
}