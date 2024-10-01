#include "ImageProcessVisitor.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    Circle circle;
    Rectangle rectangle;
    ImageProcessVisitor imageVisitor;

    circle.ExtendedFunctions(&imageVisitor);
    rectangle.ExtendedFunctions(&imageVisitor);
    return 0;
}
