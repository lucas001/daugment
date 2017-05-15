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
#include "AugmentMethods/adCannyEdge.h"
#include "AugmentMethods/adFlipDimensions.h"
#include "AugmentMethods/adInvertColors.h"
#include "adProbabilityParams.h"

class HandleData{
private:
    vector<Mat> data;

    adProbabilityParams probParams;

    void randomAugmenting();
    void executeMethods(vector<adAugmentMethod*> index);
    adAugmentMethod* getMethod(int index);
    void customAugmenting();
    void saveAugmentedData();
public:
    HandleData(string path);
    void readSource(string path);
};

#endif