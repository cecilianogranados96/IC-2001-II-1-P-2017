#ifndef RONDA_H
#define RONDA_H
#include "DLinkedListJ.h"
#include "DLinkedListM.h"
#include "ArrayList.h"

class Ronda
{
    public:
        Ronda(DLinkedListJ* jugadores, ArrayList* bOrdenada);
        virtual ~Ronda();
        void setPosMovimiento(int posMovimiento);
        void setMovimientos(DLinkedListM* movimientos);
        void setJugadores(DLinkedListJ* jugadores);
        void setState(bool state);
        void setCantidad();
        void setBEnJuego(ArrayList* bEnJuego);
        int getPosMovimiento();
        int getCantidad();
        DLinkedListM* getMovimientos();
        DLinkedListJ* getJugadores();
        bool getState();
        ArrayList* getBEnJuego();
        Baraja* getCaldero1();
        Baraja* getCaldero2();
        Baraja* getCaldero3();
        bool addCaldero1(Naipe* naipe, Jugador* jugador);
        bool addCaldero2(Naipe* naipe, Jugador* jugador);
        bool addCaldero3(Naipe* naipe, Jugador* jugador);
        void redoMovimiento();
        void undoMovimiento();
        int totalNaipes();
        void barajar();
        void unirJugadores(DLinkedListJ* jugadoresTotal);

    private:
        int posMovimiento;
        DLinkedListM* movimientos;
        DLinkedListJ* jugadores;
        bool state;             //indica si la ronda ha terminado o no
        int cantidad;
        ArrayList* bEnJuego;    //baraja de cartas en uso
        Baraja* bCaldero1;
        Baraja* bCaldero2;
        Baraja* bCaldero3;
        bool validarTotal(Baraja* bCaldero, Jugador* jugador, Naipe* naipe);
        void addMovimiento(Jugador* jugador, Naipe* naipe, Baraja* caldero, ArrayList* bComidas, ArrayList* bVenenos);
};

#endif // RONDA_H
