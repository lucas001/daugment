#ifndef SCALE_IMAGE_H
#define SCALE_IMAGE_H

#include "AugmentMethods/adAugmentMethod.h"
#include "AugmentMethods/adResizeImage.h"

class adResizeImage;

class adScaleImage : public adAugmentMethod{
private:
    float scale;
    int devScale;
    int marginScale;

    adResizeImage adResIm;

public:
    adScaleImage(float scale, int devScale, int marginScale);
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