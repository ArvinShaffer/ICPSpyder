#ifndef GOOGLESENSOR_H
#define GOOGLESENSOR_H
#include "Adaptee.h"

class GoogleSensor : public SensorRecoginze
{
    virtual void GetData()
    {
        cout << "Google Get Data" << endl;
    }
};

class GoogleSensor2 : public SensorRecoginze2
{
    virtual void GetData()
    {
        cout << "Google Get Data" << endl;
    }
};

#endif // GOOGLESENSOR_H
