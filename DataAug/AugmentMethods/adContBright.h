#ifndef CONT_BRIGHT_H
#define CONT_BRIGHT_H

#include "AugmentMethods/adAugmentMethod.h"
#include "adProbabilityParams.h"

class adContBright : public adAugmentMethod{
private:
    int brightness;
    float contrast; 
    int maxDevBrightness;
    int maxContrast; 
    float marginContrast;

public:
    adContBright(){};
    adContBright(int brightness, double contrast, int maxDevBrightness, int maxContrast, float marginContrast);

    void apply(Mat& src);
    void randomInit();

    void setBrightness(int brightness);
    void setContrast(float contrast);
    void setMaxDevBrightness(int maxDevBrightness);
    void setMaxContrast(int maxContrast);
    void setMarginContrast(float marginContrast);

    int setBrightness(){ return brightness; };
    float setContrast(){ return contrast; };
    int setMaxDevBrightness(){ return maxDevBrightness; };
    int setMaxContrast(){ return maxContrast; };
    float setMarginContrast(){ return marginContrast; };
};

#endif