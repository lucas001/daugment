#include "AugmentMethods/adGaussianBlur.h"

adGaussianBlur::adGaussianBlur(int numKer, int minNumKG, int maxNumKG, float sigX, float sigY, float maxDevSig){
    
    this->numKernels = numKer;
    this->minNumKGauss = minNumKG;
    this->maxNumKGauss = maxNumKG;
    this->sigmaY = sigY;
    this->sigmaX = sigX;
    this->maxDevSigma = maxDevSig;
}

adGaussianBlur::adGaussianBlur(int minNumKG, int maxNumKG, float sigX, float sigY, float maxDevSig) : 
adGaussianBlur(0, minNumKG, maxNumKG, sigX, sigY, maxDevSig){
    randomInit();
}

void adGaussianBlur::randomInit(){
    this->numKernels = probParams.uniformDistribution(0, maxNumKGauss);
    if(numKernels < minNumKGauss) this->numKernels = minNumKGauss;
    
    sigmaX = probParams.uniformDistribution(0,maxDevSigma);
    sigmaY = probParams.uniformDistribution(0,maxDevSigma);
}

void adGaussianBlur::apply(Mat& src){

    if(numKernels > src.rows) numKernels = src.rows;
    if(numKernels > src.cols) numKernels = src.cols;
    Mat dst = Mat::zeros(src.size(), src.type());
    
    for (int i=1; i<numKernels; i+=2){ 
        GaussianBlur( src, dst, Size( i, i ), sigmaX, sigmaY );  
    }

    dst.copyTo(src);
}

void adGaussianBlur::setMaxKGauss(int maxNumKGauss){
    this->maxNumKGauss = maxNumKGauss;
}

void adGaussianBlur::setMinKGauss(int minNumKGauss){
    this->minNumKGauss = minNumKGauss;
}

void adGaussianBlur::setNumKernels(int numKernels){
    this->numKernels = numKernels;
}

void adGaussianBlur::setSigmaX(float sigmaX){
    this->sigmaX = sigmaX;
}

void adGaussianBlur::setSigmaY(float sigmaY){
    this->sigmaY = sigmaY;
}

void adGaussianBlur::setMaxDevSigma(float maxDevSigma){
    this->maxDevSigma = maxDevSigma;
}