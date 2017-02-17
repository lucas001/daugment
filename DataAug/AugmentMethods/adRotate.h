#ifndef ROTATE_H
#define ROTATE_H

#include "AugmentMethods/adAugmentMethod.h"
#include "adProbabilityParams.h"

class adRotate : public adAugmentMethod{
private:
    int angle;
    int maxAngRot;

    adProbabilityParams probParams;

public:
    adRotate();
    adRotate(int angle, int maxAngRot = 25);

    void apply(Mat& src);
    void randomInit();

    int getAngle(){ return angle; };

    void setAngle(int angle);
};

#endif