#ifndef HANDLE_DATA_H
#define HANDLE_DATA_H

#include "adDataHeader.h"
#include "AugmentData.h"

#include "AugmentMethods/adColorIntensification.h"
#include "AugmentMethods/adContBright.h"
#include "AugmentMethods/adDropoutChannel.h"
#include "AugmentMethods/adGaussianBlur.h"
#include "AugmentMethods/adGaussianNoise.h"
#include "AugmentMethods/adGrayScale.h"
#include "AugmentMethods/adInvertImage.h"
#include "AugmentMethods/adNormalizeImage.h"
#include "AugmentMethods/adResizeImage.h"
#include "AugmentMethods/adRotate.h"
#include "AugmentMethods/adScaleImage.h"
#include "AugmentMethods/adShearImage.h"
#include "AugmentMethods/adTranslate.h"

class HandleData{
private:
    AugmentData augData;

    vector<Mat> data;

    float marginScale;
    float maxShear;
    float maxIntensColor;
    int maxPercTrans;
    int maxAngRot;
    int maxNumKGauss;
    int minNumKGauss;
    int devScale;
    int gaussMaxMean;
    int gaussMaxStd;
    int maxDevBrightness;
    int maxContrast;
    int marginContrast;
    int marginDropout;
    int devDropout;
    int devNormalization;

    void randomAugmenting();
    void selectMethod(int index,Mat& src);
    void customAugmenting();
    void saveAugmentedData();
public:
    HandleData();
    void readSource(string path);
};

#endif