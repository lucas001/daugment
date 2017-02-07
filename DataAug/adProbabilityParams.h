#ifndef PROBABILITY_PARAMS_H
#define PROBABILITY_PARAMS_H

#include "adDataHeader.h"

class adProbabilityParams {
public:
    float binomialDistribution(float pSuccess = 0.5f, float range = 100);
    float poissonDistribution(int mean = 50);
    float uniformDistribution(int begin = 0, int end = 100);
    float normalDistribution(float med = 0, float stdDev = 1);
    float exponentialDistribution(float x = 1);
};

#endif