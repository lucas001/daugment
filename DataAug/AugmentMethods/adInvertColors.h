#ifndef INVERTED_COLORS_H
#define INVERTED_COLORS_H

#include "AugmentMethods/adAugmentMethod.h"
#include "adProbabilityParams.h"

class adInvertColors : public adAugmentMethod{
private:
    vector<int> vecInv;

    adProbabilityParams probParams;

public:
    adInvertColors(vector<int> vecInv);
    adInvertColors();
    void apply(Mat& src);
    void randomInit();

    void setVecInv(vector<int> vecInv);
    
    vector<int> getVecInv(){ return vecInv; }
};

#endif