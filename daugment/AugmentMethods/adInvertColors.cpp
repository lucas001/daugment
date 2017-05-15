#include "AugmentMethods/adInvertColors.h"

adInvertColors::adInvertColors(vector<int> vecInv){
    this->vecInv = vecInv;
}

adInvertColors::adInvertColors(){
    randomInit();
}

void adInvertColors::apply(Mat& src){
    Mat out[3];
    Mat splitMat[3];

    split(src,splitMat);

    for(int i = 0; i < 3; i++){
        splitMat[i].copyTo(out[i]);
    }
    
    for(int i = 0; i < vecInv.size(); i++){
        out[vecInv.at(i)] = 255-splitMat[vecInv.at(i)];
    }

    merge(out, 3, src);
}

void adInvertColors::randomInit(){
    this->vecInv.clear();
    int numIt = round(probParams.uniformDistribution(1,3));
    //cout << probParams.uniformDistribution(1,3) << endl;
    for(int i = 0; i < numIt; i++){
        int ch = round(probParams.uniformDistribution(0,2));
        if(!(find(vecInv.begin(), vecInv.end(), ch) != vecInv.end())){
            vecInv.push_back(ch);
        }else{
            i--;
        }
    }
}

void adInvertColors::setVecInv(vector<int> vecInv){
    this->vecInv = vecInv;
}