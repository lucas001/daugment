#ifndef GAUSSIAN_NOISE_H
#define GAUSSIAN_NOISE_H

#include "AugmentMethods/adAugmentMethod.h"
#include "adProbabilityParams.h"

class adGaussianNoise : public adAugmentMethod{
private:
    float meanSc;
    bool channels;
    float stdDevSc;
    int gaussMaxMean;
    int gaussMaxStd;

public:
    adGaussianNoise(){};
    adGaussianNoise(float meanSc, float stdDevSc, bool channels, int gaussMaxMean, int gaussMaxStd);

    void apply(Mat& src);
    void randomInit();

    void setMeanSc(float meanSc);
    void setStdDevSc(float stdDevSc);
    void setChannels(bool channels);
    void setGaussMaxStd(float gaussMaxStd);
    void setGaussMaxMean(float gaussMaxMean);

    float getMeanSc(){ return meanSc; };
    float getStdDevSc(){ return stdDevSc; };
    bool getChannels(){ return channels; };
    int getGaussMaxStd(){ return gaussMaxStd; };
    int getGaussMaxMean(){ return gaussMaxMean; };
};

#endif