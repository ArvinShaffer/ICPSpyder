#ifndef ADAPTEE_H
#define ADAPTEE_H
#include "TargetSensor.h"
#include <iostream>
#include <memory>
using namespace std;
// Stable recognition algorithm
class Adaptee
{
public:
    void Recognize()
    {
        cout << " Recognize... " << endl;
    }
};

// Class Adapter Pattern
class SensorRecoginze : public TargetSensor, public Adaptee
{
public:
    virtual void GetDataAndRecognize()
    {
        GetData();
        Recognize();
    }
};
// Composition instead of inheritance -->> Object Adapter pattern
class SensorRecoginze2 : public TargetSensor
{
public:
    SensorRecoginze2() : m_adaptee(make_shared<Adaptee>()) {}
    virtual void GetDataAndRecognize()
    {
        GetData();
        m_adaptee->Recognize();
    }
    virtual ~SensorRecoginze2()
    {
        cout << "~SensorRecoginze2" << endl;
    }
private:
    std::shared_ptr<Adaptee> m_adaptee;
};

#endif // ADAPTEE_H
