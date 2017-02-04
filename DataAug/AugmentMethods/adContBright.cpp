#include "AugmentMethods/adContBright.h"
    
adContBright::adContBright(int brightness, double contrast, int maxDevBrightness, int maxContrast, float marginContrast){
    this->brightness = brightness;
    this->contrast = contrast;
    this->maxDevBrightness = maxDevBrightness;
    this->maxContrast = maxContrast;
    this->marginContrast = marginContrast;
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
    brightness = rand()%maxDevBrightness;
    brightness -= rand()%maxDevBrightness;
    contrast = (float)(rand()%(maxContrast*100)+marginContrast)/100.f;
}

void adContBright::setBrightness(int brightness){
    this->brightness = brightness;
}

void adContBright::setContrast(float contrast){
    this->contrast = contrast;
}

void adContBright::setMaxDevBrightness(int maxDevBrightness){
    this->maxDevBrightness = maxDevBrightness;
}

void adContBright::setMaxContrast(int maxContrast){
    this->maxContrast = maxContrast;
}

void adContBright::setMarginContrast(float marginContrast){
    this->marginContrast = marginContrast;
}