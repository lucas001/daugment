#include "AugmentMethods/adGaussianBlur.h"

adGaussianBlur::adGaussianBlur(int minNumKGauss, int maxNumKGauss, float sigmaX, float sigmaY){
    this->minNumKGauss = minNumKGauss;
    this->maxNumKGauss = maxNumKGauss;
    this->sigmaY = sigmaY;
    this->sigmaX = sigmaX;

    this->numKernels = 0;
}

void adGaussianBlur::randomInit(){
    this->numKernels = (int)(rand()%maxNumKGauss);
    if(numKernels < minNumKGauss) this->numKernels = minNumKGauss;
}

void adGaussianBlur::apply(Mat& src){
    if(numKernels == 0) randomInit();

    if(numKernels > src.rows) numKernels = src.rows;
    if(numKernels > src.cols) numKernels = src.cols;
    Mat dst = Mat::zeros(src.size(), src.type());
    
    for (int i=1; i<numKernels; i=i++)
    { 
        GaussianBlur( src, dst, Size( i, i ), sigmaX, sigmaY );  
    }

    dst.copyTo(src);
}