#include "AugmentMethods/adDropoutChannel.h"

adDropoutChannel::adDropoutChannel(float perc, bool channels, int dev, float margin){
    this->perc = perc;
    this->channels = channels;
    this->devDropout = dev;
    this->marginDropout = margin;
}

void adDropoutChannel::apply(Mat& src){
    Mat color(src.size(),src.type());

    if(src.channels() == 1) channels = false;

    int numPixelsDrop = src.cols*src.rows*perc;
    if(channels) numPixelsDrop *= 3;

    srand(time(NULL));
    for(int i = 0; i < numPixelsDrop; i++){
        int column = rand()%src.cols;
        int row = rand()%src.rows;
        
        if(channels){
            int idCh = rand()%3;
            src.at<Vec3b>(row,column)[idCh] = 0;
        }else{
            src.at<double>(row,column) = 0;
        }
    }
}

void adDropoutChannel::randomInit(){
    perc = ((float)(rand()%(devDropout)+marginDropout))/100.f;
    channels = (rand()%100 < 50) ? true : false;
}

void adDropoutChannel::setPerc(float perc){
    this->perc = perc;
}

void adDropoutChannel::setChannels(bool channels){
    this->channels = channels;
}

void adDropoutChannel::setMarginDropout(float margin){
    this->marginDropout = margin;
}

void adDropoutChannel::setDevDropout(int dev){
    this->devDropout = dev;
}