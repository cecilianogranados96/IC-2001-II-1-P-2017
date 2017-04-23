#include "ArrayList.h"
#include <iostream>
#include <stdexcept>
#define DEFAULT_MAX_SIZE 1024

using namespace std;

//Constructor vac�o
ArrayList::ArrayList(){}

//Constructor con par�metros
ArrayList::ArrayList(int pMax){
	//elements = new Naipe[pMax];
	size = 0;
	pos = 0;
	max = pMax;
}

//M�todo getValue: devuelve el valor en pos
Naipe* ArrayList::getValue(){
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

//M�todo getMax: devuelve max
int ArrayList::getMax(){
	return max;
}

//M�todo getPos: devuelve pos
int ArrayList::getPos(){
	return pos;
}

//M�todo getSize: devuelve el tama�o de la lista
int ArrayList::getSize(){
	return size;
}

//M�todo goToStart: situa el pos al inicio de la lista
void ArrayList::goToStart(){
	pos = 0;
}

//M�todo goToEnd: situa el pos al final de la lista
void ArrayList::goToEnd(){
    pos = size-1;
}

//M�todo goToPos: pone el pos en la posici�n dada como par�metro
void ArrayList::goToPos(int pos){
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
void ArrayList::previous(){
	if (pos > 0){
		pos--;
	}
}

//M�todo next: pone el pos en la posici�n siguiente
void ArrayList::next(){
	if (pos+1<size){
		pos++;
	}
}

//M�todo append: a�ade un elemento al final de la lista
void ArrayList::append(Naipe* element){
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

//M�todo insert: inserta un elemento despu�s del pos
void ArrayList::insert(Naipe* element){
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

//Funci�n remove: elimina el elemento en el pos
Naipe* ArrayList::remove(){
    try
    {
        if (size == 0){
            throw runtime_error("La cola esta vacia");
        }
        Naipe* deleteElement = elements[pos];

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

//Funci�n removeElement: elimina el elemento que entra como par�metro
void ArrayList::removeElement(Naipe* naipe){
    try
    {
        int posicion = find(naipe);
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

//Funci�n find: devuelve la posici�n donde se encuentra el elemento
int ArrayList::find(Naipe* naipe)
{
    try
    {
        if (size == 0){
            throw runtime_error("La cola esta vacia");
        }
        int posicion = -1;
        for(int j=0; j<size; j++){
            if(naipe->getNomenclatura() == elements[j]->getNomenclatura()){
                if(naipe->getNumero() == elements[j]->getNumero()){
                    posicion = j;
                }
            }
        }
        return posicion;
    }
    catch (runtime_error e)
    {
        cout << "Error: "<< e.what()<<"\n\n";
    }
}

//M�todo print: imprime la lista
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
            r = r + elements[i]->r_print();
    }
    if (r == ""){
        return "Vacio";
    }else{
        return r;
    }
}

//M�todo clear: elimina la lista de arreglos
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

//M�todo destructor de la clase
ArrayList::~ArrayList(){
	clear();
}
