#include "AugmentMethods/adResizeImage.h"

adResizeImage::adResizeImage(int width, int height, bool keepSize){
    this->width = width;
    this->height = height;
    this->keepSize = keepSize;
}

void adResizeImage::apply(Mat& src){
    Size size(width, height);
    Rect rect;
    Mat imResize;

    resize(src,imResize,size);

    Mat out;
    if(keepSize){
        out = Mat::zeros(src.rows,src.cols,src.type());
        
        if(width > src.cols && height > src.rows){
            rect = Rect(fabs(width-src.cols)/2,fabs(height-src.rows)/2,src.cols,src.rows);
            imResize(rect).copyTo(out);
        } 
        else{
            rect = Rect(fabs(width-src.cols)/2,fabs(height-src.rows)/2,width,height);
            imResize.copyTo(out(rect));
        } 
    }else{
        out = imResize;
    }

    out.copyTo(src);
}

void adResizeImage::setWidth(int width){
    this->width = width;
}

void adResizeImage::setHeight(int height){
    this->height = height;
}

void adResizeImage::setKeepSize(bool keepSize){
    this->keepSize = keepSize;
}