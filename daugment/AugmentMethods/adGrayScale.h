#ifndef GRAY_SCALE_H
#define GRAY_SCALE_H

#include "AugmentMethods/adAugmentMethod.h"
#include "adProbabilityParams.h"

class adGrayScale : public adAugmentMethod{
private:
    float scale;
    float maxScale;
    float minScale; 

    adProbabilityParams probParams;
public:
    adGrayScale(float minScale = 0, float maxScale = 0.5);
    adGrayScale(float scale, float minScale = 0, float maxScale = 0.5);

    void apply(Mat& src);
    void randomInit();

    void setGrayScale(float scale);
    void setMaxGrayScale(float maxScale);
    void setMinGrayScale(float minScale);

    float getGrayScale(){ return scale; }
    float getMaxGrayScale(){ return maxScale; }
    float getMinGrayScale(){ return minScale; }
};

#endif