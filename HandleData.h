#ifndef HANDLE_DATA_H
#define HANDLE_DATA_H

#include "DataHeader.h"
#include "AugmentData.h"

class HandleData{
private:
    AugmentData augData;

    vector<Mat> data;
public:
    HandleData();
    void readSource(string path);
};

#endif