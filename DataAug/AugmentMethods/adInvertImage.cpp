#include "AugmentMethods/adInvertImage.h"
    
adInvertImage::adInvertImage(bool flipLr, bool flipUd){
    this->flipLr = flipLr;
    this->flipUd = flipUd;
}

void adInvertImage::apply(Mat& src){
    Mat dst = Mat::zeros(src.size(), src.type());

    int flipSt = 0;
    if(flipLr) flipSt = 1;
    if(flipUd) flipSt = 0;
    if(flipUd && flipLr) flipSt = -1;

    if(flipLr || flipUd) flip(src, dst, flipSt); 

    dst.copyTo(src);
}

void adInvertImage::randomInit(){
    
}

void adInvertImage::setFlipUd(bool flipUd){
    this->flipUd = flipUd;
}

void adInvertImage::setFlipLr(bool flipLr){
    this->flipLr = flipLr;
}