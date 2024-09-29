#ifndef DICTIONARYITERATOR_H
#define DICTIONARYITERATOR_H
#include <stdexcept>
#include "Iterator.h"

template<typename K, typename V>
class DictionaryIterator:public Iterator<std::pair<K,V>>
{
public:
    DictionaryIterator(std::pair<K, V>* collection, unsigned int collectionSize):m_data(collection),m_size(collectionSize),m_current(0)
{}
    virtual bool HasNext() const
    {
        return m_current < m_size;
    }

    virtual std::pair<K, V> Next()
    {
        if(!HasNext())
        {
            throw std::out_of_range("Iterator has no next.");
        }
        return m_data[m_current++];
    }

    virtual bool HasPrev() const
    {
        return m_current > 0;
    }

    virtual std::pair<K, V> Prev()
    {
        if (!HasPrev())
        {
            throw std::out_of_range("Iterator has no next.");
        }
        return m_data[--m_current];
    }
private:
    std::pair<K,V>* m_data;
    unsigned int m_size;
    unsigned int m_current;
};

#endif // DICTIONARYITERATOR_H
