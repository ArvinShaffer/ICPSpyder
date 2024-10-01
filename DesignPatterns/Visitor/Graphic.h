#ifndef GRAPHIC_H
#define GRAPHIC_H
#include <iostream>
using namespace std;

class Visitor;
class Circle;
class Rectangle;

class Graphic
{
public:
    virtual void Draw() = 0;
    virtual void ExtendedFunctions(Visitor* v) = 0;
};

class Visitor
{
public:
    virtual void Visit(Circle* circle) = 0;   // overload
    virtual void Visit(Rectangle* rect) = 0;  // overload
};

class Circle :public Graphic
{
public:
    virtual void Draw()
    {
        cout << "Cricle Draw " << endl;
    }
    virtual void ExtendedFunctions(Visitor* v)
    {
        v->Visit(this);
    }
};


class Rectangle : public Graphic
{
public:
    virtual void Draw()
    {
        cout << "Rectangle Draw " << endl;
    }

    virtual void ExtendedFunctions(Visitor* v)
    {
        v->Visit(this);
    }
};

#endif // GRAPHIC_H
