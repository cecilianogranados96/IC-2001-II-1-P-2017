/*
#include <iostream>
#include "Controladora.h"
#include "Server.h"
#define REQ_WINSOCK_VER 2
#include <sstream>
#include <string>
#include <cstdlib>

class Controladora;
using namespace std;

int main(void)
{
    Controladora* controladora = new Controladora();
   // WSockServer MyServer(REQ_WINSOCK_VER);
    //MyServer.RunServer(1500,"Respuesta Inical a fuerta tiene que ir");

    int opcion = 0;
    while(true)
    {
       // WSockServer MyServer(REQ_WINSOCK_VER);
        cout<<"\n\nMenu\n\n0. Asignar cantidad jugadores\n1. Crear jugador(n)\n2. Ver jugador(cartas en mano)\n3. Ver nombre Jugador\n4. Ver caldero (s)\n5. Jugar (recibe jugador y carta, caldero a mover)\n6. Verificar ronda\n7. Ver ronda\n8. Ver jugadores actuales\n9. Ver jugadores\n10. Ver resultados\n11. Redo\n12. Undo\n13. Reset\n14. Buscar carta\n15. Ver jugador total\n16. Ver movimiento\n\nDigite su eleccion: ";
        cin>>opcion;
        //opcion = toint(MyServer.RunServer(1500,"Opcion OK"));

        if(opcion == 0){
            int numJugadores;
            cout<<"Digite la cantidad de jugadores [2-6]: ";
            //WSockServer MyServer(REQ_WINSOCK_VER);
            //numJugadores = toint(MyServer.RunServer(1500,"Opcion OK"));
            cin>>numJugadores;
            controladora->setNumJugadores(numJugadores);
            controladora->setNumJugadoresActual(numJugadores);
        }
        if(opcion == 1)
        {
            string nombre;
            cout<<"\nDigite el nombre del jugador: ";
            cin>>nombre;
            controladora->crearJugadores(nombre);
            if(controladora->getNumJugadores() == controladora->getJugadores()->getSize()){
                cout<<"\n\nSe crearon todos los jugadores\n\n";
                controladora->crearRondas();
                controladora->getRondas()->goToEnd();
                controladora->getRondas()->getCurrValue()->barajar();
            }
        }
        if(opcion == 2)
        {
            int jugador;
            cout<<"Digite el numero de jugador a ver: ";
            cin>>jugador;
            controladora->getRondas()->goToEnd();
            controladora->getRondas()->getCurrValue()->getJugadores()->goToPos(jugador);
            controladora->getRondas()->getCurrValue()->getJugadores()->getCurrValue()->getBActual()->print();
        }
        if(opcion == 3)
        {
            int jugador;
            cout<<"Digite el numero de jugador a ver: ";
            cin>>jugador;
            controladora->getRondas()->goToEnd();
            controladora->getRondas()->getCurrValue()->getJugadores()->goToPos(jugador);
            cout<<controladora->getRondas()->getCurrValue()->getJugadores()->getCurrValue()->getNombre();
        }
        if(opcion == 4)
        {
            int caldero;
            cout<<"Digite el numero de caldero: ";
            cin>>caldero;
            if(caldero == 1){
                controladora->getRondas()->goToEnd();
                controladora->getRondas()->getCurrValue()->getCaldero1()->getBaraja()->print();
                cout<<"\nTipo: "<<controladora->getRondas()->getCurrValue()->getCaldero1()->getTipo();
            }
            if(caldero == 2){
                controladora->getRondas()->goToEnd();
                controladora->getRondas()->getCurrValue()->getCaldero2()->getBaraja()->print();
                cout<<"\nTipo: "<<controladora->getRondas()->getCurrValue()->getCaldero2()->getTipo();
            }
            if(caldero == 3){
                controladora->getRondas()->goToEnd();
                controladora->getRondas()->getCurrValue()->getCaldero3()->getBaraja()->print();
                cout<<"\nTipo: "<<controladora->getRondas()->getCurrValue()->getCaldero3()->getTipo();
            }

        }
        if(opcion == 5)
        {
            controladora->getRondas()->goToEnd();
            if(controladora->getRondas()->getSize() == 1 && controladora->getRondas()->getCurrValue()->getMovimientos()->getSize() == 0)
                controladora->setJugadoresActual(controladora->getJugadores());
            if(controladora->getNumJugadoresActual()>1){
                int jugador, caldero, carta;
                cout<<"Digite el numero de jugador: ";
                cin>>jugador;
                cout<<"Digite el caldero: ";
                cin>>caldero;
                cout<<"Digite la posicion de la carta: ";
                cin>>carta;
                controladora->getRondas()->getCurrValue()->getJugadores()->goToPos(jugador);
                controladora->getRondas()->getCurrValue()->getJugadores()->getCurrValue()->getBActual()->goToPos(carta);
                if(caldero == 1){
                    controladora->getRondas()->getCurrValue()->addCaldero1(controladora->getRondas()->getCurrValue()->getJugadores()->getCurrValue()->getBActual()->getValue(),controladora->getRondas()->getCurrValue()->getJugadores()->getCurrValue());
                    controladora->getRondas()->getCurrValue()->getCaldero1()->getBaraja()->print();
                }
                if(caldero == 2){
                    controladora->getRondas()->getCurrValue()->addCaldero2(controladora->getRondas()->getCurrValue()->getJugadores()->getCurrValue()->getBActual()->getValue(),controladora->getRondas()->getCurrValue()->getJugadores()->getCurrValue());
                    controladora->getRondas()->getCurrValue()->getCaldero2()->getBaraja()->print();
                }
                if(caldero == 3){
                    controladora->getRondas()->getCurrValue()->addCaldero3(controladora->getRondas()->getCurrValue()->getJugadores()->getCurrValue()->getBActual()->getValue(),controladora->getRondas()->getCurrValue()->getJugadores()->getCurrValue());
                    controladora->getRondas()->getCurrValue()->getCaldero3()->getBaraja()->print();
                }
            }
            else{
                cout<<"\n\nTERMINA EL JUEGO\n\n";
            }
        }
        if(opcion == 6){
            controladora->getRondas()->goToEnd();
            if(controladora->getRondas()->getCurrValue()->totalNaipes() == 0){
                if(controladora->getRondas()->getCurrValue()->getBEnJuego()->getSize() >= (controladora->getRondas()->getCurrValue()->getCantidad() * controladora->getRondas()->getCurrValue()->getJugadores()->getSize())){
                    controladora->getRondas()->getCurrValue()->barajar();
                    cout<<"\n\nBARAJA\n\n";
                }
                else{
                    controladora->getRondas()->getCurrValue()->setState(false);
                    controladora->crearRondas();
                    bEnJuego->getValue());
                    cout<<"\n\nNUEVA RONDA\n\n";
                }
            }
        }
        if(opcion == 7){
            controladora->getRondas()->getSize();
            cout<<controladora->getRondas()->getSize();
        }
        if(opcion == 8){
            controladora->getRondas()->getCurrValue()->getJugadores();
            controladora->getRondas()->getCurrValue()->getJugadores()->print();
        }
        if(opcion == 9){
            controladora->getJugadores();
            controladora->getJugadores()->print();
        }
        if(opcion == 10){
            controladora->getJugadores();
        }
        if(opcion == 11){
            controladora->getRondas()->goToEnd();
            controladora->getRondas()->getCurrValue()->redoMovimiento();
        }
        if(opcion == 12){
            controladora->getRondas()->goToEnd();
            controladora->getRondas()->getCurrValue()->undoMovimiento();
        }
        if(opcion == 13){
            controladora->getRondas()->goToEnd();
            controladora->getRondas()->getCurr()->setValue(new Ronda(controladora->getJugadoresActual(), controladora->getBOrdenada()));
        }
        if(opcion == 14){
            //busca la carta
        }
        if(opcion == 15){
            int jugador;
            cout<<"Digite el numero de jugador a ver: ";
            cin>>jugador;
            controladora->getRondas()->goToEnd();
            controladora->getRondas()->getCurrValue()->getJugadores()->goToPos(jugador);
            controladora->getRondas()->getCurrValue()->getJugadores()->getCurrValue()->print();
        }
        if(opcion == 16){
            controladora->getRondas()->goToEnd();
            controladora->getRondas()->getCurrValue()->getMovimientos()->goToEnd();
            controladora->getRondas()->getCurrValue()->getMovimientos()->getCurrValue()->print();

        }
    }
}*/

#include <iostream>
#include "Controladora.h"
#include "Server.h"
#define REQ_WINSOCK_VER 2
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
    cout<<"\t\t\t VENENO GAME \n"<<endl;
    Controladora* controladora = new Controladora();
    WSockServer MyServer(REQ_WINSOCK_VER);
    MyServer.RunServer(1500,"INICIAL");

    int opcion = 0;
    while(true)
    {
        WSockServer MyServer(REQ_WINSOCK_VER);
        cout<<"\t\t\tVENENO GAME\n\nMenu\n\n0. Asignar cantidad jugadores\n1. Crear jugador(n)\n2. Ver jugador(cartas en mano)\n3. Ver nombre Jugador\n4. Ver caldero (s)\n5. Jugar (recibe jugador y carta, caldero a mover)\n6. Verificar ronda\n7. Ver ronda\n8. Ver jugadores actuales\n9. Ver numero de jugadores\n10. Ver resultados\n11. Redo\n12. Undo\n13. Reset\n14. Buscar carta\n15. Ver jugador total\n16. Ver movimiento\n17. Cartas en maso\n\nDigite su eleccion: ";
        //cin>>opcion;
        opcion = toint(MyServer.RunServer(1500,"Opcion OK"));
         ////////////////////LISTO/////////////////////
        if(opcion == 0){
            int numJugadores;
            cout<<"Digite la cantidad de jugadores [2-6]: ";
            WSockServer MyServer(REQ_WINSOCK_VER);
            numJugadores = toint(MyServer.RunServer(1500,"Opcion OK"));
            //cin>>numJugadores;
            controladora->setNumJugadores(numJugadores);
            controladora->setNumJugadoresActual(numJugadores);
            cout<<"NUM JUGADOR: "<<controladora->getNumJugadores();

        }
         ////////////////////LISTO/////////////////////
        if(opcion == 1)
        {
            string nombre;
            cout<<"\nDigite el nombre del jugador: ";
            //cin>>nombre;
            WSockServer MyServer(REQ_WINSOCK_VER);
            nombre = MyServer.RunServer(1500,"Opcion OK");
            controladora->crearJugadores(nombre);
            cout<<"\n\nNOMBRE:"<<nombre;
            if(controladora->getNumJugadores() == controladora->getJugadores()->getSize()){
                controladora->setJugadoresActual(controladora->getJugadores());
                controladora->crearRondas();
                controladora->getRondas()->goToEnd();
                controladora->getRondas()->getCurrValue()->barajar();
                cout<<"\n\nSe crearon todos los jugadores\n\n";
            }
        }
        ////////////////////LISTO/////////////////////
        if(opcion == 2)
        {
            int jugador;
            cout<<"DIGITE MAZO A VER: ";
            //cin>>jugador;
            WSockServer MyServer(REQ_WINSOCK_VER);
            jugador = toint(MyServer.RunServer(1500,"MAZO"));
            controladora->getRondas()->goToEnd();
            controladora->getRondas()->getCurrValue()->getJugadores()->goToPos(jugador);
            //El de arriba jugador recibe la opcion y el de abajo la envia, si se te queda pegado solamente dijiste otra opcion
            //Como este caso mira
            MyServer.RunServer(1500,controladora->getRondas()->getCurrValue()->getJugadores()->getCurrValue()->getBActual()->r_print());
            MyServer.send2(controladora->getRondas()->getCurrValue()->getJugadores()->getCurrValue()->getBActual()->r_print());
            cout <<"\n\n";
            controladora->getRondas()->getCurrValue()->getJugadores()->getCurrValue()->getBActual()->print();
        }
        ////////////////////LISTO/////////////////////
        if(opcion == 3)
        {
            int jugador;
            cout<<"Digite el numero de jugador a ver: ";
            //cin>>jugador;
            WSockServer MyServer(REQ_WINSOCK_VER);
            jugador = toint(MyServer.RunServer(1500,"RESPUESTA NOMBRE"));
            controladora->getRondas()->goToEnd();
            controladora->getRondas()->getCurrValue()->getJugadores()->goToPos(jugador);

            WSockServer MyServer2(REQ_WINSOCK_VER);
            string venenos = tostring(controladora->getRondas()->getCurrValue()->getJugadores()->getCurrValue()->getBVenenos()->getSize());
            string ronda = tostring(controladora->getRondas()->getSize());
            string nombre = controladora->getRondas()->getCurrValue()->getJugadores()->getCurrValue()->getNombre();

            string pozo = tostring(controladora->getRondas()->getCurrValue()->getBEnJuego()->getSize());
            string val = controladora->getRondas()->getCurrValue()->getJugadores()->getCurrValue()->getNombre() + "-" + ronda  + "-" + venenos + "-" + pozo;
            MyServer2.RunServer(1500,val);
            cout<<"NOMBRE JUGADOR: "<<val;
        }

        if(opcion == 4)
        {
            int caldero;
            cout<<"Digite el numero de caldero: ";
            //cin>>caldero;
            WSockServer MyServer(REQ_WINSOCK_VER);
            caldero = toint(MyServer.RunServer(1500,"Opcion OK"));
            string res = "OP CAL";
            if(caldero == 1){
                controladora->getRondas()->goToEnd();
                res = controladora->getRondas()->getCurrValue()->getCaldero1()->getBaraja()->r_print();
                controladora->getRondas()->getCurrValue()->getCaldero1()->getBaraja()->print();
            }
            if(caldero == 2){
                controladora->getRondas()->goToEnd();
                res = controladora->getRondas()->getCurrValue()->getCaldero2()->getBaraja()->r_print();
                controladora->getRondas()->getCurrValue()->getCaldero2()->getBaraja()->print();
            }
            if(caldero == 3){
                controladora->getRondas()->goToEnd();
                res = controladora->getRondas()->getCurrValue()->getCaldero3()->getBaraja()->r_print();
                controladora->getRondas()->getCurrValue()->getCaldero3()->getBaraja()->print();
            }
            WSockServer MyServer2(REQ_WINSOCK_VER);
            MyServer2.RunServer(1500,res);

        }


        if(opcion == 5)
        {
            controladora->getRondas()->goToEnd();
            if(controladora->getRondas()->getSize() == 1 && controladora->getRondas()->getCurrValue()->getMovimientos()->getSize() == 0)
                controladora->setJugadoresActual(controladora->getJugadores());
            if(controladora->getNumJugadoresActual()>1){
                int jugador, caldero, carta;

                WSockServer MyServer(REQ_WINSOCK_VER);
                cout<<"Digite el numero de jugador: ";
                //cin>>jugador;
                jugador = toint(MyServer.RunServer(1500,"OPT JUGADOR OK"));

                cout<<"Digite el caldero: ";
                //cin>>caldero;
                caldero = toint(MyServer.RunServer(1500,"OPT CALDERO OK"));

                cout<<"Digite la posicion de la carta: ";
                //cin>>carta;
                carta = toint(MyServer.RunServer(1500,"OP CARTA OK"));
                controladora->getRondas()->getCurrValue()->getJugadores()->goToPos(jugador);
                controladora->getRondas()->getCurrValue()->getJugadores()->getCurrValue()->getBActual()->goToPos(carta);

                if(caldero == 1){
                    controladora->getRondas()->getCurrValue()->addCaldero1(controladora->getRondas()->getCurrValue()->getJugadores()->getCurrValue()->getBActual()->getValue(),controladora->getRondas()->getCurrValue()->getJugadores()->getCurrValue());
                    controladora->getRondas()->getCurrValue()->getCaldero1()->getBaraja()->print();
                }
                if(caldero == 2){
                    controladora->getRondas()->getCurrValue()->addCaldero2(controladora->getRondas()->getCurrValue()->getJugadores()->getCurrValue()->getBActual()->getValue(),controladora->getRondas()->getCurrValue()->getJugadores()->getCurrValue());
                    controladora->getRondas()->getCurrValue()->getCaldero2()->getBaraja()->print();
                }
                if(caldero == 3){
                    controladora->getRondas()->getCurrValue()->addCaldero3(controladora->getRondas()->getCurrValue()->getJugadores()->getCurrValue()->getBActual()->getValue(),controladora->getRondas()->getCurrValue()->getJugadores()->getCurrValue());
                    controladora->getRondas()->getCurrValue()->getCaldero3()->getBaraja()->print();
                }
            }
        }

        if(opcion == 6){
            controladora->getRondas()->goToEnd();
            cout<<controladora->getRondas()->getCurrValue()->totalNaipes();
            if(controladora->getRondas()->getCurrValue()->totalNaipes() == 0){
                cout<<"ENTRE";
                if(controladora->getRondas()->getCurrValue()->getBEnJuego()->getSize() >= (controladora->getRondas()->getCurrValue()->getCantidad() * controladora->getRondas()->getCurrValue()->getJugadores()->getSize())){
                    controladora->getRondas()->getCurrValue()->barajar();
                    cout<<"BARAJE";
                }
                else{
                    controladora->getRondas()->getCurrValue()->setState(false);
                    controladora->crearRondas();
                    controladora->getRondas()->goToEnd();
                    controladora->getRondas()->getCurrValue()->barajar();
                    cout<<"CREE RONDA";
                }
            }
        }

        //LISTO LO DEVUELVE CON EL NOMBRE
        if(opcion == 7){
            cout<<controladora->getRondas()->getSize();
            WSockServer MyServer(REQ_WINSOCK_VER);
            MyServer.RunServer(1500,tostring(controladora->getRondas()->getSize()));
        }
        if(opcion == 8){
            controladora->getRondas()->getCurrValue()->getJugadores()->print();
        }
        //VER JUGADORES ACTUALES
        if(opcion == 9){
            WSockServer MyServer(REQ_WINSOCK_VER);
            string cant_jugadores = tostring(controladora->getJugadores()->getSize());
            MyServer.RunServer(1500,cant_jugadores);
            cout<<"Cantidad de jugadores:"<<cant_jugadores;
        }
         //RESULTADOS
        if(opcion == 10){

            controladora->getJugadores()->print();


        }
        if(opcion == 11){
            controladora->getRondas()->goToEnd();
            controladora->getRondas()->getCurrValue()->redoMovimiento();
            cout<<"REDO MOVIMIENTO";
        }
        if(opcion == 12){
            controladora->getRondas()->goToEnd();
            controladora->getRondas()->getCurrValue()->undoMovimiento();
            cout<<"UNDO MOVIMIENTO";
        }
        if(opcion == 13){
            controladora->getRondas()->goToEnd();
            controladora->getRondas()->getCurr()->setValue(new Ronda(controladora->getJugadoresActual(), controladora->getBOrdenada()));
            cout<<"RESET MOVIMIENTO";
        }
        if(opcion == 14){
            //busca la carta
            cout<<"BUSCAR CARTA MOVIMIENTO";
        }
        if(opcion == 15){
            int jugador;
            WSockServer MyServer(REQ_WINSOCK_VER);
            cout<<"Digite el numero de jugador a ver: ";
            //cin>>jugador;
            jugador = toint(MyServer.RunServer(1500,"OPT JUGADOR OK"));
            controladora->getRondas()->goToEnd();
            controladora->getRondas()->getCurrValue()->getJugadores()->goToPos(jugador);
            controladora->getRondas()->getCurrValue()->getJugadores()->getCurrValue()->print();
            WSockServer MyServer2(REQ_WINSOCK_VER);
            MyServer2.RunServer(1500,controladora->getRondas()->getCurrValue()->getJugadores()->getCurrValue()->print_r());

        }
		if(opcion == 16){
            controladora->getRondas()->goToEnd();
            //controladora->getRondas()->getCurrValue()->getMovimientos()->goToPos(controladora->getRondas()->getCurrValue()->getPosMovimiento());
            controladora->getRondas()->getCurrValue()->getMovimientos()->goToEnd();
            controladora->getRondas()->getCurrValue()->getMovimientos()->getCurrValue()->print();
        }
		if(opcion == 17){
            controladora->getRondas()->goToEnd();
            WSockServer MyServer2(REQ_WINSOCK_VER);
            MyServer2.RunServer(1500,tostring(controladora->getRondas()->getCurrValue()->getBEnJuego()->getSize()));
            cout<<"CARTAS EN MASO:"<<controladora->getRondas()->getCurrValue()->getBEnJuego()->getSize();
        }
        if(opcion == 18){
            int jugador;
            cout<<"Digite el numero de jugador a ver: ";
            //cin>>jugador;
            WSockServer MyServer(REQ_WINSOCK_VER);
            jugador = toint(MyServer.RunServer(1500,"RESPUESTA NOMBRE"));
            controladora->getRondas()->goToEnd();
            controladora->getRondas()->getCurrValue()->getJugadores()->goToPos(jugador);
            WSockServer MyServer2(REQ_WINSOCK_VER);
            string venenos_n = tostring(controladora->getRondas()->getCurrValue()->getJugadores()->getCurrValue()->getBVenenos()->getSize());
            string nombre = controladora->getRondas()->getCurrValue()->getJugadores()->getCurrValue()->getNombre();
            string venenos = controladora->getJugadores()->getCurrValue()->getBVenenos()->r_print();
            string val = nombre + "~" + venenos_n  + "~" + venenos;
            MyServer2.RunServer(1500,val);
            cout<<"NOMBRE JUGADOR: "<<val;
        }
        //system("cls");
    }
}

