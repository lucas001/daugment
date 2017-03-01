#include "AugmentMethods/adCannyEdge.h"
    
adCannyEdge::adCannyEdge(){
    randomInit();
}

void adCannyEdge::apply(Mat& src){
    Mat out = Mat::zeros(src.size(),src.type());
    Mat gray;
    Scalar mean, stdDev;

    cvtColor(src,gray,CV_BGR2GRAY);
    meanStdDev(gray,mean,stdDev);
    Canny(gray, out,mean.val[0]-stdDev.val[0]*0.5,mean.val[0]+stdDev.val[0]*0.5);

    out.copyTo(src);
}

void adCannyEdge::randomInit(){
    //Variables implementation for extract edges
}