#include <iostream>
#include "Controladora.h"
#include "Server.h"
#include <sstream>
#include <string>
#include <cstdlib>
class Controladora;

using namespace std;

int toint(string val){
    stringstream geek(val);
    int x = 0;
    geek >> x;
    return x;
}

string tostring(int val){
    stringstream ss;
    ss << val;
    string str = ss.str();
    return str;
}

int main(void)
{
    Controladora* controladora = new Controladora();
    /*
        WSockServer MyServer(REQ_WINSOCK_VER);
        MyServer.RunServer(1500,"INICIAL");
    */
    cout<<"\t\t\t Tic Tac Toe GAME\n\n";
    int opcion = 0;
    while(true)
    {
        cout<<"\n\nMenu\n\n0.Configuracion\n1. Dibujar tablero\n2. Jugar\n3. Verificar ganador \n";
        WSockServer MyServer = WSockServer();
        opcion = toint(MyServer.RunServer("Opcion OK"));

        /**** Configuracion ****/
        if(opcion == 0){
            string ficha;
            cout<<"\nDigite Ficha con la cual juega: ";
            WSockServer MyServer = WSockServer();
            ficha = MyServer.RunServer("FICHA REGISTRADA");

        }
        /**** OPT JUEGO ****/
        if(opcion == 1){
            int numJugadores;
            cout<<"JUEGO: ";
            WSockServer MyServer = WSockServer();
            numJugadores = toint(MyServer.RunServer("Respuesta del tablero"));
            //Formato:        1-1:X~1-2:O~
        }
        /**** JUEGAR ****/
        if(opcion == 2)
        {
            string X;
            cout<<"\nDigite POS X: ";
            WSockServer MyServer = WSockServer();
            X = MyServer.RunServer("Opcion OK");
            ///////////////////////////////////////////////
            string Y;
            cout<<"\nDigite POS Y: ";
            WSockServer MyServer2 = WSockServer();
            Y = MyServer2.RunServer("Opcion OK");
            ///////////////////////////////////////////////
            cout<<"\n\nJUGADA CORRECTA";
            // Se supone que debe jugar en las posiciones dadas y verificar jugada

        }
        /**** VERIFICAR JUGADOR ****/
        if(opcion == 3)
        {
            string verificar;
            WSockServer MyServer = WSockServer();
            verificar = toint(MyServer.RunServer("JUGADOR GANADOR"));
            cout<<"Verifica Jugador";
        }


    }
}
