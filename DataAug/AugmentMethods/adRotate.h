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
    int getMaxAngle(){ return maxAngRot; }
    
    void setMaxAngle(int maxAngle);
    void setAngle(int angle);
};

#endif