#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

using namespace std;
template <typename E>

class LinkedList
{
    public:
        LinkedList<E>();
        virtual ~LinkedList<E>();
        int getSize();
        int getPos();
        void goToStart();
        void goToEnd();
        void goToPos(int pos);
        void next();
        void previous();
        void insert(E element);
        void append(E element);
        void print();
        void clear();
        E remove();
        int find(E value);
        void printValue();
    protected:
        Node<E>* first;
        Node<E>* last;
        Node<E>* curr;
        int size;
};

#endif // LINKEDLIST_H
