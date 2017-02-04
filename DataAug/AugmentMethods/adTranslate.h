#ifndef TRANSLATE_H
#define TRANSLATE_H

#include "AugmentMethods/adAugmentMethod.h"
#include "adProbabilityParams.h"

class adTranslate : public adAugmentMethod{
private:
    float transX;
    float transY;
    int maxPercTrans;
    bool keepSize;

    float percTrans;
    bool randInit;

public:
    adTranslate(float transX = 0, float transY = 0, float percTrans = 1, int maxPercTrans = 30, bool keepSize = true);

    void apply(Mat& src);
    void randomInit();

    float getTransX(){ return transX; }
    float getTransY(){ return transY; }
    float getPercTrans(){ return percTrans; }
    int getMaxPercTrans(){ return maxPercTrans; }
    bool getKeepSize() { return keepSize; }

    void setTransX(float transX);
    void setTransY(float transY);
    void setPercTrans(float percTrans);
    void setMaxPercTrans(int maxPercTrans);
    void setKeepSize(bool keepSize);
};

#endif