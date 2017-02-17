#ifndef BILATERAL_FILTER_H
#define BILATERAL_FILTER_H

#include "AugmentMethods/adAugmentMethod.h"
#include "adProbabilityParams.h"

class adBilateralFilter : public adAugmentMethod{
private:
    float sigmaClr;
    float sigmaDst;
    int devNormalization;

    adProbabilityParams probParams;

public:
    adBilateralFilter();
    adBilateralFilter(float sigmaClr, float sigmaDst, int devNormalization = 40);

    void apply(Mat& src);
    void randomInit();

    float getSigmaClr(){ return sigmaClr; }
    float getSigmaDst(){ return sigmaDst; }
    float getDevNormalization(){ return devNormalization; }

    void setSigmaClr(float sigmaClr);
    void setSigmaDst(float sigmaDst);
    void setDevNormalization(int devNormalization);
};

#endif