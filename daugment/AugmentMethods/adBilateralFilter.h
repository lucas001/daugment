#ifndef BILATERAL_FILTER_H
#define BILATERAL_FILTER_H

#include "AugmentMethods/adAugmentMethod.h"
#include "adProbabilityParams.h"

class adBilateralFilter : public adAugmentMethod{
private:
    int kernels;
    float sigmaDst;
    float sigmaClr;
    int maxKernels;
    float minSigClr;
    float maxSigClr;
    float minSigDst;
    float maxSigDst;

    adProbabilityParams probParams;

public:
    adBilateralFilter();
    adBilateralFilter(int kernels, float sigmaDst, float sigmaClr, int maxKernels = 80, float minSigClr = 10, float maxSigClr = 120, float minSigDst = 5, float maxSigDst = 100);

    void apply(Mat& src);
    void randomInit();

    int getNumKernels(){ return kernels; }
    float getSigmaClr(){ return sigmaClr; }
    float getSigmaDst(){ return sigmaDst; }
    int getMaxKernels(){ return maxKernels; }
    float getMinSigClr(){ return minSigClr; }
    float getMaxSigClr(){ return maxSigClr; }
    float getMinSigDst(){ return minSigDst; }
    float getMaxSigDst(){ return maxSigDst; }

    void setSigmaClr(float sigmaClr);
    void setSigmaDst(float sigmaDst);
    void setNumKernels(int kernels);
    void setMaxKernels(int maxKernels);
    void setMinSigClr(float minSigClr);
    void setMaxSigClr(float maxSigClr);
    void setMinSigDst(float minSigDst);
    void setMaxSigDst(float maxSigDst);
};

#endif