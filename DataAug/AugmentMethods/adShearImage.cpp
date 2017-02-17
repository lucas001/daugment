#include "AugmentMethods/adShearImage.h"
    
adShearImage::adShearImage(float shearX, float shearY, float maxShear){
    this->shearX = shearX;
    this->shearY = shearY;
    this->maxShear = maxShear;
}

adShearImage::adShearImage():
adShearImage(0,0){
    randomInit();

    //Correcting shear. If negative cuts the image
    if(shearX < 0) shearX *= -1;
    if(shearY < 0) shearY *= -1;
}

void adShearImage::apply(Mat& src){
    Mat out;

    float maxYOffset = fabs(src.cols * shearY);
    float maxXOffset = fabs(src.rows * shearX);

    Mat temp;
    src.copyTo(temp);
    Mat M(2,3,CV_32F);


    M.at<float>(0,0) = 1;
    M.at<float>(0,1) = shearX;
    M.at<float>(0,2) = 0;

    M.at<float>(1,0) = shearY;
    M.at<float>(1,1) = 1;
    M.at<float>(1,2) = 0;

    cout << maxXOffset << endl;
    cout << maxYOffset << endl;
    if(shearX < 0){
        adTrans.setTransX(maxXOffset);
        adTrans.setKeepSize(true);
        adTrans.apply(temp);
    } 
    if(shearY < 0){
        adTrans.setTransY(maxYOffset);
        adTrans.setKeepSize(true);
        adTrans.apply(temp);
    }

    warpAffine(temp, out, M , Size(shearX < 0 ? temp.cols : temp.cols+fabs(src.rows*shearX),
                shearY < 0 ? temp.rows : (temp.rows+fabs(src.cols*shearY))));

    float marginX = (out.cols - src.cols)/2;
    float marginY = (out.rows - src.rows)/2;
    Rect crop(marginX,marginY,src.cols,src.rows);

    Mat origArea(out,crop);

    out.copyTo(src);
}

void adShearImage::randomInit(){
    this->shearX = probParams.uniformDistribution(-maxShear,maxShear);
    this->shearY = probParams.uniformDistribution(-maxShear,maxShear);
}

void adShearImage::setShearX(float shearX){
    this->shearX = shearX;
}

void adShearImage::setShearY(float shearY){
    this->shearY = shearY;
}

void adShearImage::setMaxShear(float maxShear){
    this->maxShear = maxShear;
}