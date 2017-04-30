#include "Naipe.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//Constructor clase Naipe, asigna los valores iniciales de naipe
Naipe::Naipe(char nomenclatura, string numero, float valor, char mazo)
{
    this->nomenclatura = nomenclatura;
    this->numero = numero;
    this->valor = valor;
    this->mazo = mazo;
}

//Destructor de la clase
Naipe::~Naipe()
{}

//Getters
char Naipe::getNomenclatura()
{
    return nomenclatura;
}

string Naipe::getNumero()
{
    return numero;
}

float Naipe::getValor()
{
    return valor;
}

char Naipe::getMazo()
{
    return mazo;
}

//Setters
void Naipe::setNomenclatura(char nomenclatura)
{
    this->nomenclatura = nomenclatura;
}

void Naipe::setNumero(string numero)
{
    this->numero = numero;
}

void Naipe::setValor(float valor)
{
    this->valor = valor;
}

void Naipe::setMazo(char mazo)
{
    this->mazo = mazo;
}

void Naipe::print()
{
    cout<<"\nNomenclatura: "<<nomenclatura<<", Numero: "<<numero<<", Valor: "<<valor<<", Tipo de mazo: "<<mazo;
}

string Naipe::r_print()
{
    stringstream ss;
    string s;
    ss << nomenclatura;
    ss >> s;

    stringstream ss2;
    string s2;
    ss2 << numero;
    ss2 >> s2;
    return s+":"+s2+"-";
}



