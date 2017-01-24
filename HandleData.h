#ifndef HANDLE_DATA_H
#define HANDLE_DATA_H

#include "DataHeader.h"
#include "AugmentData.h"

class HandleData{
private:
    AugmentData augData;

    vector<Mat> data;

    float marginScale;
    int maxPercTrans;
    int maxAngRot;
    int maxNumKGauss;
    int minNumKGauss;
    int devScale;
    int gaussMaxMean;
    int gaussMaxStd;
    int maxDevBrightness;
    int maxContrast;
    int maxShear;
    int maxIntensColor;

    void randomAugmenting();
    void selectMethod(int index,Mat& src);
    void customAugmenting();
    void saveAugmentedData();
public:
    HandleData();
    void readSource(string path);
};

#endif