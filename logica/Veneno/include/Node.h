#include <iostream>
#ifndef NODE_H
#define NODE_H

using namespace std;

template <typename E>

class Node
{
    public:
        Node<E>();
        Node<E>(E value, Node<E>* next);
        Node<E>(Node<E>* next);
        virtual ~Node<E>();
        E getValue();
        void setValue(E value);
        Node<E>* getNext();
        void setNext(Node<E>* node);
        void clear();
    protected:
    private:
        E value;
        Node<E>* next;
};

#endif // NODE_H
