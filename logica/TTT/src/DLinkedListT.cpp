#include "DLinkedListT.h"
#include "DNodeT.h"
#include <stdexcept>
#include <cstddef>

using namespace std;

template class  DLinkedListT<int>;
template class  DLinkedListT<float>;
template class  DLinkedListT<char>;

template <typename E>
//Constructor
DLinkedListT<E>::DLinkedListT()
{
    first = new DNodeT<E>(NULL,NULL);
    last = new DNodeT<E>(NULL,first);
    first->setNext(last);
    last->setPrevious(first);
    curr = first;
    size=0;
}

template <typename E>
//Destructor
DLinkedListT<E>::~DLinkedListT()
{
    while (first != NULL)
    {
        curr = first;
        first = first->getNext();
        //delete curr;
    }
    size = 0;
    //delete first;
    //delete last;
}

//Añade el elemento dado en la posición siguiente a la del current
template <typename E>
void DLinkedListT<E>::insert(E value)
{
    DNodeT<E>* dNode = new DNodeT<E>(value, curr->getNext(), curr);

    curr ->getNext()->setPrevious(dNode);
    curr->setNext(dNode);
    size++;
}

//Añade el elemento dado al final de la lista
template <typename E>
void DLinkedListT<E>::append (E value)
{
    DNodeT<E>* dNode = new DNodeT<E>(value, last, last->getPrevious());

    last->getPrevious()->setNext(dNode);
    last->setPrevious(dNode);
    if(size==0)
    {
        next();
    }
    size++;
}

//Elimina el elemento siguiente al current
template <typename E>
E DLinkedListT<E>::remove()
{
     try
    {

        if(curr->getNext() == last && curr==last)
        {
            throw runtime_error("No element to remove");
        }
        E valDNodeToDelete = curr->getNext()->getValue();
        DNodeT<E>* temp = curr->getNext();
        curr->setNext(curr->getNext()->getNext());

        curr->getNext()->setPrevious(curr);
        curr = curr->getNext();
        //Mis delete no funcionan :( delete temp;
        size--;
        return valDNodeToDelete;
    }
    catch (runtime_error e)
    {
        cout << "Error: " << e.what()<<"\n\n";
    }
}


//Pone el current en el primer elemento
template <typename E>
void DLinkedListT<E>::goToStart()
{
    curr = first->getNext();
}


//Pone el current en el último elemento
template <typename E>
void DLinkedListT<E>::goToEnd()
{
    curr = last->getPrevious();
}


//Lleva el current a la posicion con el valor dado
template <typename E>
void DLinkedListT<E>::goToPos(int pos)
{
    if(pos<size && pos>=0)
    {
        int i = 0;
        goToStart();
        curr = curr->getNext();
        for(i=0; i<pos; i++)
        {
            curr = curr->getNext();
        }
    }
}


//Pone el current en el nodo siguiente al actual
template <typename E>
void DLinkedListT<E>::next()
{
    if (curr != last->getPrevious())
    {
        curr = curr->getNext();
    }
}

//Pone el current en el nodo anterior al actual
template <typename E>
void DLinkedListT<E>::previous()
{
    if (curr != first->getNext())
    {
        curr = curr->getPrevious();
    }
}

//Obtiene la posición en la que se encuentre el current
template <typename E>
int DLinkedListT<E>::getPos()
{
    int pos = 0;
    DNodeT<E>* temp = first;
    while (temp != curr)
    {
        temp = temp->getNext();
        pos ++;
    }
    return pos;
}

//Devuelve el tamaño de la lista
template <typename E>
int DLinkedListT<E>::getSize()
{
    return size;
}

template <typename E>
//Imprime la lista
void DLinkedListT<E>::print()
{
    if(size==0)
    {
        cout<<"La lista esta vacia \n \n";
    }
    else
    {
        goToStart();
        while (curr != last)
        {
            //cout<<curr->getValue()<<"\t";
            curr = curr->getNext();
        }
        goToStart();
        cout<<"\n \n";
    }
}

