#ifndef SHEAR_IMAGE_H
#define SHEAR_IMAGE_H

#include "AugmentMethods/adAugmentMethod.h"
#include "AugmentMethods/adTranslate.h"
#include "adProbabilityParams.h"

class adShearImage : public adAugmentMethod{
private:
    float shearX;
    float shearY;
    float maxShear;

    adTranslate adTrans;
    adProbabilityParams probParams;

public:
    adShearImage();
    adShearImage(float shearX, float shearY, float maxShear = 0.2 );

    void apply(Mat& src);
    void randomInit();

    float getShearX(){ return shearX; }
    float getShearY(){ return shearY; }
    float getMaxShear(){ return maxShear; }

    void setShearX(float shearX);
    void setShearY(float shearY);
    void setMaxShear(float maxShear);
};

#endif