/*#include <iostream>
#ifndef DNODEM_H
#define DNODEM_H
#include "Movimiento.h"

using namespace std;

class DNodeM
{
    public:
        DNodeM();
        DNodeM(Movimiento* value, DNodeM* next, DNodeM* previous);
        DNodeM(DNodeM* next, DNodeM* previous);
        virtual ~DNodeM();
        Movimiento* getValue();
        DNodeM* getPrevious();
        DNodeM* getNext();
        void setPrevious(DNodeM* previous);
        void setNext(DNodeM* next);
        void setValue(Movimiento* value);
        void clear();

    private:
        Movimiento* value;
        DNodeM* next;
        DNodeM* previous;
};

#endif // DNODE_H
*/
