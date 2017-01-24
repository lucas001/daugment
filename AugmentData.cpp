#include "AugmentData.h"

void AugmentData::resizeImage(Mat& src, int width, int height, bool keepSize){
    Size size(width, height);
    Rect rect;
    Mat imResize;

    resize(src,imResize,size);

    Mat out;
    if(keepSize){
        out = Mat::zeros(src.rows,src.cols,src.type());
        
        if(width > src.cols && height > src.rows){
            rect = Rect(fabs(width-src.cols)/2,fabs(height-src.rows)/2,src.cols,src.rows);
            imResize(rect).copyTo(out);
        } 
        else{
            rect = Rect(fabs(width-src.cols)/2,fabs(height-src.rows)/2,width,height);
            imResize.copyTo(out(rect));
        } 
    }else{
        out = imResize;
    }

    src = out;
}

void AugmentData::applyGaussianBlur(Mat& src, int numKernels){
    if(numKernels > src.rows) numKernels = src.rows;
    if(numKernels > src.cols) numKernels = src.cols;
    Mat dst;
    for (int i=1; i<numKernels; i=i+2)
    { 
        GaussianBlur( src, dst, Size( i, i ), 2, 2 );  
    }

    src = dst;
    
}

void AugmentData::invertImage(Mat& src){
    Mat dst;               // dst must be a different Mat
    flip(src, dst, 1); 
    src = dst;
}

void AugmentData::scaleImage(Mat& src, float scale){
    int width = src.cols*scale;
    int height = src.rows*scale;

    
    Rect cropArea((width-src.cols)/2, (height-src.rows)/2, src.cols, src.rows);

    resizeImage(src,width,height,true);

    Mat dst(src,cropArea);

    src = dst;
}

void AugmentData::dropoutChannels(Mat& src,float perc, bool channels){
    Mat color(src.size(),src.type());

    int numPixelsDrop = src.cols*src.rows*perc;
    if(channels) numPixelsDrop *= 3;

    srand(time(NULL));
    for(int i = 0; i < numPixelsDrop; i++){
        int column = rand()%src.cols;
        int row = rand()%src.rows;
        
        if(channels){
            int idCh = rand()%3;
            src.at<Vec3b>(row,column)[idCh] = 0;
        }else{
            src.at<double>(row,column) = 0;
        }
    }
}

void AugmentData::addGaussianNoise(Mat& src, float meanSc, float stdDevSc, bool channels){
    Mat noise(src.size(),src.type());
    Scalar mean(meanSc);
    Scalar stdDev(stdDevSc);
    
    randn(noise,mean,stdDev);

    src += noise;
}

void AugmentData::addContBright(Mat& src, int brightness, double contrast){
    int beta = brightness;
    double alpha = contrast;
    Mat new_image = Mat::zeros(src.size(),src.type());

    for( int y = 0; y < src.rows; y++ ){
        for( int x = 0; x < src.cols; x++ ){
            for( int c = 0; c < src.channels(); c++ ){
                new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( alpha*( src.at<Vec3b>(y,x)[c] ) + beta );
            }
        }
    }

    src = new_image;
}

void AugmentData::grayScale(Mat& src, float scale){
    Mat grayMat, colorMat;
    cvtColor(src, grayMat, CV_BGR2GRAY);

    grayMat = grayMat*scale;

    src = grayMat;
}

void AugmentData::translate(Mat& src, int transX, int transY, bool keepSize){
    Mat out;
    src.copyTo(out);
    Mat M(2,3,CV_32F);


    M.at<float>(0,0) = 1;
    M.at<float>(0,1) = 0;
    M.at<float>(0,2) = transX;

    M.at<float>(1,0) = 0;
    M.at<float>(1,1) = 1;
    M.at<float>(1,2) = transY;

    warpAffine(src, out, M , Size(keepSize ? out.cols : out.cols+transX,
                (keepSize ? out.rows : out.rows +transY)));

    src = out;
}

void AugmentData::rotate(Mat& src, float angle){
    Point2f src_center(src.cols/2.0f, src.rows/2.0f);
    Mat rot_mat = getRotationMatrix2D(src_center, angle, 1.0);
    Mat dst;
    warpAffine(src, dst, rot_mat, src.size());
    src = dst;
}

void AugmentData::shearImate(Mat& src, float shearX, float shearY){
    Mat out;

    float maxYOffset = fabs(src.cols * shearY);
    float maxXOffset = fabs(src.rows * shearX);

    Mat temp;
    src.copyTo(temp);
    Mat M(2,3,CV_32F);


    M.at<float>(0,0) = 1;
    M.at<float>(0,1) = shearX;
    M.at<float>(0,2) = shearY >= 0 ? 0 : -maxYOffset*shearX;

    M.at<float>(1,0) = shearY;
    M.at<float>(1,1) = 1;
    M.at<float>(1,2) = shearX < 0 ? -maxXOffset*shearY : 0;

    if(shearX < 0) translate(temp,maxXOffset,0,false);
    if(shearY < 0) translate(temp,0,maxYOffset,false);

    warpAffine(temp, out, M , Size(shearX < 0 ? temp.cols : temp.cols+fabs(src.rows*shearX),
                (shearY < 0 ? temp.rows : temp.rows+src.cols*shearY)));

    float marginX = (out.cols - src.cols)/2;
    float marginY = (out.rows - src.rows)/2;
    Rect crop(marginX,marginY,src.cols,src.rows);

    Mat origArea(out,crop);
    src = out;
}

void AugmentData::colorIntensification(Mat& src, Vec3f unitaryChange){
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

    src = out;
}