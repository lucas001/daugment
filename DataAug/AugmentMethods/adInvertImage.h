#ifndef INVERT_IMAGE_H
#define INVERT_IMAGE_H

#include "AugmentMethods/adAugmentMethod.h"
#include "adProbabilityParams.h"

class adInvertImage : public adAugmentMethod{
private:
    bool flipLr;
    bool flipUd;

    adProbabilityParams probParams;
public:
    adInvertImage();
    adInvertImage(bool flipLr, bool flipUd);
    void apply(Mat& src);
    void randomInit();

    void setFlipUd(bool flipUd);
    void setFlipLr(bool flipLr);

    bool getFlipUd() { return flipUd; };
    bool getFlipLr() { return flipLr; };
};

#endif