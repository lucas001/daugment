#ifndef CANNY_EDGE_H
#define CANNY_EDGE_H

#include "AugmentMethods/adAugmentMethod.h"
#include "adProbabilityParams.h"

class adCannyEdge : public adAugmentMethod{
private:
    adProbabilityParams probParams;

public:
    adCannyEdge();

    void apply(Mat& src);
    void randomInit();
};

#endif