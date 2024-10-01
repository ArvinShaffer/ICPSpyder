#ifndef IMAGEPROCESSVISITOR_H
#define IMAGEPROCESSVISITOR_H
#include "Graphic.h"

class ImageProcessVisitor : public Visitor
{
public: // double dispatch: override and overload
    virtual void Visit(Circle* circle)
    {
        circle->Draw();
    }

    virtual void Visit(Rectangle* rect)
    {
        rect->Draw();
    }
};

#endif // IMAGEPROCESSVISITOR_H
