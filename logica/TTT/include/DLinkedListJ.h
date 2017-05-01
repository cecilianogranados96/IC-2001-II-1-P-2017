/*#ifndef DLINKEDLISTJ_H
#define DLINKEDLISTJ_H
#include <stdexcept>
#include <cstddef>
#include "DNodeJ.h"

class DLinkedListJ
{
    public:
        DLinkedListJ();
        virtual ~DLinkedListJ();
        void insert(Jugador* element);
        void append(Jugador* element);
        Jugador* remove();
        void goToStart();
        void goToEnd();
        void next();
        void previous();
        int getPos();
        int getSize();
        Jugador* getCurrValue();
        DNodeJ* getCurr();
        void goToPos(int pos);
        void print();

    protected:
        DNodeJ* first;
        DNodeJ* last;
        DNodeJ* curr;
        int size;

};

#endif // DLINKEDLIST_H
*/
