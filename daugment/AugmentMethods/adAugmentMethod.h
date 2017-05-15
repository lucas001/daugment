#ifndef AUGMENT_METHOD_H
#define AUGMENT_METHOD_H

#include "adDataHeader.h"

class adAugmentMethod{
private:

public:
    adAugmentMethod(){};
    ~adAugmentMethod(){};
    virtual void apply(Mat& src) = 0;
    virtual void randomInit() {};
};

#endif