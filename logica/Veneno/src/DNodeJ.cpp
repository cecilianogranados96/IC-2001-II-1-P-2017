#include "DNodeJ.h"
#include <stdexcept>
#include <cstddef>
#include "Jugador.h"

using namespace std;

DNodeJ::DNodeJ(DNodeJ* next, DNodeJ* previous){
    this->next=next;
    this->previous=previous;
}

DNodeJ::DNodeJ(Jugador* value, DNodeJ* next, DNodeJ* previous){
    this->value = value;
    this->next = next;
    this->previous = previous;
}

Jugador* DNodeJ::getValue(){
    return value;
}

void DNodeJ::setValue(Jugador* value)
{
    this->value = value;
}

DNodeJ* DNodeJ::getNext(){
    return next;
}

void DNodeJ::setNext(DNodeJ* node){
    next = node;
}

DNodeJ* DNodeJ::getPrevious(){
    return previous;
}

void DNodeJ::setPrevious(DNodeJ* node ){
    previous = node;
}

DNodeJ::~DNodeJ()
{
    delete previous;
    delete next;
}
