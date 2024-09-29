#ifndef ITERATOR_H
#define ITERATOR_H
#include <memory>
template<typename T>
class Iterator
{
public:
    virtual bool HasNext() const = 0;
    virtual T Next() = 0;
    virtual bool HasPrev() const = 0;
    virtual T Prev() = 0;
};

#endif // ITERATOR_H
