#include "Movimiento.h"

//Constructor de la clase movimiento, guarda los datos del movimiento realizado
Movimiento::Movimiento(Jugador* jugador, Naipe* naipe, Baraja* caldero, ArrayList* bComidas, ArrayList* bVenenos)
{
    this->jugador = jugador;
    this->naipe = naipe;
    this->caldero = caldero;
    this->bComidas = bComidas;
    this->bVenenos = bVenenos;
    undo = false;
}

//Destructor de la clase
Movimiento::~Movimiento()
{
    delete jugador;
    delete naipe;
    delete caldero;
    delete bComidas;
    delete bVenenos;
}

//Setters
void Movimiento::setUndo(bool state)
{
    undo = state;
}

void Movimiento::setJugador(Jugador* jugador)
{
    this->jugador = jugador;
}

void Movimiento::setNaipe(Naipe* naipe)
{
    this->naipe = naipe;
}

void Movimiento::setCaldero(Baraja* caldero)
{
    this->caldero = caldero;
}

void Movimiento::setBComidas(ArrayList* bComidas)
{
    this->bComidas = bComidas;
}

void Movimiento::setBVenenos(ArrayList* bVenenos)
{
    this->bVenenos = bVenenos;
}

//Getters
bool Movimiento::getUndo()
{
    return undo;
}
Jugador* Movimiento::getJugador()
{
    return jugador;
}

Naipe* Movimiento::getNaipe()
{
    return naipe;
}

Baraja* Movimiento::getCaldero()
{
    return caldero;
}

ArrayList* Movimiento::getBComidas()
{
    return bComidas;
}

ArrayList* Movimiento::getBVenenos()
{
    return bVenenos;
}

//Autora: Silvia Calderón Navarro
//Fecha: 12 de abril del 2017
//Descripción: Devuelve un movimiento realizado
void Movimiento::undoMovimiento()
{
    if(undo == false)
    {
        if(bComidas->getSize() == 0)
        {
            caldero->getBaraja()->removeElement(naipe);
            jugador->getBActual()->append(naipe);
        }
        else
        {
            bComidas->removeElement(naipe);
            caldero->setBaraja(bComidas);
            jugador->getBActual()->append(naipe);

            for(int i=0; i<bComidas->getSize(); i++){
                bComidas->goToPos(i);
                jugador->getBComidas()->removeElement(bComidas->getValue());
            }

            for(int i=0; i<bVenenos->getSize(); i++){
                bVenenos->goToPos(i);
                jugador->getBVenenos()->removeElement(bVenenos->getValue());
            }
        }
        undo = true;
    }
}

//Autora: Silvia Calderón Navarro
//Fecha: 12 de abril del 2017
//Descripción: Vuelve a realizar un movimiento
void Movimiento::redoMovimiento()
{
    if(undo == true)
    {
        if(bComidas->getSize() == 0)
        {
            caldero->getBaraja()->append(naipe);
            jugador->getBActual()->removeElement(naipe);
        }
        else
        {
            bComidas->append(naipe);
            caldero = new Baraja('V', 15);
            jugador->getBActual()->removeElement(naipe);

            for(int i=0; i<bComidas->getSize(); i++){
                bComidas->goToPos(i);
                jugador->getBComidas()->append(bComidas->getValue());
            }

            for(int i=0; i<bVenenos->getSize(); i++){
                bVenenos->goToPos(i);
                jugador->getBVenenos()->append(bVenenos->getValue());
            }
        }
        undo = false;
    }
}

//Imprime los movimientos
void Movimiento::print()
{
    cout<<"\nJugador: ";
    jugador->print();
    cout<<"\nNaipe: ";
    naipe->print();
    cout<<"\nCaldero: ";
    caldero->getBaraja()->print();
    cout<<"\nCartas comidas: ";
    bComidas->print();
    cout<<"\nCartas venenos: ";
    bVenenos->print();
}
