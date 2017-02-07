#ifndef GAUSSIAN_BLUR_H
#define GAUSSIAN_BLUR_H

#include "AugmentMethods/adAugmentMethod.h"
#include "adProbabilityParams.h"

class adGaussianBlur : public adAugmentMethod{
private:
    int numKernels;
    int minNumKGauss;
    int maxNumKGauss;
    float sigmaX;
    float sigmaY;
    float maxDevSigma;

    adProbabilityParams probParams;

public:
    adGaussianBlur(int minNumKGauss  = 20,int maxNumKGauss = 100, float sigmaX = 2, float sigmaY = 2, float maxDevSigma = 10);
    adGaussianBlur(int numKernels, int minNumKGauss  = 20,int maxNumKGauss = 100, float sigmaX = 2, float sigmaY = 2, float maxDevSigma = 10);
    ~adGaussianBlur(){};
    void randomInit();
    void apply(Mat& src);

    int getMaxKGauss(){ return maxNumKGauss; }
    int getMinKGauss(){ return minNumKGauss; }
    int getNumKernels(){ return numKernels; }
    float getSigmaX(){ return sigmaX; }
    float getSigmaY(){ return sigmaY; }
    float getMaxDevSigma(){ return maxDevSigma; }

    void setMaxKGauss(int maxNumKGauss);
    void setMinKGauss(int minNumKGauss);
    void setNumKernels(int numKernels);
    void setSigmaX(float sigmaX);
    void setSigmaY(float sigmaY);
    void setMaxDevSigma(float maxDevSigma);
};

#endif