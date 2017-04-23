#ifndef DLINKEDLISTM_H
#define DLINKEDLISTM_H
#include <stdexcept>
#include <cstddef>
#include "DNodeM.h"

class DLinkedListM
{
    public:
        DLinkedListM();
        virtual ~DLinkedListM();
        void insert(Movimiento* element);
        void append(Movimiento* element);
        Movimiento* remove();
        void goToStart();
        void goToEnd();
        void next();
        void previous();
        int getPos();
        int getSize();
        Movimiento* getCurrValue();
        DNodeM* getCurr();
        void goToPos(int pos);
        void print();

    protected:
        DNodeM* first;
        DNodeM* last;
        DNodeM* curr;
        int size;

};

#endif // DLINKEDLIST_H
