#include "HandleData.h"

HandleData::HandleData(string path){
    readSource(path);
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

    randomAugmenting();
}

void HandleData::randomAugmenting(){
    vector<adAugmentMethod*> listMethods;
    vector<int> attachedMethods;
    int numMethods = round(probParams.uniformDistribution(0,15));
    for(int i = 0; i < numMethods; i++){
        int idMethod = round(probParams.uniformDistribution(0,15));
        if(!(find(attachedMethods.begin(), attachedMethods.end(), idMethod) != attachedMethods.end())){
            listMethods.push_back(getMethod(idMethod));
            attachedMethods.push_back(idMethod);
        }else{
            i--;
        }
    }

    executeMethods(listMethods);
    
    saveAugmentedData();
}

void HandleData::executeMethods(vector<adAugmentMethod*> listMethods){
    for(int i = 0; i < data.size(); i++){
        int numberTransform = round(probParams.uniformDistribution(0,listMethods.size()));
        listMethods.at(numberTransform)->apply(data.at(i));
    }
}

adAugmentMethod* HandleData::getMethod(int index){
    switch(index){
        case 0:{
            return new adGaussianBlur();
        }break;
        case 1:{
            return new adInvertImage();
        }break;
        case 2:{
            return new adScaleImage();
        }break;
        case 3:{
            return new adGaussianNoise();
        }break;
        case 4:{
            return new adDropoutChannel();
        }break;
        case 5:{
            return new adContBright();
        }break;
        case 6:{
            return new adGrayScale();
        }break;
        case 7:{
            return new adTranslate();
        }break;
        case 8:{
            return new adRotate();
        }break;
        case 9:{
            return new adShearImage();
        }break;
        case 10:{
            return new adColorIntensification();
        }break;
        case 11:{
            return new adNormalizeImage();
        }break;
        case 12:{
            return new adBilateralFilter();
        }break;
        case 13:{
            return new adCannyEdge();
        }break;
        case 14:{
            return new adFlipDimensions();
        }break;
        case 15:{
            return new adInvertColors();
        }break;
    }
}

void HandleData::saveAugmentedData(){
    for(int i = 0; i < data.size(); i++){
        //adResizeImage resImg(180,130,false);
        //resImg.apply(data.at(i));
        stringstream concat;
        concat << "./onca-" << i << ".jpg";
        imwrite(concat.str(),data.at(i));
    }
}