#include "AugmentMethods/adGrayScale.h"
    
adGrayScale::adGrayScale(float scale){
    this->scale = scale;
}

void adGrayScale::apply(Mat& src){
    Mat grayMat;
    cvtColor(src, grayMat, CV_BGR2GRAY);

    grayMat = grayMat*scale;

    grayMat.copyTo(src);
}

void adGrayScale::randomInit(){
    this->scale = (float)(rand()%100)/100.f;
}

void adGrayScale::setGrayScale(float scale){
    this->scale = scale;
}