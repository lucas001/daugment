#include "AugmentMethods/adContBright.h"
    
adContBright::adContBright(int brightness, double contrast, int minBrightness, int maxBrightness, float maxContrast, float minContrast){
    this->brightness = brightness;
    this->contrast = contrast;
    this->maxBrightness = maxBrightness;
    this->minBrightness = minBrightness;
    this->maxContrast = maxContrast;
    this->minContrast = minContrast;
}

adContBright::adContBright(int minBrightness, int maxBrightness, float maxContrast, float minContrast):
adContBright(0,0,minBrightness,maxBrightness,maxContrast, minContrast){
    randomInit();
}

void adContBright::apply(Mat& src){
    int beta = brightness;
    double alpha = contrast;
    Mat out = Mat::zeros(src.size(),src.type());

    for( int y = 0; y < src.rows; y++ ){
        for( int x = 0; x < src.cols; x++ ){
            for( int c = 0; c < src.channels(); c++ ){
                out.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( alpha*( src.at<Vec3b>(y,x)[c] ) + beta );
            }
        }
    }

    out.copyTo(src);
}

void adContBright::randomInit(){
    brightness = probParams.uniformDistribution(minBrightness,maxBrightness);
    contrast = probParams.uniformDistribution(minContrast,maxContrast);
}

void adContBright::setBrightness(int brightness){
    this->brightness = brightness;
}

void adContBright::setContrast(float contrast){
    this->contrast = contrast;
}

void adContBright::setMaxBrightness(int maxBrightness){
    this->maxBrightness = maxBrightness;
}

void adContBright::setMinBrightness(int minBrightness){
    this->minBrightness = minBrightness;
}

void adContBright::setMaxContrast(float maxContrast){
    this->maxContrast = maxContrast;
}

void adContBright::setMinContrast(float minContrast){
    this->minContrast = minContrast;
}