#include "AugmentMethods/adGaussianNoise.h"
    
adGaussianNoise::adGaussianNoise(float meanSc, float stdDevSc, bool channels, float gaussMaxMean, float gaussMaxStd, float gaussMinMean, float gaussMinStd){
    this->meanSc = meanSc;
    this->stdDevSc = stdDevSc;
    this->gaussMaxMean = gaussMaxMean;
    this->gaussMaxStd = gaussMaxStd;
    this->gaussMinMean = gaussMinMean;
    this->gaussMinStd = gaussMinStd;
}

adGaussianNoise::adGaussianNoise(float gaussMaxMean, float gaussMaxStd, float gaussMinMean, float gaussMinStd) : 
adGaussianNoise(0,0,false,gaussMaxMean, gaussMaxStd, gaussMinMean, gaussMinStd){
    randomInit();
}

void adGaussianNoise::apply(Mat& src){
    Mat noise = Mat::zeros(src.size(), src.type());
    Mat chSrc[src.channels()];
    Scalar mean(meanSc);
    Scalar stdDev(stdDevSc);

    if(!channels){
        randn(noise,meanSc,stdDevSc);
        src += noise;
        return;
    }
    
    split(src,chSrc);

    int numIt = probParams.uniformDistribution(1, src.channels());

    for(int i = 0; i < numIt; i++){
        noise = Mat::zeros(src.size(), CV_8UC1);
        randn(noise,meanSc,stdDevSc);
        int numCh = probParams.uniformDistribution(0, src.channels()-1);
        chSrc[numCh] += noise;
    }

    merge(chSrc,3,src);
}

void adGaussianNoise::randomInit(){
    meanSc = probParams.uniformDistribution(gaussMinMean,gaussMaxMean);
    stdDevSc = probParams.uniformDistribution(gaussMinStd,gaussMaxStd);
    
    channels = (probParams.uniformDistribution(0,100) < 50) ? true : false;
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

void adGaussianNoise::setGaussMinStd(float gaussMinStd){
    this->gaussMinStd = gaussMinStd;
}

void adGaussianNoise::setGaussMinMean(float gaussMinMean){
    this->gaussMinMean = gaussMinMean;
}