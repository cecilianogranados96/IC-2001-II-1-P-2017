#include "ArrayListN.h"
#include <iostream>
#include <stdexcept>
#define DEFAULT_MAX_SIZE 1024

using namespace std;

//Constructor vac�o
ArrayListN::ArrayListN(){}

//Constructor con par�metros
ArrayListN::ArrayListN(int pMax = DEFAULT_MAX_SIZE){
	elements = new int[pMax];
	size = 0;
	pos = 0;
	max = pMax;
}

//M�todo getValue: devuelve el valor en pos
int ArrayListN::getValue(){
    try
    {
        if(pos<0 || pos>size){
            throw runtime_error("La posicion esta fuera de los limites");
        }
        else if (size == 0){
            throw runtime_error("La cola esta vacia");
        }
        return elements[pos];
    }
    catch (runtime_error e)
    {
        cout << "Error: " << e.what()<<"\n\n";
    }
}

//M�todo getPos: devuelve pos
int ArrayListN::getPos(){
	return pos;
}

//M�todo getSize: devuelve el tama�o de la lista
int ArrayListN::getSize(){
	return size;
}

//M�todo goToStart: situa el pos al inicio de la lista
void ArrayListN::goToStart(){
	pos = 0;
}

//M�todo goToEnd: situa el pos al final de la lista
void ArrayListN::goToEnd(){
    pos = size-1;
}

//M�todo goToPos: pone el pos en la posici�n dada como par�metro
void ArrayListN::goToPos(int pos){
    try
    {
        if(pos<0 || pos>size){
            throw runtime_error("La posicion esta fuera de los limites");
        }
        this->pos = pos;
    }
    catch (runtime_error e)
    {
     cout << "Error: " << e.what()<<"\n\n";
    }
}

//M�todo previous: pone el pos en la posici�n anterior
void ArrayListN::previous(){
	if (pos>0){
		pos--;
	}
}

//M�todo next: pone el pos en la posici�n siguiente
void ArrayListN::next(){
	if (pos+1<size){
		pos++;
	}
}

//M�todo append: a�ade un elemento al final de la lista
void ArrayListN::append(int element){
    try
    {
        if(size == max){
            throw runtime_error("La cola esta llena");
        }
        elements[size] = element;
        size++;
    }
    catch (runtime_error e)
    {
     cout << "Error: " << e.what()<<"\n\n";
    }

}

//M�todo insert: inserta un elemento despu�s del pos
void ArrayListN::insert(int element){
    try
    {
        if(size == max){
            throw runtime_error("La cola esta llena");
        }

        for(int i=size;i>pos;i--){
            elements[i] = elements[i-1];
        }
        elements[pos] = element;
        size++;
    }
    catch (runtime_error e)
    {
        cout << "Error: "<< e.what()<<"\n\n";
    }
}

//Funci�n remove: elimina el elemento siguiente del pos
int ArrayListN::remove(){
    try
    {
        if (size == 0){
            throw runtime_error("La cola esta vacia");
        }
        int deleteElement = elements[pos];

        for(int i=pos;i<size;i++){
            elements[i] = elements[i+1];
        }

        size--;
        return deleteElement;
    }
    catch (runtime_error e)
    {
        cout << "Error: "<< e.what()<<"\n\n";
    }
}

//M�todo print: imprime la lista
void ArrayListN::print(){
    try
    {
        if (size == 0){
            throw runtime_error("La cola esta vacia");
        }

        for(int i=0;i<size;i++){
            cout<<elements[i]<<"\t";
        }
        cout<<"\n\n";
    }
    catch (runtime_error e)
    {
        cout << "Error: "<< e.what()<<"\n\n";
    }
}

//M�todo clear: elimina la lista de arreglos
void ArrayListN::clear()
{
    try
    {
        size = 0;
        pos = 0;
        delete []elements;
    }
    catch (runtime_error e)
    {
        cout << "Error: no se puede borrar"; //<< e.what();
    }
}

//M�todo destructor de la clase
ArrayListN::~ArrayListN(){
	clear();
}
