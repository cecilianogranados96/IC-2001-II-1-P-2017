/*#include <iostream>
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

    cout<<"\t\t\t Tic Tac Toe GAME\n\n";
    int opcion = 0;
    while(true)
    {
        cout<<"\n\nMenu\n\n0.Configuracion\n1. Dibujar tablero\n2. Jugar\n3. Verificar ganador \n";
        WSockServer MyServer = WSockServer();
        opcion = toint(MyServer.RunServer("Opcion OK"));

        /**** Configuracion ***
        if(opcion == 0){
            string ficha;
            cout<<"\nDigite Ficha con la cual juega: ";
            WSockServer MyServer = WSockServer();
            ficha = MyServer.RunServer("FICHA REGISTRADA");

        }
        /**** OPT JUEGO ***
        if(opcion == 1){
            int numJugadores;
            cout<<"JUEGO: ";
            WSockServer MyServer = WSockServer();
            numJugadores = toint(MyServer.RunServer("Respuesta del tablero"));
            //Formato:        1-1:X~1-2:O~
        }
        /**** JUGAR ***
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
        /**** VERIFICAR JUGADOR ***
        if(opcion == 3)
        {
            string verificar;
            WSockServer MyServer = WSockServer();
            verificar = toint(MyServer.RunServer("JUGADOR GANADOR"));
            cout<<"Verifica Jugador";
        }


    }
}*/

#include <iostream>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <minMax.h>
#include <ArrayList.h>
#include <ArrayListC.h>


int main(void){
    minMax *minMaxTree = new minMax();
    srand(time(0));
    bool BotStart(false);
    string yesno;
    int TotalMoves(0),i(0),j(0);
    ArrayList* m = new ArrayList(3);
    for(int i=0; i<3; i++){
        m->goToPos(i);
        m->append(new ArrayListC(3));
        m->goToEnd();
        for(int j=0; j<3; j++){
            m->getValue()->append('*');
        }
    }

REYESNO:
    cout << "¿Quiere el primer turno? si no" << endl;
    cin >> yesno;
    if(yesno == "si") BotStart = false;
    else if(yesno == "no") BotStart = true;
    else {
         cout << "La entrada fue inválida, vuelva a intentar" << endl;
         goto REYESNO;
    }
    cout << "Puede empezar su turno al escribir coordenadas como: 1 2 empezando en 0 0 desde la esquina superior izquierda." << endl;
    if(BotStart) {
        cout << "Empieza PC" << endl;
        minMaxTree->BotPlayRand(m);
        TotalMoves = 1;
    }
    while(TotalMoves < 9) {
PLAY:
        minMaxTree->display(m);
        cout << "Tu turno X. Digite las coordenadas:";
        cin >> i >> j;
        m->goToPos(i)->goToPos(j);
        if(!minMaxTree->validMove(m,i,j)) goto PLAY;
        else m->getValue()->setValue('X');
        TotalMoves ++;
        if(minMaxTree->GoalState(m)) goto Done;
        minMaxTree->PlayBot(m, TotalMoves);
        if(minMaxTree->GoalState(m)) goto Done;
        TotalMoves++;

        cout << "total de movimientos :" << TotalMoves << endl;
    }
Done:

    minMaxTree->display(m);
    if(minMaxTree->LooseState(m)) cout << "Bot Loose :(" << endl;
    else if(minMaxTree->WinState(m)) cout << "Bot Win:" << endl;
    else cout << "Empate" << endl;
    return 0;

}
