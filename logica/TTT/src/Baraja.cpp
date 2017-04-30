#include "Baraja.h"
#include "ArrayListN.h"
#include <string>
#include <sstream>
#include <cstdlib>
#include <time.h>

using namespace std;

//Constructor de la clase
Baraja::Baraja(char tipo, int max)
{
    this->tipo = tipo;
    baraja = new ArrayList(max);
}

//Destructor de la clase
Baraja::~Baraja()
{
    delete baraja;
}

//Getters
char Baraja::getTipo()
{
    return tipo;
}

ArrayList* Baraja::getBaraja()
{
    return baraja;
}

//Setters
void Baraja::setTipo(char tipo)
{
    this->tipo = tipo;
}

void Baraja::setBaraja(ArrayList* baraja)
{
    this->baraja = baraja;
}

//Remueve el naipe en la posición que entra como parámetro
bool Baraja::removeNaipe(int pos)
{
    baraja->goToPos(pos);
    baraja->remove();
}

//Añade un naipe al final de la baraja
void Baraja::insertNaipe(Naipe* naipe)
{
    baraja->append(naipe);
}

//Devuelve el total de la baraja
float Baraja::totalBaraja()
{
    float total = 0;
    for(int i=0; i<baraja->getSize(); i++){
        baraja->goToPos(i);
        total = total + baraja->getValue()->getValor();
    }
    return total;
}

