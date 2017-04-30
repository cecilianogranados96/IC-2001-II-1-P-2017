#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H
#include "Jugador.h"
#include "Baraja.h"

class Movimiento
{
    public:
        Movimiento(Jugador* jugador, Naipe* naipe, Baraja* caldero, ArrayList* bComidas, ArrayList* bVenenos);
        ~Movimiento();
        void setUndo(bool state);
        void setJugador(Jugador* jugador);
        void setNaipe(Naipe* naipe);
        void setCaldero(Baraja* caldero);
        void setBComidas(ArrayList* bComidas);
        void setBVenenos(ArrayList* bVenenos);
        bool getUndo();
        Jugador* getJugador();
        Naipe* getNaipe();
        Baraja* getCaldero();
        ArrayList* getBComidas();
        ArrayList* getBVenenos();
        void undoMovimiento();
        void redoMovimiento();
        void print();

    protected:

    private:
        Jugador* jugador;
        Naipe* naipe;
        Baraja* caldero;
        ArrayList* bComidas;
        ArrayList* bVenenos;
        bool undo;
};

#endif // MOVIMIENTO_H
