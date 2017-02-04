#ifndef DROPOUT_CHANNEL_H
#define DROPOUT_CHANNEL_H

#include "AugmentMethods/adAugmentMethod.h"
#include "adProbabilityParams.h"

class adDropoutChannel : public adAugmentMethod{
private:
    float perc;
    bool channels;
    int devDropout;
    float marginDropout;

public:
    adDropoutChannel(){};
    adDropoutChannel(float perc, bool channels, int devDropout, float marginDropout);

    void randomInit();
    void apply(Mat& src);

    void setPerc(float perc);
    void setChannels(bool channels);
    void setMarginDropout(float margin);
    void setDevDropout(int dev);

    float getPerc(){ return perc; }
    bool getChannels(){ return channels; }
    float getMarginDropout() { return marginDropout; };
    int getDevDropout(){ return devDropout; };
};

#endif