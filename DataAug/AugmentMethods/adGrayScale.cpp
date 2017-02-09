#include "AugmentMethods/adGrayScale.h"
    
adGrayScale::adGrayScale(float scale){
    this->scale = scale;
}

adGrayScale::adGrayScale(){
    randomInit();
}

void adGrayScale::apply(Mat& src){
    Mat grayMat;
    cvtColor(src, grayMat, CV_BGR2GRAY);

    grayMat = grayMat+255*scale;

    grayMat.copyTo(src);
}

void adGrayScale::randomInit(){
    this->scale = probParams.uniformDistribution(0,1.0);
}

void adGrayScale::setGrayScale(float scale){
    this->scale = scale;
}