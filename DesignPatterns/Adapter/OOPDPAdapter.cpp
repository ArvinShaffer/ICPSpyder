#include <QCoreApplication>
#include <iostream>
#include "MSSensor.h"
#include "GoogleSensor.h"
#include "LeapMotionRecoginze.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Class Adapter pattern
    std::shared_ptr<MSSensor> msSensor1 = make_shared<MSSensor>();
    msSensor1->GetDataAndRecognize();

    std::shared_ptr<GoogleSensor> msSensor2 = make_shared<GoogleSensor>();
    msSensor2->GetDataAndRecognize();

    // Object Adapter pattern
    std::shared_ptr<LeapMotionRecoginze2> msSensor3 = make_shared<LeapMotionRecoginze2>();
    msSensor3->GetDataAndRecognize();

    return a.exec();
}
