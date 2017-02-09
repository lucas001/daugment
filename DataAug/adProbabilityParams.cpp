#include "adProbabilityParams.h"

float adProbabilityParams::binomialDistribution(float pSuccess , float range){
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::binomial_distribution<int> distribution(pSuccess,range);

    float number = distribution(generator);
    return number/range;
}

float adProbabilityParams::poissonDistribution(int mean){
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::poisson_distribution<int> distribution(mean);

    float number = distribution(generator);
    return number;
}

float adProbabilityParams::uniformDistribution(float beginInter, float endInter){
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_real_distribution<float> distribution(beginInter,endInter);
    float number = distribution(generator);
    return number;
}

float adProbabilityParams::normalDistribution(float med, float stdDev){
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::normal_distribution<float> distribution(med,stdDev);

    float number = distribution(generator);
    return number;
}

float adProbabilityParams::exponentialDistribution(float x){
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::exponential_distribution<float> distribution(x);

    float number = distribution(generator);
    return number;
}