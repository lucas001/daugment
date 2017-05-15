#include "AugmentMethods/adNormalizeImage.h"
    
adNormalizeImage::adNormalizeImage(float maxNorm, float minNorm, int devNormalization){
    this->maxNorm = maxNorm;
    this->minNorm = minNorm;
    this->devNormalization = devNormalization;
}

adNormalizeImage::adNormalizeImage():
adNormalizeImage(0,0){
    randomInit();
}

void adNormalizeImage::apply(Mat& src){
    Mat out = Mat::zeros(src.size(),src.type());
    
    normalize(src, out, minNorm, maxNorm, NORM_MINMAX, src.type());

    out.copyTo(src);
}

void adNormalizeImage::randomInit(){
    this->minNorm = probParams.uniformDistribution(0,255-devNormalization);
    this->maxNorm = minNorm + devNormalization + probParams.uniformDistribution(0,minNorm + devNormalization);
}

void adNormalizeImage::setMaxNorm(float maxNorm){
    this->maxNorm = maxNorm;
}

void adNormalizeImage::setMinNorm(float minNorm){
    this->minNorm = minNorm;
}

void adNormalizeImage::setDevNormalization(int devNormalization){
    this->devNormalization = devNormalization;
}