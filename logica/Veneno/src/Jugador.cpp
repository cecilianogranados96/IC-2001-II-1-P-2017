#include "Jugador.h"

//Constructor de la clase
Jugador::Jugador(string nombre, int id)
{
   this->nombre = nombre;
   this->id = id;
   bVenenos = new ArrayList(52);
   bActual = new ArrayList(52);
   bComidas = new ArrayList(52);
}

//Destructor de la clase
Jugador::~Jugador()
{
   delete bVenenos;
   delete bActual;
   delete bComidas;
}

//Setters
void Jugador::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Jugador::setId(int id)
{
    this->id = id;
}

void Jugador::setBVenenos(ArrayList* bVenenos)
{
    this->bVenenos = bVenenos;
}

void Jugador::setBComidas(ArrayList* bComidas)
{
    this->bComidas = bComidas;
}

void Jugador::setBActual(ArrayList* bActual)
{
    this->bActual = bActual;
}

//Getters
string Jugador::getNombre()
{
    return nombre;
}

int Jugador::getId()
{
    return id;
}

ArrayList* Jugador::getBVenenos()
{
    return bVenenos;
}

ArrayList* Jugador::getBComidas()
{
    return bComidas;
}

ArrayList* Jugador::getBActual()
{
    return bActual;
}

void Jugador::print()
{
    cout<<"\nNombre: "<<nombre<<" ID: "<<id<<"\n";
    cout<<"Cartas en mano: ";
    bActual->print();
    cout<<"Cartas comidas: ";
    bComidas->print();
    cout<<"Cartas veneno: ";
    bVenenos->print();
}

string Jugador::print_r()
{
    /*
    cout<<"\nNombre: "<<nombre<<" ID: "<<id<<"\n";
    cout<<"Cartas en mano: ";
    bActual->r_print();
    cout<<"Cartas comidas: ";
    bComidas->r_print();
    cout<<"Cartas veneno: ";
    bVenenos->r_print();
    */
    return nombre+"~"+bActual->r_print()+"~"+bComidas->r_print()+"~"+bVenenos->r_print();
}
