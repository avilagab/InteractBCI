#ifndef BCIDATA_H
#define BCIDATA_H
#include "vector"
#include "queue"

using namespace std;

class BCIData
{
public:
    BCIData();
    BCIData(int k);
    ~BCIData();
    //ModificarDatos
    void setSamplesSize(unsigned int s);
    void setData(int p, double d);
    void addToBuffer(vector<double> d);

    //ObtenerDatos
    int getSamplesSize();
    double getData(int p);
    vector<double> getCurrentData();
    vector<double> getBufferBack();
    queue< vector<double> > getBuffer();

    //Densidad de Potencia
    vector< vector <double> > PowerDensity();
private:
    unsigned int samples;
    vector<double> currentData;
    queue< vector<double> > sampleQueue;

    float * data[15];

};

#endif // BCIDATA_H
