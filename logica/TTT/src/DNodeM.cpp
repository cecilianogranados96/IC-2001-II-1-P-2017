#include "DNodeM.h"
#include <stdexcept>
#include <cstddef>
#include "Movimiento.h"

using namespace std;

DNodeM::DNodeM(DNodeM* next, DNodeM* previous){
    this->next=next;
    this->previous=previous;
}

DNodeM::DNodeM(Movimiento* value, DNodeM* next, DNodeM* previous){
    this->value = value;
    this->next = next;
    this->previous = previous;
}

Movimiento* DNodeM::getValue(){
    return value;
}

void DNodeM::setValue(Movimiento* value)
{
    this->value = value;
}

DNodeM* DNodeM::getNext(){
    return next;
}

void DNodeM::setNext(DNodeM* node){
    next = node;
}

DNodeM* DNodeM::getPrevious(){
    return previous;
}

void DNodeM::setPrevious(DNodeM* node ){
    previous = node;
}

DNodeM::~DNodeM()
{
    delete previous;
    delete next;
}
