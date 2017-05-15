# daugment
Daugment is a C++ suport library for augmenting data from image samples. It takes images from a folder and can apply a variety of augmenting methods on them.

| Method        | Result        |
| ------------- |:-------------:|
| adGaussianBlur()| ![Method-0](https://github.com/lucasbsimao/daugment/blob/master/example/samples/methods/onca-0.jpg) |
| adInvertImage()      | ![Method-1](https://github.com/lucasbsimao/daugment/blob/master/example/samples/methods/onca-1.jpg)      |
| adScaleImage()      | ![Method-2](https://github.com/lucasbsimao/daugment/blob/master/example/samples/methods/onca-2.jpg)      |
| adGaussianNoise()     | ![Method-3](https://github.com/lucasbsimao/daugment/blob/master/example/samples/methods/onca-3.jpg)      |
| adDropoutChannel()      | ![Method-4](https://github.com/lucasbsimao/daugment/blob/master/example/samples/methods/onca-4.jpg)      |
| adContBright()     | ![Method-5](https://github.com/lucasbsimao/daugment/blob/master/example/samples/methods/onca-5.jpg)      |
| adGrayScale()      | ![Method-6](https://github.com/lucasbsimao/daugment/blob/master/example/samples/methods/onca-6.jpg)      |
| adTranslate()      | ![Method-7](https://github.com/lucasbsimao/daugment/blob/master/example/samples/methods/onca-7.jpg)      |
| adRotate()      | ![Method-8](https://github.com/lucasbsimao/daugment/blob/master/example/samples/methods/onca-8.jpg)      |
| adShearImage()      | ![Method-9](https://github.com/lucasbsimao/daugment/blob/master/example/samples/methods/onca-9.jpg)      |
| adColorIntensification()      | ![Method-10](https://github.com/lucasbsimao/daugment/blob/master/example/samples/methods/onca-10.jpg)      |
| adNormalizeImage()      | ![Method-10](https://github.com/lucasbsimao/daugment/blob/master/example/samples/methods/onca-11.jpg)      |
| adBilateralFilter()      | ![Method-10](https://github.com/lucasbsimao/daugment/blob/master/example/samples/methods/onca-12.jpg)      |
| adCannyEdge()      | ![Method-10](https://github.com/lucasbsimao/daugment/blob/master/example/samples/methods/onca-13.jpg)      |
| adFlipDimensions()      | ![Method-10](https://github.com/lucasbsimao/daugment/blob/master/example/samples/methods/onca-14.jpg)      |
| adInvertColors()     | ![Method-10](https://github.com/lucasbsimao/daugment/blob/master/example/samples/methods/onca-15.jpg)      |

# Examples

The library can apply argmentation by random or in sequence.

For random transformations, as seen in example folder, you can get results like shown below.

![Method-0](https://github.com/lucasbsimao/daugment/blob/master/example/samples/random/onca-0.jpg)
![Method-1](https://github.com/lucasbsimao/daugment/blob/master/example/samples/random/onca-1.jpg)
![Method-2](https://github.com/lucasbsimao/daugment/blob/master/example/samples/random/onca-2.jpg)
![Method-3](https://github.com/lucasbsimao/daugment/blob/master/example/samples/random/onca-3.jpg)
![Method-4](https://github.com/lucasbsimao/daugment/blob/master/example/samples/random/onca-4.jpg)
![Method-5](https://github.com/lucasbsimao/daugment/blob/master/example/samples/random/onca-7.jpg)
![Method-6](https://github.com/lucasbsimao/daugment/blob/master/example/samples/random/onca-9.jpg)
![Method-7](https://github.com/lucasbsimao/daugment/blob/master/example/samples/random/onca-12.jpg)

All methods have encapsulation to set values for required transformations. So you can apply specific transformations too, like examples below.

* ## For Bilateral Filter

    ```c++
    adBilateralFilter bil = new adBilateralFilter();
    bil->setSigmaClr(float sigmaClr);
    bil->setSigmaDst(float sigmaDst);
    bil->setNumKernels(int kernels);
    bil->setMaxKernels(int maxKernels);
    bil->setMinSigClr(float minSigClr);
    bil->setMaxSigClr(float maxSigClr);
    bil->setMinSigDst(float minSigDst);
    bil->setMaxSigDst(float maxSigDst);
    bil->apply(Mat cpImg);
    ```

    or

    ```c++
    adBilateralFilter bil = new adBilateralFilter(int kernels, float sigmaDst, float sigmaClr,
        int maxKernels = 80, float minSigClr = 10, float maxSigClr = 120, float minSigDst = 5, float maxSigDst = 100);
    bil->apply(Mat cpImg);
    ```

* ## For Rotation

    ```c++
    adRotate rot = new Rotate();
    rot->setAngle(int angle);
    rot->setMaxAngle(int maxAngle);
    rot->apply(Mat cpImg);
    ```

    or

    ```c++
    adRotate rot = new Rotate(int angle, int maxAngRot = 25);
    rot->apply(Mat cpImg);
    ```

* ## For Contrast and Brightness

    ```c++
    adContBright cb = new adContBright();
    cb->setBrightness(int brightness);
    cb->setContrast(float contrast);
    cb->setMaxBrightness(int maxBrightness);
    cb->setMinBrightness(int minBrightness);
    cb->setMaxContrast(float maxContrast);
    cb->setMinContrast(float minContrast);
    cb->setMinSigDst(float minSigDst);
    cb->setMaxSigDst(float maxSigDst);
    cb->apply(Mat cpImg);
    ```

    or

    ```c++
    adContBright cb = new adContBright(int brightness, double contrast, int minBrightness = 50,
        int maxBrightness = 150, float maxContrast = 150, float minContrast = 50);
    cb->apply(Mat cpImg);
    ```

# Requirements and Instalation

Daugment only requires openCV for C++.

* Opencv - sudo apt-get install libopencv-dev




