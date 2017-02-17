#include "HandleData.h"

HandleData::HandleData(){
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
    
    Mat src;
    data.at(index).copyTo(src);
    selectMethod(12,src);
    imshow("SHOW",src);
    imshow("SHOW 2",data.at(index));
    waitKey(0);
}

void HandleData::randomAugmenting(){
    
    for(int i = 0; i < data.size(); i++){
        vector<int> listAppliedTech;
        int numberTransform = rand()%12;
        for(int j = 0; j < numberTransform; j++){
            
        }
        if (find(listAppliedTech.begin(), listAppliedTech.end(), numberTransform) != listAppliedTech.end()){

        }
        listAppliedTech.push_back(numberTransform);

    }
}

void HandleData::selectMethod(int index,Mat& src){
    switch(index){
        case 0:{
            adGaussianBlur gaussBlur;
            gaussBlur.apply(src);
        }break;
        case 1:{
            adInvertImage invImg;
            invImg.apply(src);
        }break;
        case 2:{
            adScaleImage scImg;
            scImg.apply(src);
        }break;
        case 3:{
            adGaussianNoise gaussNs;
            gaussNs.apply(src);
        }break;
        case 4:{
            adDropoutChannel dropCh;
            dropCh.apply(src);
        }break;
        case 5:{
            adContBright coBr;
            coBr.apply(src);
        }break;
        case 6:{
            adGrayScale grSc;
            grSc.apply(src);
        }break;
        case 7:{
            adTranslate trans;
            trans.apply(src);
        }break;
        case 8:{
            adRotate rotImg;
            rotImg.apply(src);
        }break;
        case 9:{
            adShearImage shImg;
            shImg.apply(src);
        }break;
        case 10:{
            adColorIntensification clrItImg;
            clrItImg.apply(src);
        }break;
        case 11:{
            adNormalizeImage normImg;
            normImg.apply(src);
        }break;
        case 12:{
            adBilateralFilter biFilt;
            biFilt.apply(src);
        }break;
    }
}

void HandleData::customAugmenting(){
    
}

void HandleData::saveAugmentedData(){
    for(int i = 0; i < data.size(); i++){
        adResizeImage resImg(32,32,false);
        resImg.apply(data.at(i));
        stringstream concat;
        concat << "./images/carro-" << i << ".jpg";
        imwrite(concat.str(),data.at(i));
    }
}