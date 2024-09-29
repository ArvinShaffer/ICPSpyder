#ifndef ARRAYITERATOR_H
#define ARRAYITERATOR_H
#include <stdexcept>
#include "Iterator.h"

template<typename T>
class ArrayIterator : public Iterator<T>
{
public:
    ArrayIterator(T* collection, unsigned int collectionSize) :m_data(collection),m_size(collectionSize), m_current(0) {}

    virtual bool HasNext() const
    {
        return m_current < m_size;
    }

    virtual T Next()
    {
        if (!HasNext())
        {
            throw std::out_of_range("Iterator has no next.");
        }
        return m_data[m_current++];
    }

    virtual bool HasPrev() const
    {
        return m_current > 0;
    }

    virtual T Prev()
    {
        if (!HasPrev())
        {
            throw std::out_of_range("Iterator has no next.");
        }
        return m_data[--m_current];
    }

private:
    T* m_data;
    unsigned int m_size;
    unsigned int m_current;
};

#endif // ARRAYITERATOR_H
