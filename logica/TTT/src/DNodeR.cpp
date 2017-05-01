/*#include "DNodeR.h"
#include <stdexcept>
#include <cstddef>
#include "Ronda.h"

using namespace std;

DNodeR::DNodeR(DNodeR* next, DNodeR* previous){
    this->next=next;
    this->previous=previous;
}

DNodeR::DNodeR(Ronda* value, DNodeR* next, DNodeR* previous){
    this->value = value;
    this->next = next;
    this->previous = previous;
}

Ronda* DNodeR::getValue(){
    return value;
}

void DNodeR::setValue(Ronda* value)
{
    this->value = value;
}

DNodeR* DNodeR::getNext(){
    return next;
}

void DNodeR::setNext(DNodeR* node){
    next = node;
}

DNodeR* DNodeR::getPrevious(){
    return previous;
}

void DNodeR::setPrevious(DNodeR* node ){
    previous = node;
}

DNodeR::~DNodeR()
{
    delete previous;
    delete next;
}
*/
