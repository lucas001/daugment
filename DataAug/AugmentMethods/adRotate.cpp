#include "AugmentMethods/adRotate.h"
    
adRotate::adRotate(int angle, int maxAngRot){
    this->angle = angle;
    this->maxAngRot = maxAngRot;
}

adRotate::adRotate():
adRotate(0){
    randomInit();
}

void adRotate::apply(Mat& src){
    Point2f src_center(src.cols/2.0f, src.rows/2.0f);
    Mat rot_mat = getRotationMatrix2D(src_center, angle, 1.0);
    Mat dst;
    warpAffine(src, dst, rot_mat, src.size());

    dst.copyTo(src);
}

void adRotate::randomInit(){
    this->angle = probParams.uniformDistribution(-maxAngRot,maxAngRot);
}

void adRotate::setAngle(int angle){
    this->angle = angle;
}

void adRotate::setMaxAngle(int maxAngle){
    this->maxAngRot = maxAngle;
}