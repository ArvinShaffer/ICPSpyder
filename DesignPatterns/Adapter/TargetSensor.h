#ifndef TARGETSENSOR_H
#define TARGETSENSOR_H
// Google, MS, Apple, Leap Motion...
class TargetSensor
{
public:
    virtual void GetData() = 0;
};

#endif // TARGETSENSOR_H
