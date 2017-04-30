#include <iostream>
#ifndef DNODEJ_H
#define DNODEJ_H
#include "Jugador.h"

class DNodeJ
{
    public:
        DNodeJ();
        DNodeJ(Jugador* value, DNodeJ* next, DNodeJ* previous);
        DNodeJ(DNodeJ* next, DNodeJ* previous);
        virtual ~DNodeJ();
        Jugador* getValue();
        DNodeJ* getPrevious();
        DNodeJ* getNext();
        void setPrevious(DNodeJ* previous);
        void setNext(DNodeJ* next);
        void setValue(Jugador* value);
        void clear();

    private:
        Jugador* value;
        DNodeJ* next;
        DNodeJ* previous;
};

#endif // DNODE_H

