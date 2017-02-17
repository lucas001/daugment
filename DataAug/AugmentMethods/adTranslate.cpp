#include "AugmentMethods/adTranslate.h"
    
adTranslate::adTranslate(float transX, float transY, float maxPercTrans, bool keepSize){
    this->transX = transX;
    this->transY = transY;
    this->maxPercTrans = maxPercTrans;
    this->keepSize = keepSize;

    this->isRandInit = false;
    this->percX = 0;
    this->percY = 0;
}

adTranslate::adTranslate():
adTranslate(0,0){
    randomInit();
}

void adTranslate::apply(Mat& src){


    transX = isRandInit ? src.cols*(percX) : transX;
    transY = isRandInit ? src.rows*(percY) : transY;

    Mat out;
    src.copyTo(out);
    Mat M(2,3,CV_32F);


    M.at<float>(0,0) = 1;
    M.at<float>(0,1) = 0;
    M.at<float>(0,2) = transX;

    M.at<float>(1,0) = 0;
    M.at<float>(1,1) = 1;
    M.at<float>(1,2) = transY;

    warpAffine(src, out, M , Size(keepSize ? out.cols : out.cols+transX,
                (keepSize ? out.rows : out.rows +transY)));

    out.copyTo(src);
}

void adTranslate::randomInit(){
    isRandInit = true;
    percX = probParams.uniformDistribution(-maxPercTrans,maxPercTrans);
    percY = probParams.uniformDistribution(-maxPercTrans,maxPercTrans);
}

void adTranslate::setTransX(float transX){
    isRandInit = false;
    this->transX = transX;
}

void adTranslate::setTransY(float transY){
    isRandInit = false;
    this->transY = transY;
}

void adTranslate::setMaxPercTrans(float maxPercTrans){
    this->maxPercTrans = maxPercTrans;
}

void adTranslate::setKeepSize(bool keepSize){
    this->keepSize = keepSize;
}