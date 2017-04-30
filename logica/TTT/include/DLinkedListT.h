#ifndef DLINKEDLISTT_H
#define DLINKEDLISTT_H
#include "DNodeT.h"

using namespace std;
template <typename E>

class DLinkedListT
{
    public:
        DLinkedListT<E>();
        virtual ~DLinkedListT<E>();
        void insert(E element);
        void append(E element);
        E remove();
        void goToStart();
        void goToEnd();
        void goToPos(int pos);
        void next();
        void previous();
        int getPos();
        int getSize();
        void print();

    private:
        DNodeT<E>* first;
        DNodeT<E>* last;
        DNodeT<E>* curr;
        int size;

};

#endif // DLinkedListT<E>_H
