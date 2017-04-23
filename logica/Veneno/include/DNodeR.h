#include <iostream>
#ifndef DNODER_H
#define DNODER_H
#include "Ronda.h"

class DNodeR
{
    public:
        DNodeR();
        DNodeR(Ronda* value, DNodeR* next, DNodeR* previous);
        DNodeR(DNodeR* next, DNodeR* previous);
        virtual ~DNodeR();
        Ronda* getValue();
        DNodeR* getPrevious();
        DNodeR* getNext();
        void setPrevious(DNodeR* previous);
        void setNext(DNodeR* next);
        void setValue(Ronda* value);
        void clear();

    private:
        Ronda* value;
        DNodeR* next;
        DNodeR* previous;
};

#endif // DNODER_H

