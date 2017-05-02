#include "Server.h"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <minMax.h>
#include <ArrayList.h>
#include <ArrayListC.h>
#include <sstream>
#include <string>
#include <cstdlib>

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
    while(true){
        int opt;
        cout << "\t\t\t Tic Tac Toe\n 1 - Config \n 2 - Tablero \n 3 - Jugar \n 4 - Verificar" << endl;
        cout << "Digite una opcion:";
        //cin >> opt;

        WSockServer MyServer = WSockServer();
        opt = toint(MyServer.RunServer("Opcion OK"));

        /*CONFIGURACION*/
        if (opt == 1){
            cout << "¿Quiere el primer turno? 1:si 0: no" << endl;
            //cin >> opt;
            WSockServer MyServer = WSockServer();
            opt = toint(MyServer.RunServer("Configuracion OK"));
            if(opt == 1){
                BotStart = false;
            }else{
                BotStart = true;
            }
            if(BotStart) {
                cout << "Empieza PC" << endl;
                minMaxTree->BotPlayRand(m);
                TotalMoves = 1;
            }
        }

        /*TABLERO*/
        if (opt == 2){
            minMaxTree->display(m);
            WSockServer MyServer = WSockServer();
            MyServer.RunServer(minMaxTree->display_r(m));

        }
        /*JUGAR*/
        if (opt == 3){
            minMaxTree->display(m);
            cout << "Tu turno X. Digite las coordenadas:";
            //cin >> i >> j;
            WSockServer MyServer = WSockServer();
            int i = toint(MyServer.RunServer("Respuesta CORDENADA I"));

            WSockServer MyServer2 = WSockServer();
            int j = toint(MyServer2.RunServer("Respuesta CORDENADA J"));

            m->goToPos(i)->goToPos(j);
            if(minMaxTree->validMove(m,i,j)){
                m->getValue()->setValue('X');
            }
            TotalMoves ++;
            minMaxTree->PlayBot(m, TotalMoves);
            TotalMoves++;
            cout << "total de movimientos :" << TotalMoves << endl;
        }
        /*VERIFICAR GANADOR*/
        if (opt == 4){
            minMaxTree->display(m);
            string ver;
            if(minMaxTree->LooseState(m)){
                    cout << "Maquina Perdio :(" << endl;
                    ver = "Loose";
            }else if(minMaxTree->WinState(m)){
                    cout << "Maquina Gano:" << endl;
                    ver = "Win";
            }else if (TotalMoves == 9){
                    cout << "Empate" << endl;
                    ver = "Bougth";
            }else{
                cout << "Continua el juego" << endl;
                ver = "Next";
            }
            WSockServer MyServer = WSockServer();
            MyServer.RunServer(ver);
        }
    }
}
