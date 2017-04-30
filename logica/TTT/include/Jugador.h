#ifndef JUGADOR_H
#define JUGADOR_H
#include "ArrayList.h"

class Jugador
{
    public:
        Jugador(string nombre, int id);
        ~Jugador();
        void setNombre(string nombre);
        void setId(int id);
        void setBVenenos(ArrayList* bVenenos);
        void setBComidas(ArrayList* bComidas);
        void setBActual(ArrayList* bActual);
        string getNombre();
        int getId();
        ArrayList* getBVenenos();
        ArrayList* getBComidas();
        ArrayList* getBActual();
        void print();
        string print_r();

    protected:

    private:
        string nombre;
        int id;
        ArrayList* bVenenos;
        ArrayList* bComidas;
        ArrayList* bActual;
};

#endif // JUGADOR_H
