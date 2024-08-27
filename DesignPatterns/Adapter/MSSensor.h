#ifndef MSSENSOR_H
#define MSSENSOR_H
#include "Adaptee.h"

class MSSensor: public SensorRecoginze
{
    virtual void GetData()
    {
        cout << "MS Get Data " << endl;
    }
};

class MSSensor2 : public SensorRecoginze2
{
    virtual void GetData()
    {
        cout << "MS Get Data " << endl;
    }
};

#endif // MSSENSOR_H
