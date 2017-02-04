#include "AugmentMethods/adGaussianNoise.h"
    
adGaussianNoise::adGaussianNoise(float meanSc, float stdDevSc, bool channels, int gaussMaxMean, int gaussMaxStd){
    this->meanSc = meanSc;
    this->stdDevSc = stdDevSc;
    this->gaussMaxMean = gaussMaxMean;
    this->gaussMaxStd = gaussMaxStd;
}

void adGaussianNoise::apply(Mat& src){
    Mat noise(src.size(),src.type());

    if(src.channels() == 1) channels = false;

    Scalar mean(meanSc);
    Scalar stdDev(stdDevSc);
    
    randn(noise,meanSc,stdDevSc);

    src += noise;
}

void adGaussianNoise::randomInit(){
    meanSc = (float)(rand()%(gaussMaxMean*100))/100.f;
    stdDevSc = (float)(rand()%(gaussMaxStd*100))/100.f;
    
    channels = (rand()%100 < 50) ? true : false;
}

void adGaussianNoise::setMeanSc(float meanSc){
    this->meanSc = meanSc;
}

void adGaussianNoise::setStdDevSc(float stdDevSc){
    this->stdDevSc = stdDevSc;
}

void adGaussianNoise::setChannels(bool channels){
    this->channels = channels;
}

void adGaussianNoise::setGaussMaxStd(float gaussMaxStd){
    this->gaussMaxStd = gaussMaxStd;
}

void adGaussianNoise::setGaussMaxMean(float gaussMaxMean){
    this->gaussMaxMean = gaussMaxMean;
}