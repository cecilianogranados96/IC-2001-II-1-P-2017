#include "ArrayListC.h"
#include <iostream>
#include <stdexcept>
#define DEFAULT_MAX_SIZE 1024

using namespace std;

//Constructor vacío
ArrayListC::ArrayListC(){}

//Constructor con parámetros
ArrayListC::ArrayListC(int pMax = DEFAULT_MAX_SIZE){
	elements = new char[pMax];
	size = 0;
	pos = 0;
	max = pMax;
}

//Método getValue: devuelve el valor en pos
char ArrayListC::getValue(){
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
void ArrayListC::setValue(char element)
{
    elements[pos] = element;
}

//Método getPos: devuelve pos
int ArrayListC::getPos(){
	return pos;
}

//Método getSize: devuelve el tamaño de la lista
int ArrayListC::getSize(){
	return size;
}

//Método goToStart: situa el pos al inicio de la lista
void ArrayListC::goToStart(){
	pos = 0;
}

//Método goToEnd: situa el pos al final de la lista
void ArrayListC::goToEnd(){
    pos = size-1;
}

//Método goToPos: pone el pos en la posición dada como parámetro
char ArrayListC::goToPos(int pos){
    try
    {
        if(pos<0 || pos>size){
            throw runtime_error("La posicion esta fuera de los limites");
        }
        this->pos = pos;
        return elements[pos];
    }
    catch (runtime_error e)
    {
     cout << "Error: " << e.what()<<"\n\n";
    }
}

//Método previous: pone el pos en la posición anterior
void ArrayListC::previous(){
	if (pos>0){
		pos--;
	}
}

//Método next: pone el pos en la posición siguiente
void ArrayListC::next(){
	if (pos+1<size){
		pos++;
	}
}

//Método append: añade un elemento al final de la lista
void ArrayListC::append(char element){
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

//Método insert: inserta un elemento después del pos
void ArrayListC::insert(char element){
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

//Función remove: elimina el elemento siguiente del pos
int ArrayListC::remove(){
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

//Método print: imprime la lista
void ArrayListC::print(){
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

//Método clear: elimina la lista de arreglos
void ArrayListC::clear()
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

//Método destructor de la clase
ArrayListC::~ArrayListC(){
	clear();
}
