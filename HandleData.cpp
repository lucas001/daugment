#include "HandleData.h"

HandleData::HandleData(){
    srand(time(NULL));

    maxPercTrans = 30;
    maxNumKGauss = 100;
    minNumKGauss = 20;
    marginScale = 80;
    devScale = 40;
    gaussMaxMean = 4;
    gaussMaxStd = 4;
    maxDevBrightness = 1;
    maxContrast = 2;
    maxAngRot = 25;
    maxShear = 0.2;
    maxIntensColor = 0.5;

    readSource("./");
}

void HandleData::readSource(string path){
    String pathTo(path);
    vector<String> fn;
    glob(pathTo,fn,true); // recurse
    for (size_t k=0; k<fn.size(); ++k)
    {
        Mat im = imread(fn[k]);
        if (im.empty()) continue; 
        data.push_back(im);
    }

    int index = rand()%data.size();
    
    Mat src = data.at(index);
    selectMethod(0,src);
    imshow("SHOW",src);
    waitKey(0);
}

void HandleData::randomAugmenting(){
    for(int i = 0; i < data.size(); i++){

    }
}

void HandleData::selectMethod(int index,Mat& src){
    switch(index){
        case 0:{
            float numKernels = (int)(rand()%maxNumKGauss);
            if(numKernels < minNumKGauss) numKernels = minNumKGauss;

            augData.applyGaussianBlur(src, numKernels);
        }break;
        case 1:{
            augData.invertImage(src);
        }break;
        case 2:{
            float scale = ((float)(rand()%devScale)+marginScale)/100.f;
            augData.scaleImage(src, scale);
        }break;
        case 3:{
            float meanSc = (float)(rand()%gaussMaxMean*100)/100.f;
            float stdDevSc = (float)(rand()%gaussMaxStd*100)/100.f;
            
            bool doChannels = (rand()%100 < 50) ? true : false;
            if(src.channels() == 1) doChannels = false;

            augData.addGaussianNoise(src, meanSc, stdDevSc, doChannels);
        }break;
        case 4:{
            float perc = ((float)(rand()%50)+50)/100.f;
            bool doChannels = (rand()%100 < 50) ? true : false;
            if(src.channels() == 1) doChannels = false;

            augData.dropoutChannels(src, perc, doChannels);
        }break;
        case 5:{
            int brightness = rand()%maxDevBrightness;
            brightness -= rand()%maxDevBrightness;
            float contrast = (float)(rand()%maxContrast*100)/100.f;

            augData.addContBright(src, brightness, contrast);
        }break;
        case 6:{
            float scale = (float)(rand()%100)/100.f;

            augData.grayScale(src, scale);
        }break;
        case 7:{
            float transX = src.cols*(float)(rand()%maxPercTrans)/100.f;
            float transY = src.rows*(float)(rand()%maxPercTrans)/100.f;
            
            augData.translate(src, transX, transY, true);
        }break;
        case 8:{
            float angle = rand()%maxAngRot;
            
            augData.rotate(src, angle);
        }break;
        case 9:{
            float shearX = (float)(rand()%maxShear*100.f)/100.f;
            float shearY = (float)(rand()%maxShear*100.f)/100.f;
            
            augData.shearImate(src, shearX, shearY);
        }break;
        case 10:{
            float unit[3];
            for(int i = 0; i < 3; i++){
                unit[i] = (float)(rand()%maxIntensColor*100.f)/100.f;
            }
            Vec3f unitaryChange(unit[0],unit[1],unit[2]);

            augData.colorIntensification(src, unitaryChange);
        }break;
    }
}

void HandleData::customAugmenting(){
    
}

void HandleData::saveAugmentedData(){
    for(int i = 0; i < data.size(); i++){
        augData.resizeImage(data.at(i),32,32,false);
        stringstream concat;
        concat << "./images/carro-" << i << ".jpg";
        imwrite(concat.str(),data.at(i));
    }
}