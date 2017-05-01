/*#ifndef DLINKEDLISTR_H
#define DLINKEDLISTR_H
#include <stdexcept>
#include <cstddef>
#include "DNodeR.h"

class DLinkedListR
{
    public:
        DLinkedListR();
        virtual ~DLinkedListR();
        void insert(Ronda* element);
        void append(Ronda* element);
        Ronda* remove();
        void goToStart();
        void goToEnd();
        void next();
        void previous();
        int getPos();
        int getSize();
        Ronda* getCurrValue();
        DNodeR* getCurr();
        void goToPos(int pos);
        void print();

    protected:
        DNodeR* first;
        DNodeR* last;
        DNodeR* curr;
        int size;

};

#endif // DLINKEDLIST_H
*/
