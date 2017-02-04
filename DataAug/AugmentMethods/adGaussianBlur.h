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

public:
    adGaussianBlur(){};
    adGaussianBlur(int minNumKGauss,int maxNumKGauss, float sigmaX, float sigmaY);
    ~adGaussianBlur(){};
    void randomInit();
    void apply(Mat& src);
};

#endif