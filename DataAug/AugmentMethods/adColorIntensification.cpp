#include "AugmentMethods/adColorIntensification.h"
    
adColorIntensification::adColorIntensification(Vec3f unitaryChange, float maxIntensColor){
    this->maxIntensColor = maxIntensColor;
    this->unitaryChange = unitaryChange;
}

adColorIntensification::adColorIntensification():
adColorIntensification(Vec3f(0,0,0)){
    randomInit();
}

void adColorIntensification::apply(Mat& src){
    if(src.channels() == 1){
        cout << "Gray image. Use contrast and brightness method instead." << endl;
        return;
    } 

    Mat out = Mat::zeros(src.size(),src.type());

    for( int y = 0; y < src.rows; y++ ){
        for( int x = 0; x < src.cols; x++ ){
            for( int c = 0; c < src.channels(); c++ ){
                out.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( unitaryChange[c]*( src.at<Vec3b>(y,x)[c] ) );
            }
        }
    }

    out.copyTo(src);
}

void adColorIntensification::randomInit(){
    float unit[3];
    for(int i = 0; i < 3; i++){
        unit[i] = probParams.uniformDistribution(0,maxIntensColor);
    }
    this->unitaryChange = Vec3f(unit[0],unit[1],unit[2]);
}

void adColorIntensification::setUnitaryChange(Vec3f unitaryChange){
    this->unitaryChange = unitaryChange;
}

void adColorIntensification::setMaxIntensColor(float maxIntensColor){
    this->maxIntensColor = maxIntensColor;
}