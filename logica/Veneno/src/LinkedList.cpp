#include "LinkedList.h"
#include "Node.h"
#include <stdexcept>
#include <cstddef>

using namespace std;

template class  LinkedList<int>;
template class  LinkedList<char>;
template class  LinkedList<float>;

//Constructor de la clase
template <typename E>
LinkedList<E>::LinkedList()
{
    first = new Node<E>(NULL);
    last = first;
    curr = first;
    size = 0;
}

//Función getSize: devuelve el tamaño
template <typename E>
int LinkedList<E>::getSize()
{
    return size;
}

//Función getPos devuelve la posición del current
template <typename E>
int LinkedList<E>::getPos()
{
    int pos = 0;
    Node<E>* temp = first;
    while(temp != curr)
    {
        pos++;
        temp=temp->getNext();
    }
    return pos;
}

//Método goToStart: pone el current en el primer nodo
template <typename E>
void LinkedList<E>::goToStart()
{
    curr = first->getNext();
}

//Método goToStart: pone el current en el último nodo
template <typename E>
void LinkedList<E>::goToEnd()
{
    curr = last;
}

//Método goToPos: pone el current el posición del parámetro
template <typename E>
void LinkedList<E>::goToPos(int pos)
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

//Método next: situa el current en la siguiente posición
template <typename E>
void LinkedList<E>::next()
{
    if(curr->getNext()!=last)
    {
        curr = curr->getNext();
    }
}

//Método append: añade el parámetro al final de la lista
template <typename E>
void LinkedList<E>::append(E element)
{
    Node<E>* newNode = new Node<E>(element, NULL);
    last->setNext(newNode);
    last = newNode;
    size++;
}

//Método insert: inserta un elemento al final de la lista
template <typename E>
void LinkedList<E>::insert(E element)
{
    Node<E>* newNode = new Node<E>(element, NULL);
    newNode->setNext(curr->getNext());
    curr->setNext(newNode);
    if (curr==last)
    {
        last=last->getNext();
    }
    size++;
}

//Función find: devuelve la posición donde se encuentra un valor
template <typename E>
int LinkedList<E>::find(E value)
{
    try
    {
        if (size!=0)
        {
            goToStart();
            curr=curr->getNext();
            int i=0;
            while(curr!=NULL)
            {
                if (curr->getValue()== value)
                {
                    return i;
                }
                i++;
                curr = curr->getNext();
            }
            throw runtime_error("El valor no esta en la lista");
        }
        else
        {
            throw runtime_error("La lista esta vacia");
        }
    }
    catch (runtime_error e)
    {
        cout << "Error: " << e.what()<<"\n\n";
    }
}

//Función remove: elimina el nodo siguiente al current
template <typename E>
E LinkedList<E>::remove()
{
    try
    {
        if(curr->getNext() == NULL || size == 0)
        {
            throw runtime_error("No existe un elemento que borrar");
        }
        E value = curr->getNext()->getValue();
        Node<E>* temp = curr->getNext();
        curr->setNext(temp->getNext());
        if (temp == last)
        {
            last = curr;
        }
        return value;
    }
    catch (runtime_error e)
    {
        cout << "Error: " << e.what()<<"\n\n";
    }
}

//Método clear: elimina la lista
template <typename E>
void LinkedList<E>::clear()
{
    try
    {
        goToStart();
        for(int i=0; i<size; i++)
        {
            Node<E>* temp=curr;
            next();
            //delete temp;
        }
        //first = new Node<E>*(NULL);
        last = first;
        curr = first;
        size = 0;
    }
    catch (runtime_error e)
    {
        cout << "Error: no se puede borrar " << e.what()<<"\n\n";
    }
}

//Método print: imprime la lista
template <typename E>
void LinkedList<E>::print()
{
    try
    {
        Node<E> *temp= first->getNext();
        if (size!=0)
        {
            cout<<"Lista: \n";
            while(temp!=NULL)
            {
                cout<<temp->getValue()<< " \t";
                temp = temp->getNext();
            }
            cout<<"\n \n";
            delete temp;
        }
        else
        {
            throw runtime_error("La lista esta vacia");
        }
    }
    catch (runtime_error e)
    {
        cout << "Error: " << e.what()<<"\n\n";
    }
}

//Método printValue: imprime el valor del current
template <typename E>
void LinkedList<E>::printValue()
{
    try
    {
        if (size!=0)
        {
            if (curr==first)
                next();
            cout<<"Current: "<<curr->getValue()<< "\n \n";
        }
        else
        {
            throw runtime_error("La lista esta vacia");
        }
    }
    catch (runtime_error e)
    {
        cout << "Error: " << e.what()<<"\n\n";
    }
}

//Destructor de la clase
template <typename E>
LinkedList<E>::~LinkedList()
{
    clear();
}
