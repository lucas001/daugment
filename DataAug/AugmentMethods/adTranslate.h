#ifndef TRANSLATE_H
#define TRANSLATE_H

#include "AugmentMethods/adAugmentMethod.h"
#include "adProbabilityParams.h"

class adTranslate : public adAugmentMethod{
private:
    float transX;
    float transY;
    float maxPercTrans;
    bool keepSize;

    bool isRandInit;
    float percX;
    float percY;

    adProbabilityParams probParams;

public:
    adTranslate();
    adTranslate(float transX, float transY, float maxPercTrans = 0.3, bool keepSize = true);

    void apply(Mat& src);
    void randomInit();

    float getTransX(){ return transX; }
    float getTransY(){ return transY; }
    float getMaxPercTrans(){ return maxPercTrans; }
    bool getKeepSize() { return keepSize; }

    void setTransX(float transX);
    void setTransY(float transY);
    void setMaxPercTrans(float maxPercTrans);
    void setKeepSize(bool keepSize);
};

#endif