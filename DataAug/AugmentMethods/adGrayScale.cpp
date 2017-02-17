#include "AugmentMethods/adGrayScale.h"
    
adGrayScale::adGrayScale(float scale, float minScale, float maxScale){
    this->scale = scale;
    this->minScale = minScale;
    this->maxScale = maxScale;
}

adGrayScale::adGrayScale(float minScale, float maxScale) :
adGrayScale(0,minScale, maxScale) {
    randomInit();
}

void adGrayScale::apply(Mat& src){
    Mat out = Mat::zeros(src.size(),CV_8UC1);
    cvtColor(src, out, CV_BGR2GRAY);

    cout << scale*255 << endl;
    out = out+scale*255;

    out.copyTo(src);
}

void adGrayScale::randomInit(){
    this->scale = probParams.uniformDistribution(minScale,maxScale);
}

void adGrayScale::setGrayScale(float scale){
    this->scale = scale;
}

void adGrayScale::setMaxGrayScale(float maxScale){
    this->maxScale = maxScale;
}
    
void adGrayScale::setMinGrayScale(float minScale){
    this->minScale = minScale;
}