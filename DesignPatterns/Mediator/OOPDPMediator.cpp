#include <iostream>
#include "Mediator.h"
using namespace std;

int main(int argc, char *argv[])
{
    ConcreMeiator mediator;

    ConcreColleague c1(&mediator, "c1");
    ConcreColleague c2(&mediator, "c2");
    ConcreColleague c3(&mediator, "c3");

    c1.Send("hello everyone");
    c2.Send("test 2");
    c3.Send("test 3");

    return 0;
}
