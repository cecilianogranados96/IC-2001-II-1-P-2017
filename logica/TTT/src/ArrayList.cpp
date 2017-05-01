#include "ArrayList.h"
#include <iostream>
#include <stdexcept>
#define DEFAULT_MAX_SIZE 1024

using namespace std;

//Constructor vacío
ArrayList::ArrayList(){}

//Constructor con parámetros
ArrayList::ArrayList(int pMax){
	//elements = new ArrayListC[pMax];
	size = 0;
	pos = 0;
	max = pMax;
}

//Método getValue: devuelve el valor en pos
ArrayListC* ArrayList::getValue(){
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

//Método getMax: devuelve max
int ArrayList::getMax(){
	return max;
}

//Método getPos: devuelve pos
int ArrayList::getPos(){
	return pos;
}

//Método getSize: devuelve el tamaño de la lista
int ArrayList::getSize(){
	return size;
}

//Método goToStart: situa el pos al inicio de la lista
void ArrayList::goToStart(){
	pos = 0;
}

//Método goToEnd: situa el pos al final de la lista
void ArrayList::goToEnd(){
    pos = size-1;
}

//Método goToPos: pone el pos en la posición dada como parámetro
ArrayListC* ArrayList::goToPos(int pos){
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
void ArrayList::previous(){
	if (pos > 0){
		pos--;
	}
}

//Método next: pone el pos en la posición siguiente
void ArrayList::next(){
	if (pos+1<size){
		pos++;
	}
}

//Método append: añade un elemento al final de la lista
void ArrayList::append(ArrayListC* element){
    try
    {
        if(size == 1024){
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
void ArrayList::insert(ArrayListC* element){
    try
    {
        if(size == 1024){
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

//Función remove: elimina el elemento en el pos
ArrayListC* ArrayList::remove(){
    try
    {
        if (size == 0){
            throw runtime_error("La cola esta vacia");
        }
        ArrayListC* deleteElement = elements[pos];

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

//Función removeElement: elimina el elemento que entra como parámetro
void ArrayList::removeElement(ArrayListC* element){
    try
    {
        int posicion = find(element);
        if (size == 0){
            throw runtime_error("La cola esta vacia");
        }
        if(posicion == -1){
            throw runtime_error("No se encontro el elemento");
        }

        for(int i=posicion;i<size;i++){
            elements[i] = elements[i+1];
        }
        size--;
    }
    catch (runtime_error e)
    {
        cout << "Error: "<< e.what()<<"\n\n";
    }
}

//Función find: devuelve la posición donde se encuentra el elemento
int ArrayList::find(ArrayListC* element)
{
    try
    {
        if (size == 0){
            throw runtime_error("La cola esta vacia");
        }
        int posicion = -1;
        for(int j=0; j<size; j++){
            /*if(naipe->getNomenclatura() == elements[j]->getNomenclatura()){
                if(naipe->getNumero() == elements[j]->getNumero()){
                    posicion = j;
                }
            }*/
        }
        return posicion;
    }
    catch (runtime_error e)
    {
        cout << "Error: "<< e.what()<<"\n\n";
    }
}

//Método print: imprime la lista
void ArrayList::print(){
    try
    {
        if (size == 0){
            throw runtime_error("La cola esta vacia");
        }
        for(int i=0;i<size;i++){
            elements[i]->print();
        }
        cout<<"\n\n";
    }
    catch (runtime_error e)
    {
        cout << "Error: "<< e.what()<<"\n\n";
    }
}

string ArrayList::r_print(){
    string r = "";
    for(int i=0;i<size;i++){
           // r = r + elements[i]->r_print();
    }
    if (r == ""){
        return "Vacio";
    }else{
        return r;
    }
}

//Método clear: elimina la lista de arreglos
void ArrayList::clear()
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
ArrayList::~ArrayList(){
	clear();
}
