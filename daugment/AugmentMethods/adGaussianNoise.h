#ifndef GAUSSIAN_NOISE_H
#define GAUSSIAN_NOISE_H

#include "AugmentMethods/adAugmentMethod.h"
#include "adProbabilityParams.h"

class adGaussianNoise : public adAugmentMethod{
private:
    float meanSc;
    bool channels;
    float stdDevSc;
    float gaussMaxMean;
    float gaussMaxStd;
    float gaussMinMean;
    float gaussMinStd;

    adProbabilityParams probParams;

public:
    adGaussianNoise(float gaussMaxMean = 150, float gaussMaxStd = 80, float gaussMinMean = 20, float gaussMinStd = 30);
    adGaussianNoise(float meanSc, float stdDevSc, bool channels, float gaussMaxMean = 1, float gaussMaxStd = 1, float gaussMinMean = 20, float gaussMinStd = 30);

    void apply(Mat& src);
    void randomInit();

    void setMeanSc(float meanSc);
    void setStdDevSc(float stdDevSc);
    void setChannels(bool channels);
    void setGaussMaxStd(float gaussMaxStd);
    void setGaussMaxMean(float gaussMaxMean);
    void setGaussMinStd(float gaussMinStd);
    void setGaussMinMean(float gaussMinMean);

    float getMeanSc(){ return meanSc; }
    float getStdDevSc(){ return stdDevSc; }
    bool getChannels(){ return channels; }
    float getGaussMaxStd(){ return gaussMaxStd; }
    float getGaussMaxMean(){ return gaussMaxMean; }
    float getGaussMinStd(){ return gaussMinStd; }
    float getGaussMinMean(){ return gaussMinMean; }
};

#endif