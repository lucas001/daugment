#ifndef CONT_BRIGHT_H
#define CONT_BRIGHT_H

#include "AugmentMethods/adAugmentMethod.h"
#include "adProbabilityParams.h"

class adContBright : public adAugmentMethod{
private:
    int brightness;
    float contrast;
    int minBrightness; 
    int maxBrightness;
    float maxContrast; 
    float minContrast;

    adProbabilityParams probParams;

public:
    adContBright(int minBrightness = 50, int maxBrightness = 150, float maxContrast = 1.5, float minContrast = 0.5);
    adContBright(int brightness, double contrast, int minBrightness = 50, int maxBrightness = 150, float maxContrast = 150, float minContrast = 50);

    void apply(Mat& src);
    void randomInit();

    void setBrightness(int brightness);
    void setContrast(float contrast);
    void setMaxBrightness(int maxBrightness);
    void setMinBrightness(int minBrightness);
    void setMaxContrast(float maxContrast);
    void setMinContrast(float minContrast);

    int getBrightness(){ return brightness; }
    float getContrast(){ return contrast; }
    int getMaxBrightness(){ return maxBrightness; }
    int getMinBrightness(){ return minBrightness; }
    float getMaxContrast(){ return maxContrast; }
    float getMinContrast(){ return minContrast; }
};

#endif