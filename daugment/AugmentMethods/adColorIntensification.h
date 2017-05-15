#ifndef COLOR_INTENSICATION_H
#define COLOR_INTENSICATION_H

#include "AugmentMethods/adAugmentMethod.h"
#include "adProbabilityParams.h"

class adColorIntensification : public adAugmentMethod{
private:
    Vec3f unitaryChange;
    float maxIntensColor;

    adProbabilityParams probParams;

public:
    adColorIntensification();
    adColorIntensification(Vec3f unitaryChange, float maxIntensColor = 0.5);

    void apply(Mat& src);
    void randomInit();

    Vec3f getUnitaryChange(){ return unitaryChange; }
    float getMaxIntensColor(){ return maxIntensColor; }

    void setUnitaryChange(Vec3f unitaryChange);
    void setMaxIntensColor(float maxIntensColor);
};

#endif