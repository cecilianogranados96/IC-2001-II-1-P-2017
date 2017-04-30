#include "Controladora.h"
#include "ArrayListN.h"
#include "ArrayList.h"
#include <string>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <iostream>

using namespace std;

//Constructor de la clase
Controladora::Controladora()
{
    barajaOriginal = new Baraja('O', 52);
    jugadores = new DLinkedListJ();
    jugadoresActual = new DLinkedListJ();
    bOrdenada = new ArrayList(52);
    rondas = new DLinkedListR();
    crearBOriginal();
}

//Destructor de la clase
Controladora::~Controladora()
{
    delete jugadores;
    delete jugadoresActual;
    delete bOrdenada;
    delete barajaOriginal;
}

//Crea cada jugador y lo añade en la lista de jugadores
void Controladora::crearJugadores(string nombre)
{
    jugadores->append(new Jugador(nombre, jugadores->getSize()));
    jugadoresActual->append(new Jugador(nombre, jugadores->getSize()));
}

//Borra el jugador de la lista de jugadores actuales
void Controladora::borrarJugadores(Jugador* jugador)
{
    for(int i = 0; i<jugadoresActual->getSize(); i++){
        jugadoresActual->goToPos(i);
        if(jugador->getId() == jugadoresActual->getCurrValue()->getId()){
            if(i == 0){
                jugadoresActual->goToStart();
            }
            else
                jugadoresActual->goToPos(i-1);
            jugadoresActual->remove();
        }
    }
    numJugadoresActual--;
}

//Autora: Silvia Calderón Navarro
//Fecha: 10 de abril del 2017
//Descripción: Borra el jugador de la lista de jugadores actuales
void Controladora::borrarJugadores()
{
    jugadoresActual->goToStart();
    jugadoresActual->next();
    Jugador* temp = jugadoresActual->getCurrValue();
    int cant = 0;

    //busca el jugador con menos cartas veneno
    for(int i = 0; i<jugadoresActual->getSize(); i++){
        jugadoresActual->goToPos(i);
        if(jugadoresActual->getCurrValue()->getBVenenos()->getSize() < temp->getBVenenos()->getSize()){
            temp = jugadoresActual->getCurrValue();
        }
    }

    cout<<"\n\n Cantidad minima de venenos: "<<temp->getBVenenos()->getSize();

    //borra los jugadores con la menor cantidad de venenos
    int i = 0;
    bool borrado = false;
    do{
            borrado = false;
            jugadoresActual->goToPos(i);
            if(jugadoresActual->getCurrValue()->getBVenenos()->getSize() == temp->getBVenenos()->getSize()){
                borrarJugadores(jugadoresActual->getCurrValue());
                borrado = true;
            }
            if(borrado == true)
                i=0;
            else
                i++;
    }while(i<jugadoresActual->getSize());

}

//Setters
void Controladora::setJugadores(DLinkedListJ* jugadores)
{
    this->jugadores = jugadores;
}

void Controladora::setJugadoresActual(DLinkedListJ* jugadoresActual)
{
    this->jugadoresActual = jugadoresActual;
}

void Controladora::setNumJugadores(int numJugadores)
{
    this->numJugadores = numJugadores;
}

void Controladora::setNumJugadoresActual(int numJugadoresActual)
{
    this->numJugadoresActual = numJugadoresActual;
}

void Controladora::setRondas(DLinkedListR* rondas)
{
    this->rondas = rondas;
}
//Getters
DLinkedListJ* Controladora::getJugadores()
{
    return jugadores;
}

DLinkedListJ* Controladora::getJugadoresActual()
{
    return jugadoresActual;
}

int Controladora::getNumJugadores()
{
    return numJugadores;
}

int Controladora::getNumJugadoresActual()
{
    return numJugadoresActual;
}

ArrayList* Controladora::getBOrdenada()
{
    return bOrdenada;
}

Baraja* Controladora::getBarajaOriginal()
{
    return barajaOriginal;
}

DLinkedListR* Controladora::getRondas()
{
    return rondas;
}

//Autora: Silvia Calderón Navarro
//Fecha: 11 de abril del 2017
//Descripción: Crea una nueva ronda.
void Controladora::crearRondas()
{
    if(rondas->getSize() > 0)
    {
        rondas->goToEnd();
        DLinkedListJ* tempJugador = new DLinkedListJ();
        rondas->getCurrValue()->unirJugadores(jugadoresActual);
        unirJugadores();
        borrarJugadores();
        for(int i = 0; i < jugadoresActual->getSize(); i++)
        {
            jugadoresActual->goToPos(i);
            ArrayList* tempVenenos = new ArrayList();
            for(int j = 0; j <  jugadoresActual->getCurrValue()->getBVenenos()->getSize(); j++){
                jugadoresActual->getCurrValue()->getBVenenos()->goToPos(i);
                tempVenenos->append(jugadoresActual->getCurrValue()->getBVenenos()->getValue());
            }
            tempJugador->append(new Jugador(jugadoresActual->getCurrValue()->getNombre(), jugadoresActual->getCurrValue()->getId()));
            tempJugador->goToEnd();
            tempJugador->getCurrValue()->setBVenenos(tempVenenos);
        }
        rondas->append(new Ronda(jugadoresActual, crearBOriginal()));
        cout<<"RONDA :"<<rondas->getSize();
    }
    else{
        DLinkedListJ* tempJugador = new DLinkedListJ();
        for(int i = 0; i < jugadoresActual->getSize(); i++)
        {
            jugadoresActual->goToPos(i);
            tempJugador->append(new Jugador(jugadoresActual->getCurrValue()->getNombre(), jugadoresActual->getCurrValue()->getId()));
        }
        rondas->append(new Ronda(jugadoresActual, crearBOriginal()));
        cout<<"RONDA :"<<rondas->getSize();
    }

}

//Autora: Silvia Calderón Navarro
//Fecha: 11 de abril del 2017
//Descripción: Asigna los nuevos valores de los jugadores actuales, en la lista de jugadores
void Controladora::unirJugadores()
{
    for(int i = 0; i<jugadoresActual->getSize(); i++){
        jugadoresActual->goToPos(i);
        for(int j = 0; j<jugadores->getSize(); j++){
            jugadores->goToPos(j);
            if(jugadores->getCurrValue()->getId() == jugadoresActual->getCurrValue()->getId())
                jugadores->getCurr()->setValue(jugadoresActual->getCurrValue());
        }
    }
}

//Autora: Silvia Calderón Navarro
//Fecha: 10 de abril del 2017
//Descripción: Crea la baraja original ordenada
ArrayList* Controladora::crearBOriginal()
{
    ArrayList* temp = new ArrayList();
    float f;

    for(int i=0; i<4;i++)
    {
        for(int j=1; j<=13;j++)
        {
            f = (float)j;
            if(i==0){
                if(j==1){
                    bOrdenada->append(new Naipe('D',"A",f,barajaOriginal->getTipo()));
                    temp->append(new Naipe('D',"A",f,barajaOriginal->getTipo()));
                }
                else{
                    if(j<=10 && j>0){
                        //Convierte el de int a string j
                        string str;
                        ostringstream tempStr;
                        tempStr<<j;
                        str=tempStr.str();
                        bOrdenada->append(new Naipe('D',str,f,barajaOriginal->getTipo()));
                        temp->append(new Naipe('D',str,f,barajaOriginal->getTipo()));
                    }
                    else
                    {
                        if(j==11){
                            bOrdenada->append(new Naipe('D',"J",0.5,barajaOriginal->getTipo()));
                            temp->append(new Naipe('D',"J",0.5,barajaOriginal->getTipo()));
                        }
                        else
                        {
                            if(j==12){
                                bOrdenada->append(new Naipe('D',"Q",0.5,barajaOriginal->getTipo()));
                                temp->append(new Naipe('D',"Q",0.5,barajaOriginal->getTipo()));
                            }
                            else
                            {
                                bOrdenada->append(new Naipe('D',"K",0.5,barajaOriginal->getTipo()));
                                temp->append(new Naipe('D',"K",0.5,barajaOriginal->getTipo()));
                            }
                        }
                    }
                }
            }
            if(i==1){
                if(j==1){
                    bOrdenada->append(new Naipe('P',"A",f,barajaOriginal->getTipo()));
                    temp->append(new Naipe('P',"A",f,barajaOriginal->getTipo()));
                }
                else{
                    if(j<=10 && j>0){
                        //Convierte el de int a string j
                        string str;
                        ostringstream tempStr;
                        tempStr<<j;
                        str=tempStr.str();
                        bOrdenada->append(new Naipe('P',str,f,barajaOriginal->getTipo()));
                        temp->append(new Naipe('P',str,f,barajaOriginal->getTipo()));
                    }
                    else
                    {
                        if(j==11){
                            bOrdenada->append(new Naipe('P',"J",0.5,barajaOriginal->getTipo()));
                            temp->append(new Naipe('P',"J",0.5,barajaOriginal->getTipo()));
                        }
                        else
                        {
                            if(j==12){
                                bOrdenada->append(new Naipe('P',"Q",0.5,barajaOriginal->getTipo()));
                                temp->append(new Naipe('P',"Q",0.5,barajaOriginal->getTipo()));
                            }
                            else{
                                bOrdenada->append(new Naipe('P',"K",0.5,barajaOriginal->getTipo()));
                                temp->append(new Naipe('P',"K",0.5,barajaOriginal->getTipo()));
                            }
                        }
                    }
                }
            }
            if(i==2){
                if(j==1){
                    bOrdenada->append(new Naipe('T',"A",f,barajaOriginal->getTipo()));
                    temp->append(new Naipe('T',"A",0.5,barajaOriginal->getTipo()));
                }
                else{
                    if(j<=10 && j>0){
                        //Convierte el de int a string j
                        string str;
                        ostringstream tempStr;
                        tempStr<<j;
                        str=tempStr.str();
                        bOrdenada->append(new Naipe('T',str,f,barajaOriginal->getTipo()));
                        temp->append(new Naipe('T',str,f,barajaOriginal->getTipo()));
                    }
                    else
                    {
                        if(j==11){
                            bOrdenada->append(new Naipe('T',"J",0.5,barajaOriginal->getTipo()));
                            temp->append(new Naipe('T',"J",0.5,barajaOriginal->getTipo()));
                        }
                        else
                        {
                            if(j==12){
                                bOrdenada->append(new Naipe('T',"Q",0.5,barajaOriginal->getTipo()));
                                temp->append(new Naipe('T',"Q",0.5,barajaOriginal->getTipo()));
                            }
                            else{
                                bOrdenada->append(new Naipe('T',"K",0.5,barajaOriginal->getTipo()));
                                temp->append(new Naipe('T',"K",0.5,barajaOriginal->getTipo()));
                            }
                        }
                    }
                }
            }
            if(i==3){
                if(j==1){
                    bOrdenada->append(new Naipe('C',"A",f,barajaOriginal->getTipo()));
                    temp->append(new Naipe('C',"A",f,barajaOriginal->getTipo()));
                }
                else{
                    if(j<=10 && j>0){
                        //Convierte el de int a string j
                        string str;
                        ostringstream tempStr;
                        tempStr<<j;
                        str=tempStr.str();
                        bOrdenada->append(new Naipe('C',str,f,barajaOriginal->getTipo()));
                        temp->append(new Naipe('C',str,f,barajaOriginal->getTipo()));
                    }
                    else
                    {
                        if(j==11){
                            bOrdenada->append(new Naipe('C',"J",0.5,barajaOriginal->getTipo()));
                            temp->append(new Naipe('C',"J",0.5,barajaOriginal->getTipo()));
                        }
                        else
                        {
                            if(j==12){
                                bOrdenada->append(new Naipe('C',"Q",0.5,barajaOriginal->getTipo()));
                                temp->append(new Naipe('C',"Q",0.5,barajaOriginal->getTipo()));
                            }
                            else{
                                bOrdenada->append(new Naipe('C',"K",0.5,barajaOriginal->getTipo()));
                                temp->append(new Naipe('C',"K",0.5,barajaOriginal->getTipo()));
                            }
                        }
                    }
                }
            }
        }
    }
    barajaOriginal->setBaraja(bOrdenada);
    return temp;
}
