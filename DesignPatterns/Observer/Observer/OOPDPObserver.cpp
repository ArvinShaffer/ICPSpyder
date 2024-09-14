#include <QCoreApplication>
#include "Subject.h"
#include "Observers.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    shared_ptr<News> subject = make_shared<News>();
    shared_ptr<Observer1> ob1 = make_shared<Observer1>("Ob1");
    shared_ptr<Observer1> ob1A = make_shared<Observer1>("Ob1A");
    shared_ptr<Observer2> ob2 = make_shared<Observer2>("Ob2");
    subject->RegisterObservers(ob1);
    subject->RegisterObservers(ob1A);
    subject->RegisterObservers(ob2);

    subject->SetState("Normal State");
    subject->RemoveObservers(ob1A);
    subject->SetState("Excepted State");

    SubjectSTL subjectSTL;
    ObserverSTL1 obstl1("obstl1");
    ObserverSTL1 obstlA("obstl1A");
    ObserverSTL2 obstl2("obstl2");

    function<void(const string&)> obstl1F = [&](const string& message) {obstl1.Update(message);};
    function<void(const string&)> obstl1AF = [&](const string& message) {obstlA.Update(message);};
    function<void(const string&)> obstl2F = [&](const string& message) {obstl2.Update(message);};
    subjectSTL.RegisterObservers(obstl1F);
    subjectSTL.RegisterObservers(obstl1AF);
    subjectSTL.RegisterObservers(obstl2F);

    subjectSTL.SetState("STL Normal State");
    subjectSTL.RemoveObservers(obstl1AF);
    subjectSTL.SetState("STL Excepted State");


    return a.exec();
}
