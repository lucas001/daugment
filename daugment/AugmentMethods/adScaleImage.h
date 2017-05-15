#ifndef SCALE_IMAGE_H
#define SCALE_IMAGE_H

#include "AugmentMethods/adAugmentMethod.h"
#include "AugmentMethods/adResizeImage.h"
#include "adProbabilityParams.h"

class adResizeImage;

class adScaleImage : public adAugmentMethod{
private:
    float scale;
    float devScale;
    float marginScale;

    adResizeImage adResIm;
    adProbabilityParams probParams;

public:
    adScaleImage(float devScale = 0.4, float marginScale = 0.8);
    adScaleImage(float scale, float devScale = 0.4, float marginScale = 0.8);
    void apply(Mat& src);
    void randomInit();

    void setScale(float scale);
    void setMarginScale(int scale);
    void setDevScale(int scale);
    
    float getScale(){ return scale; }
    int getMarginScale(){ return marginScale; }
    int getDevScale(){ return devScale; }
};

#endif