#ifndef NAIPE_H
#define NAIPE_H
#include <iostream>

using namespace std;

class Naipe
{
    public:
        Naipe(char nomenclatura, string numero, float valor, char mazo);
        virtual ~Naipe();
        char getNomenclatura();
        string getNumero();
        float getValor();
        char getMazo();
        void setNomenclatura(char nomenclatura);
        void setNumero(string numero);
        void setValor(float valor);
        void setMazo(char mazo);
        void print();
        string r_print();
    private:
        char nomenclatura;
        string numero;
        float valor;
        char mazo;
};

#endif // NAIPE_H
