#include "AugmentMethods/adTranslate.h"
    
adTranslate::adTranslate(float transX, float transY, float percTrans, int maxPercTrans, bool keepSize){
    this->transX = transX;
    this->transY = transY;
    this->percTrans = percTrans;
    this->maxPercTrans = maxPercTrans;
    this->keepSize = keepSize;

    this->percTrans = 1;
    this->randInit = false;
}

void adTranslate::apply(Mat& src){

    transX = src.cols*percTrans;
    transY = src.rows*percTrans;

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
    percTrans = (float)(rand()%maxPercTrans)/100.f;
    randInit = true;
}

void adTranslate::setTransX(float transX){
    this->transX = transX;
}

void adTranslate::setTransY(float transY){
    this->transY = transY;
}

void adTranslate::setPercTrans(float percTrans){
    this->percTrans = percTrans;
}

void adTranslate::setMaxPercTrans(int maxPercTrans){
    this->maxPercTrans = maxPercTrans;
}

void adTranslate::setKeepSize(bool keepSize){
    this->keepSize = keepSize;
}