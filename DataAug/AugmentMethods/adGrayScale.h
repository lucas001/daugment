#ifndef GRAY_SCALE_H
#define GRAY_SCALE_H

#include "AugmentMethods/adAugmentMethod.h"
#include "adProbabilityParams.h"

class adGrayScale : public adAugmentMethod{
private:
    float scale; 

    adProbabilityParams probParams;
public:
    adGrayScale();
    adGrayScale(float scale);

    void apply(Mat& src);
    void randomInit();

    void setGrayScale(float scale);

    float getGrayScale(){ return scale; };
};

#endif