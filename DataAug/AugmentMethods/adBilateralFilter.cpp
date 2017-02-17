#include "AugmentMethods/adBilateralFilter.h"
    
adBilateralFilter::adBilateralFilter(float sigmaDst, float sigmaClr, int devNormalization){
    this->sigmaDst = 3;//sigmaDst;
    this->sigmaClr = 500;//sigmaClr;
    this->devNormalization = devNormalization;
}

adBilateralFilter::adBilateralFilter():
adBilateralFilter(0,0){
    randomInit();
}

void adBilateralFilter::apply(Mat& src){
    Mat out = Mat::zeros(src.size(),src.type());
    
    for ( int i = 1; i  <  31; i = i + 2 ){ 
        bilateralFilter( src, out, i, sigmaClr, sigmaDst);
    }

    out.copyTo(src);
}

void adBilateralFilter::randomInit(){
    //this->minNorm = probParams.uniformDistribution(0,255-devNormalization);
    //this->maxNorm = minNorm + devNormalization + probParams.uniformDistribution(0,minNorm + devNormalization);
}

void adBilateralFilter::setSigmaDst(float sigmaDst){
    this->sigmaDst = sigmaDst;
}

void adBilateralFilter::setSigmaClr(float sigmaClr){
    this->sigmaClr = sigmaClr;
}

void adBilateralFilter::setDevNormalization(int devNormalization){
    this->devNormalization = devNormalization;
}