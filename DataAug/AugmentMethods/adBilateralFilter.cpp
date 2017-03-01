#include "AugmentMethods/adBilateralFilter.h"
    
adBilateralFilter::adBilateralFilter(int kernels, float sigmaDst, float sigmaClr, int maxKernels, float minSigClr, float maxSigClr, float minSigDst, float maxSigDst){
    this->kernels = kernels;
    this->sigmaDst = sigmaDst;
    this->sigmaClr = sigmaClr;
    this->maxKernels = maxKernels;
    this->minSigClr = minSigClr;
    this->maxSigClr = maxSigClr;
    this->minSigDst = minSigDst;
    this->maxSigDst = maxSigDst;
}

adBilateralFilter::adBilateralFilter():
adBilateralFilter(0,0,0){
    randomInit();
}

void adBilateralFilter::apply(Mat& src){
    Mat out = Mat::zeros(src.size(),src.type());
    
    cout << kernels << " " << sigmaClr << " " << sigmaDst << endl;
    for ( int i = 1; i  <  kernels; i = i + 2 ){ 
        bilateralFilter( src, out, i, sigmaClr, sigmaDst);
    }

    out.copyTo(src);
}

void adBilateralFilter::randomInit(){
    this->sigmaDst =  probParams.uniformDistribution(minSigDst,maxSigDst);
    this->sigmaClr =  probParams.uniformDistribution(minSigClr,maxSigClr);
    this->kernels =  probParams.uniformDistribution(1,maxKernels);
}

void adBilateralFilter::setSigmaDst(float sigmaDst){
    this->sigmaDst = sigmaDst;
}

void adBilateralFilter::setSigmaClr(float sigmaClr){
    this->sigmaClr = sigmaClr;
}

void adBilateralFilter::setNumKernels(int kernels){
    this->kernels = kernels;
}

void adBilateralFilter::setMaxKernels(int maxKernels){
    this->maxKernels = maxKernels;
}

void adBilateralFilter::setMinSigClr(float minSigClr){
    this->minSigClr = minSigClr;
}

void adBilateralFilter::setMaxSigClr(float maxSigClr){
    this->maxSigClr = maxSigClr;
}

void adBilateralFilter::setMinSigDst(float minSigDst){
    this->minSigDst = minSigDst;
}

void adBilateralFilter::setMaxSigDst(float maxSigDst){
    this->maxSigDst = maxSigDst;
}