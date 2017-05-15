#ifndef DROPOUT_CHANNEL_H
#define DROPOUT_CHANNEL_H

#include "AugmentMethods/adAugmentMethod.h"
#include "adProbabilityParams.h"

class adDropoutChannel : public adAugmentMethod{
private:
    float perc;
    bool channels;
    float minPercDrop;
    float maxPercDrop;

    adProbabilityParams probParams;
public:
    adDropoutChannel(float minPercDrop = 0.3, float maxPercDrop = 0.7);
    adDropoutChannel(float perc, bool channels, float minPercDrop = 0.3, float maxPercDrop = 0.7);

    void randomInit();
    void apply(Mat& src);

    void setPerc(float perc);
    void setChannels(bool channels);
    void setMaxPercDrop(float maxPercDrop);
    void setMinPercDrop(float minPercDrop);

    float getPerc(){ return perc; }
    bool getChannels(){ return channels; }
    float getMaxPercDrop() { return maxPercDrop; }
    int getMinPercDrop(){ return minPercDrop; }
};

#endif