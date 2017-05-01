/*#include "DCircleList.h"

DCircleList::DCircleList()
{
    first = new DNodeJ(last, last);
    last = new DNodeJ(first, first);
    first->setNext(last);
    last->setPrevious(first);
    curr = first;
}

void DCircleList::append (Jugador* value){
    DNodeJ* dnode = new DNodeJ(value,last,last->getPrevious());
    last->getPrevious()->setNext(dnode);
    last->setPrevious(dnode);
    size++;
}

bool DCircleList::empty(){
    if(size == 0 ){
        return 1;
    }else{
        return 0;
    }
}

void DCircleList::clear(){
    int x=0;
    while (x < size) {
        DLinkedListJ::remove();
        first->getNext();
        x++;
    }
}

DCircleList::~DCircleList()
{

}
*/
