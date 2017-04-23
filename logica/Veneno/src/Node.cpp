#include "Node.h"
#include <stdexcept>
#include <cstddef>

using namespace std;

template class  Node<int>;
template class  Node<char>;
template class  Node<float>;

template <typename E>
//Constructor de un nodo vac�o con referencia al siguiente
Node<E>::Node(Node<E>* next){
    this->next=next;
}

template <typename E>
//Constructor de un nodo
Node<E>::Node(E value, Node<E>* next){
    this->value=value;
    this->next=next;
}

template <typename E>
//Funci�n getValue: devuelve el valor del nodo
E Node<E>::getValue(){
    return value;
}

template <typename E>
//Funci�n getNext: devuelve el nodo siguiente
Node<E>* Node<E>::getNext(){
    return next;
}

template <typename E>
//M�todo setNext: le asigna el par�metro como siguiente del nodo
void Node<E>::setNext(Node<E>* next){
    this->next= next;
}

template <typename E>
//M�todo setValue: le asigna el par�metro como valor del nodo
void Node<E>::setValue(E value){
    this->value=value;
}

template <typename E>
//M�todo clear: elimina el nodo
void Node<E>::clear(){
    delete next;
}

template <typename E>
//Destructor del nodo
Node<E>::~Node()
{
    clear();
}
