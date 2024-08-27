#ifndef LEAPMOTIONRECOGINZE_H
#define LEAPMOTIONRECOGINZE_H
#include "Adaptee.h"

class LeapMotionRecoginze: public SensorRecoginze
{
    virtual void GetData()
    {
        cout << "LeapMotion Get Data " << endl;
    }
};

class LeapMotionRecoginze2 : public SensorRecoginze2
{
    virtual void GetData()
    {
        cout << "LeapMotion Get Data " << endl;
    }
};

#endif // LEAPMOTIONRECOGINZE_H
