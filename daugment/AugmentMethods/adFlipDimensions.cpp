#include "AugmentMethods/adFlipDimensions.h"

adFlipDimensions::adFlipDimensions(vector<int> vecFlip){
    this->vecFlip = vecFlip;
}

adFlipDimensions::adFlipDimensions(){
    randomInit();
}

void adFlipDimensions::apply(Mat& src){
    if(src.channels() == 1) return;
    Mat out[3];
    Mat splitMat[3];

    split(src,splitMat);

    for(int i = 0; i < 3; i++){
        out[i] = splitMat[vecFlip.at(i)];
    }

    merge(out, 3, src);
}

void adFlipDimensions::randomInit(){
    this->vecFlip.clear();
    for(int i = 0; i < 3; i++){
        this->vecFlip.push_back(probParams.uniformDistribution(0,3));
    }
}

void adFlipDimensions::setVecFlip(vector<int> vecFlip){
    this->vecFlip = vecFlip;
}