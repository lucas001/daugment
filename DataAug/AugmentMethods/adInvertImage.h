#ifndef INVERT_IMAGE_H
#define INVERT_IMAGE_H

#include "AugmentMethods/adAugmentMethod.h"

class adInvertImage : public adAugmentMethod{
private:
    bool flipLr;
    bool flipUd;
public:
    adInvertImage(bool flipLr, bool flipUd);
    void apply(Mat& src);
    void randomInit();

    void setFlipUd(bool flipUd);
    void setFlipLr(bool flipLr);

    bool getFlipUd() { return flipUd; };
    bool getFlipLr() { return flipLr; };
};

#endif