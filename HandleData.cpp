#include "HandleData.h"

HandleData::HandleData(){
    readSource("./");
}

void HandleData::readSource(string path){
    Mat src = imread("./carro1.jpg");
    
    
    String pathTo(path);
    vector<String> fn;
    glob(pathTo,fn,true); // recurse
    for (size_t k=0; k<fn.size(); ++k)
    {
        Mat im = imread(fn[k]);
        if (im.empty()) continue; //only proceed if sucsessful

        //augData.resizeImage(im,32,32,false);
        data.push_back(im);
        /*stringstream concat;
        concat << "./images/carro-" << k << ".jpg";
        imwrite(concat.str(),im);*/
    }
}