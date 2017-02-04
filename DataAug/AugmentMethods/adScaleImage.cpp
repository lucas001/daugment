#include "AugmentMethods/adScaleImage.h"

adScaleImage::adScaleImage(float scale, int devScale, int marginScale){
    this->scale = scale;
    this->devScale = devScale;
    this->marginScale = marginScale;
}

void adScaleImage::apply(Mat& src){
    int width = src.cols*scale;
    int height = src.rows*scale;

    
    Rect cropArea(fabs(width-src.cols)/2, fabs(height-src.rows)/2, src.cols, src.rows);

    adResIm.setWidth(width);
    adResIm.setHeight(height);
    adResIm.setKeepSize(true);
    adResIm.apply(src);
}

void adScaleImage::randomInit(){
    this->scale = ((float)(rand()%devScale)+marginScale)/100.f;
}

void adScaleImage::setScale(float scale){
    this->scale = scale;
}

void adScaleImage::setMarginScale(int marginScale){
    this->marginScale = marginScale;
}

void adScaleImage::setDevScale(int devScale){
    this->devScale = devScale;
}