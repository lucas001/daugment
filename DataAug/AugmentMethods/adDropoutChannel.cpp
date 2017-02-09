#include "AugmentMethods/adDropoutChannel.h"

adDropoutChannel::adDropoutChannel(float perc, bool channels, float minPercProp, float maxPercDrop){
    this->perc = perc;
    this->channels = channels;
    this->minPercDrop = minPercDrop;
    this->maxPercDrop = maxPercDrop;
}

adDropoutChannel::adDropoutChannel(float minPercProp, float maxPercDrop) :
adDropoutChannel(0,false, minPercDrop, maxPercDrop){
    randomInit();
}

void adDropoutChannel::apply(Mat& src){
    Mat color(src.size(),src.type());

    int numPixelsDrop = src.cols*src.rows*perc;
    numPixelsDrop *= src.channels();
    cout << numPixelsDrop << endl;

    for(int i = 0; i < numPixelsDrop; i++){
        int column = probParams.uniformDistribution(0,src.cols);
        int row = probParams.uniformDistribution(0,src.rows);
        
        int idCh = probParams.uniformDistribution(0,src.channels()-1);
        src.at<Vec3b>(row,column)[idCh] = 0;
    }
}

void adDropoutChannel::randomInit(){
    perc = probParams.uniformDistribution(minPercDrop, maxPercDrop);
    channels = (probParams.uniformDistribution(0,100) < 50) ? true : false;
}

void adDropoutChannel::setPerc(float perc){
    this->perc = perc;
}

void adDropoutChannel::setChannels(bool channels){
    this->channels = channels;
}

void adDropoutChannel::setMaxPercDrop(float maxPercDrop){
    this->maxPercDrop = maxPercDrop;
}

void adDropoutChannel::setMinPercDrop(float minPercDrop){
    this->minPercDrop = minPercDrop;
}