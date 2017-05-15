#ifndef FLIP_DIMENSIONS_H
#define FLIP_DIMENSIONS_H

#include "AugmentMethods/adAugmentMethod.h"
#include "adProbabilityParams.h"

class adFlipDimensions : public adAugmentMethod{
private:
    vector<int> vecFlip;

    adProbabilityParams probParams;

public:
    adFlipDimensions(vector<int> vecFlip);
    adFlipDimensions();
    void apply(Mat& src);
    void randomInit();

    void setVecFlip(vector<int> vecFlip);
    
    vector<int> getVecFlip(){ return vecFlip; }
};

#endif