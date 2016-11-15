#include "bcidata.h"
#include "DspFilters/Dsp.h"

BCIData::BCIData()
{
    this->samples = 128;
    for(int i=0; i<15; i++)
    {
        this->currentData.push_back(0);
    }

    for(int i=0; i<15; i++)
    {
        data[i] = new float[this->getSamplesSize()];
    }
}

BCIData::BCIData(int k){
    for(int i=0; i<k; i++)
    {
        this->currentData.push_back(0);
    }
}

BCIData::~BCIData()
{}

void BCIData::setSamplesSize(unsigned int s){
    this->samples = s;
}

void BCIData::setData(int p, double d){
    this->currentData[p] = d;
}

void BCIData::addToBuffer(vector<double> d){
    if(this->sampleQueue.size() >= this->getSamplesSize())
    {
        this->sampleQueue.pop();
    }
    this->sampleQueue.push(d);
}

int BCIData::getSamplesSize(){
    return this->samples;
}

double BCIData::getData(int p){
    return this->currentData[p];
}

vector<double> BCIData::getCurrentData(){
    return this->currentData;
}

vector<double> BCIData::getBufferBack(){
    return this->sampleQueue.back();
}

queue< vector<double> > BCIData::getBuffer(){
    return this->sampleQueue;
}

void setFilter(){
}

vector<double> BCIData::filterBuffer(){
    return this->currentData;
}
