#ifndef PROTOTYPE_H
#define PROTOTYPE_H
#include <iostream>
#include <memory>
using namespace std;
class Prototype
{
public:
    virtual std::shared_ptr<Prototype> Clone() const = 0;
    virtual void PrintTypeInfo() const = 0;
};

#endif // PROTOTYPE_H
