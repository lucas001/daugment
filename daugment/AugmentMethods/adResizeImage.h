#ifndef RESIZE_IMAGE_H
#define RESIZE_IMAGE_H

#include "AugmentMethods/adAugmentMethod.h"

class adResizeImage : public adAugmentMethod{
private:
    int width;
    int height;
    bool keepSize;
public:
    adResizeImage(){};
    adResizeImage(int width, int height, bool resize = false);
    void apply(Mat& src);

    void setWidth(int width);
    void setHeight(int height);
    void setKeepSize(bool resize);

    int getWidth() { return width; };
    int getHeight() { return height; };
    int getKeepSize() { return keepSize; };
};

#endif