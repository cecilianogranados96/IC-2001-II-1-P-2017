#include <iostream>
#ifndef DNODET_H
#define DNODET_H

using namespace std;

template <typename E>

class DNodeT
{
    public:
        DNodeT<E>();
        DNodeT<E>(E value, DNodeT<E>* next, DNodeT<E>* previous);
        DNodeT<E>(DNodeT<E> *next, DNodeT<E> *previous);
        virtual ~DNodeT<E>();
        E getValue();
        DNodeT<E>* getPrevious();
        DNodeT<E>* getNext();
        void setPrevious(DNodeT<E>* previous);
        void setNext(DNodeT<E>* next);
        void clear();
    protected:
    private:
        E value;
        DNodeT<E>* next;
        DNodeT<E>* previous;
};

#endif // NODE_H
