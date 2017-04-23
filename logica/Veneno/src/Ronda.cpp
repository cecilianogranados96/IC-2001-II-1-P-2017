#include "Ronda.h"
#include "Baraja.h"
#include "ArrayListN.h"
#include <string>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <iostream>

//Constructor de la clase
Ronda::Ronda(DLinkedListJ* jugadores, ArrayList* bOrdenada)
{
    this->jugadores = jugadores;
    bCaldero1 = new Baraja('V', 15);
    bCaldero2 = new Baraja('V', 15);
    bCaldero3 = new Baraja('V', 15);
    movimientos = new DLinkedListM();
    bEnJuego = bOrdenada;
    state = true;
    setCantidad();
    posMovimiento = 0;
}

//Destructor de la clase
Ronda::~Ronda()
{
    delete jugadores;
    delete bCaldero1;
    delete bCaldero2;
    delete bCaldero3;
    delete bEnJuego;
}

//Setters
void Ronda::setPosMovimiento(int posMovimiento)
{
    this->posMovimiento = posMovimiento;
}

void Ronda::setMovimientos(DLinkedListM* movimientos)
{
    this->movimientos = movimientos;
}

void Ronda::setJugadores(DLinkedListJ* jugadores)
{
    this->jugadores = jugadores;
}

void Ronda::setState(bool state)
{
    this->state = state;
}

void Ronda::setCantidad()
{
    switch(jugadores->getSize()){
        case 2:
            cantidad = 7;
            break;
        case 3:
            cantidad = 6;
            break;
        case 4:
            cantidad = 5;
            break;
        case 5:
            cantidad = 4;
            break;
        case 6:
            cantidad = 3;
            break;
    }
}

void Ronda::setBEnJuego(ArrayList* bEnJuego)
{
    this->bEnJuego = bEnJuego;
}

//Getters
int Ronda::getPosMovimiento()
{
    return posMovimiento;
}

int Ronda::getCantidad()
{
    return cantidad;
}

DLinkedListM* Ronda::getMovimientos()
{
    return movimientos;
}

DLinkedListJ* Ronda::getJugadores()
{
    return jugadores;
}

bool Ronda::getState()
{
    return state;
}

ArrayList* Ronda::getBEnJuego()
{
    return bEnJuego;
}

Baraja* Ronda::getCaldero1()
{
    return bCaldero1;
}

Baraja* Ronda::getCaldero2()
{
    return bCaldero2;
}

Baraja* Ronda::getCaldero3()
{
    return bCaldero3;
}

//Autora: Silvia Calderón Navarro
//Fecha: 10 de abril del 2017
//Descripción: añade un nuevo movimiento, a la baraja de movimiento
void Ronda::addMovimiento(Jugador* jugador, Naipe* naipe, Baraja* caldero, ArrayList* bComidas, ArrayList* bVenenos)
{
    if(posMovimiento == movimientos->getSize() || posMovimiento == 0){
        movimientos->append(new Movimiento(jugador, naipe, caldero, bComidas, bVenenos));
        posMovimiento++;
    }
    else{
        movimientos->goToPos(posMovimiento);
        movimientos->getCurr()->setValue(new Movimiento(jugador, naipe, caldero, bComidas, bVenenos));
        posMovimiento++;
    }
}

//Autora: Silvia Calderón Navarro
//Fecha: 10 de abril del 2017
//Descripción: Añade naipes al caldero 1
bool Ronda::addCaldero1(Naipe* naipe, Jugador* jugador)
{
    if(naipe->getNomenclatura() != 'C'){
        if(bCaldero1->getTipo() == 'V'){
            if(bCaldero2->getTipo() != naipe->getNomenclatura() && bCaldero3->getTipo() != naipe->getNomenclatura()){
                bCaldero1->getBaraja()->append(naipe);
                bCaldero1->setTipo(naipe->getNomenclatura());
                jugador->getBActual()->removeElement(naipe);
                validarTotal(bCaldero1, jugador, naipe);
                return true;
            }
        }
        else{
            if(bCaldero1->getTipo() == naipe->getNomenclatura()){
                bCaldero1->getBaraja()->append(naipe);
                bCaldero1->setTipo(naipe->getNomenclatura());
                jugador->getBActual()->removeElement(naipe);
                validarTotal(bCaldero1, jugador, naipe);
                return true;
            }
        }
        cout<<"\n\nNO SE PUEDE COLOCAR LA CARTA\n\n";
        return false;
    }
    else{
        if(bCaldero1->getTipo() != 'V'){
            bCaldero1->getBaraja()->append(naipe);
            jugador->getBActual()->removeElement(naipe);
            validarTotal(bCaldero1, jugador, naipe);
            return true;
        }
        else{
            if(bCaldero1->getTipo() == 'V' && jugador->getBActual()->getSize() == 1){
                bCaldero1->getBaraja()->append(naipe);
                jugador->getBActual()->removeElement(naipe);
                validarTotal(bCaldero1, jugador, naipe);
                return true;
            }
        }
    }
}

//Autora: Silvia Calderón Navarro
//Fecha: 10 de abril del 2017
//Descripción: Añade naipes al caldero 2
bool Ronda::addCaldero2(Naipe* naipe, Jugador* jugador)
{
    if(naipe->getNomenclatura() != 'C'){
        if(bCaldero2->getTipo() == 'V'){
            if(bCaldero1->getTipo() != naipe->getNomenclatura() && bCaldero3->getTipo() != naipe->getNomenclatura()){
                bCaldero2->getBaraja()->append(naipe);
                bCaldero2->setTipo(naipe->getNomenclatura());
                jugador->getBActual()->removeElement(naipe);
                validarTotal(bCaldero2, jugador, naipe);
                return true;
            }
        }
        else{
            if(bCaldero2->getTipo() == naipe->getNomenclatura()){
                bCaldero2->getBaraja()->append(naipe);
                bCaldero2->setTipo(naipe->getNomenclatura());
                jugador->getBActual()->removeElement(naipe);
                validarTotal(bCaldero2, jugador, naipe);
                return true;
            }
        }
        cout<<"\n\nNO SE PUEDE COLOCAR LA CARTA\n\n";
        return false;
    }
    else{
        if(bCaldero2->getTipo() != 'V'){
            bCaldero2->getBaraja()->append(naipe);
            jugador->getBActual()->removeElement(naipe);
            validarTotal(bCaldero2, jugador, naipe);
            return true;
        }
        else{
            if(bCaldero2->getTipo() == 'V' && jugador->getBActual()->getSize() == 1){
                bCaldero2->getBaraja()->append(naipe);
                jugador->getBActual()->removeElement(naipe);
                validarTotal(bCaldero2, jugador, naipe);
                return true;
            }
        }
    }
}

//Autora: Silvia Calderón Navarro
//Fecha: 10 de abril del 2017
//Descripción: Añade naipes al caldero 3
bool Ronda::addCaldero3(Naipe* naipe, Jugador* jugador)
{
    if(naipe->getNomenclatura() != 'C'){
        if(bCaldero3->getTipo() == 'V'){
            if(bCaldero2->getTipo() != naipe->getNomenclatura() && bCaldero1->getTipo() != naipe->getNomenclatura()){
                bCaldero3->getBaraja()->append(naipe);
                bCaldero3->setTipo(naipe->getNomenclatura());
                jugador->getBActual()->removeElement(naipe);
                validarTotal(bCaldero3, jugador, naipe);
                return true;
            }
            else{
                cout<<"\n\nNO SE PUEDE COLOCAR LA CARTA\n\n";
                return false;
            }
        }
        else{
            if(bCaldero3->getTipo() == naipe->getNomenclatura()){
                bCaldero3->getBaraja()->append(naipe);
                bCaldero3->setTipo(naipe->getNomenclatura());
                jugador->getBActual()->removeElement(naipe);
                validarTotal(bCaldero3, jugador, naipe);
                return true;
            }
            else{
                cout<<"\n\nNO SE PUEDE COLOCAR LA CARTA\n\n";
                return false;
            }
        }
        cout<<"\n\nNO SE PUEDE COLOCAR LA CARTA\n\n";
        return false;
    }
    else{
        if(bCaldero3->getTipo() != 'V'){
            bCaldero3->getBaraja()->append(naipe);
            jugador->getBActual()->removeElement(naipe);
            validarTotal(bCaldero3, jugador, naipe);
            return true;
        }
        else{
            if(bCaldero3->getTipo() == 'V' && jugador->getBActual()->getSize() == 1){
                bCaldero3->getBaraja()->append(naipe);
                jugador->getBActual()->removeElement(naipe);
                validarTotal(bCaldero3, jugador, naipe);
                return true;
            }
        }
    }

}

//Autora: Silvia Calderón Navarro
//Fecha: 10 de abril del 2017
//Descripción: Verifica si el valor total del caldero es menor que 13, si es así retorna true, sino el jugador se come las cartas
bool Ronda::validarTotal(Baraja* bCaldero, Jugador* jugador, Naipe* naipe)
{
    ArrayList *tempComidas = new ArrayList();
    ArrayList *tempVenenos = new ArrayList();
    if(bCaldero->totalBaraja() >= 13)
    {
        for(int i=0; i<bCaldero->getBaraja()->getSize(); i++){
            bCaldero->getBaraja()->goToPos(i);
            jugador->getBComidas()->append(bCaldero->getBaraja()->getValue());
            tempComidas->append(bCaldero->getBaraja()->getValue());
            if(bCaldero->getBaraja()->getValue()->getNomenclatura() == 'C'){
                jugador->getBVenenos()->append(bCaldero->getBaraja()->getValue());
                tempVenenos->append(bCaldero->getBaraja()->getValue());
            }
        }
        bCaldero->setBaraja(new ArrayList(15));
        bCaldero->setTipo('V');
        cout<<"\n\nSE COME LAS CARTAS\n\n";
        addMovimiento(jugador, naipe, bCaldero, tempComidas, tempVenenos);
        return false;
    }else{
        addMovimiento(jugador, naipe, bCaldero, tempComidas, tempVenenos);
        cout<<"\n\nCREA UN MOVIMIENTO\n\n";
        return true;
    }

}

//Autora: Silvia Calderón Navarro
//Fecha: 10 de abril del 2017
//Descripción: Baraja el mazo con la cantidad de cartas indicadas
void Ronda::barajar()
{
    int max = cantidad * jugadores->getSize();
    ArrayListN* posiciones = new ArrayListN(max);

    srand(time(NULL));

    //Crea posiciones aleatorias y verifica que no existan en el arreglo
    for (int i=0;i<max;i++)
    {
        bool check;
        int n;
        do
        {
            n = rand()%(bEnJuego->getSize()-1);
            check = true;

            for (int j=0;j<i;j++){
                posiciones->goToPos(j);
                if (n == posiciones->getValue())
                {
                    check = false;
                    break;
                }
            }
        } while (!check);
        posiciones->append(n);
    }
    int sumCantidad = cantidad;
    int sumInicio = 0;


    //Asigna al jugador el mazo actual, tomando las posiciones aleatorias en el arrayList
    for(int i=0;i<jugadores->getSize();i++){
        ArrayList* temp = new ArrayList(52);
        jugadores->goToPos(i);
        for(int j=sumInicio;j<sumCantidad;j++){
            posiciones->goToPos(j);
            bEnJuego->goToPos(posiciones->getValue());
            temp->append(bEnJuego->getValue());
        }
        sumCantidad = sumCantidad + cantidad;
        sumInicio = sumInicio + cantidad;
        jugadores->getCurrValue()->setBActual(temp);
    }

    //Elimmina los naipes repartidos del mazo en juego
    for(int i=0;i<jugadores->getSize();i++){
        jugadores->goToPos(i);
        for(int j=0;j<cantidad;j++){
            jugadores->getCurrValue()->getBActual()->goToPos(j);
            bEnJuego->removeElement(jugadores->getCurrValue()->getBActual()->getValue());
        }
    }
}

//Autora: Silvia Calderón Navarro
//Fecha: 10 de abril del 2017
//Descripción: Devuelve el total de cartas en las manos de los jugadores
int Ronda::totalNaipes()
{
    int total = 0;
    for(int i=0; i<jugadores->getSize(); i++){
        jugadores->goToPos(i);
        total = total + jugadores->getCurrValue()->getBActual()->getSize();
    }
    return total;
}

//Autora: Silvia Calderón Navarro
//Fecha: 12 de abril del 2017
//Descripción: Devuelve al movimiento anterior
void Ronda::redoMovimiento()
{
    if(posMovimiento+1 < movimientos->getSize()){
        movimientos->goToPos(posMovimiento+1);
        movimientos->getCurrValue()->redoMovimiento();
        posMovimiento++;
    }
    else{
        cout<<"No hay mas movimientos por rehacer";
    }

}

//Autora: Silvia Calderón Navarro
//Fecha: 12 de abril del 2017
//Descripción: Vuelve al movimiento siguiente
void Ronda::undoMovimiento()
{
    if(posMovimiento <= movimientos->getSize() && posMovimiento >= 0){
        movimientos->goToPos(posMovimiento-1);
        movimientos->getCurrValue()->undoMovimiento();
        posMovimiento--;
    }
    else{
        cout<<"No hay más movimientos por deshacer";
    }
}

//Autora: Silvia Calderón Navarro
//Fecha: 12 de abril del 2017
//Descripción: Asigna los nuevos valores de los jugadores actuales, en la lista de jugadores
void Ronda::unirJugadores(DLinkedListJ* jugadoresTotal)
{
    for(int i = 0; i<jugadores->getSize(); i++){
        jugadores->goToPos(i);
        for(int j = 0; j<jugadoresTotal->getSize(); j++){
            jugadoresTotal->goToPos(j);
            if(jugadoresTotal->getCurrValue()->getId() == jugadores->getCurrValue()->getId())
                jugadoresTotal->getCurr()->setValue(jugadores->getCurrValue());
        }
    }
}
