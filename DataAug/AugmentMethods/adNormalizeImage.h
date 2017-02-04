#ifndef NORMALIZE_IMAGE_H
#define NORMALIZE_IMAGE_H

#include "AugmentMethods/adAugmentMethod.h"
#include "adProbabilityParams.h"

class adNormalizeImage : public adAugmentMethod{
private:
    float maxNorm;
    float minNorm;
    int devNormalization;

public:
    adNormalizeImage(){}
    adNormalizeImage(float maxNorm, float minNorm, int devNormalization = 40);

    void apply(Mat& src);
    void randomInit();

    float getMaxNorm(){ return maxNorm; }
    float getMinNorm(){ return minNorm; }
    float getDevNormalization(){ return devNormalization; }

    void setMaxNorm(float maxNorm);
    void setMinNorm(float minNorm);
    void setDevNormalization(int devNormalization);
};

#endif