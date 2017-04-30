#include "DNodeT.h"
#include <stdexcept>
#include <cstddef>

using namespace std;

template class  DNodeT<int>;
template class  DNodeT<float>;
template class  DNodeT<char>;

template <typename E>
//Constructor sin valor
DNodeT<E>::DNodeT(DNodeT<E>* next, DNodeT<E>* previous)
{
    this->next=next;
    this->previous=previous;
}

template <typename E>
//Constructor con valor
DNodeT<E>::DNodeT(E value, DNodeT<E>* next, DNodeT<E>* previous)
{
    this->value = value;
    this->next = next;
    this->previous = previous;
}


template <typename E>
//Destructor
DNodeT<E>::~DNodeT()
{
    clear();
}

template <typename E>
//Devuelve el valor del nodo
E DNodeT<E>::getValue()
{
    return value;
}

template <typename E>
//Devuelve el siguiente nodo
DNodeT<E>* DNodeT<E>::getNext()
{
    return next;
}

template <typename E>
//Asigna el siguiente nodo
void DNodeT<E>::setNext(DNodeT<E>* node)
{
    next=node;
}

template <typename E>
//Devuelve el nodo anterior
DNodeT<E>* DNodeT<E>::getPrevious()
{
    return previous;
}

template <typename E>
//Asigna el nodo anterior
void DNodeT<E>::setPrevious(DNodeT<E>* node )
{
    previous=node;
}

template <typename E>
//Elimina el nodo
void DNodeT<E>::clear()
{
    delete next;
    delete previous;
}
