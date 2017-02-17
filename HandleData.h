#ifndef HANDLE_DATA_H
#define HANDLE_DATA_H

#include "adDataHeader.h"

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
#include "AugmentMethods/adBilateralFilter.h"

class HandleData{
private:
    vector<Mat> data;

    void randomAugmenting();
    void selectMethod(int index,Mat& src);
    void customAugmenting();
    void saveAugmentedData();
public:
    HandleData();
    void readSource(string path);
};

#endif