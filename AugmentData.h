#ifndef AUGMENT_DATA_H
#define AUGMENT_DATA_H

#include "adDataHeader.h"

class AugmentData{
private:
public:
    AugmentData(){}
    void resizeImage(Mat& src, int width, int height, bool keepSize);
    void applyGaussianBlur(Mat& src, int numKernels);
    void invertImage(Mat& src);
    void scaleImage(Mat& src, float scale);
    void addGaussianNoise(Mat& src, float meanSc, float stdDevSc, bool channels);
    void dropoutChannels(Mat& src,float perc, bool channels=false);
    void addContBright(Mat& src, int brightness, double contrast);
    void grayScale(Mat& src, float scale);
    void translate(Mat& src, int transX, int transY, bool keepSize);
    void rotate(Mat& src, float angle);
    void shearImate(Mat& src, float shearX, float shearY);
    void colorIntensification(Mat& src, Vec3f unitaryChange);
    void normalizeImage(Mat& src, float minNorm, float maxNorm);
    void laplaceTransform(Mat& src);
};

#endif