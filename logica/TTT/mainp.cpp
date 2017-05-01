/*#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>
#include <ctime>
using namespace std;

int main(){
    minMax *minMaxTree = new minMax();
    srand(time(0));
    bool BotStart(false);
    string yesno;
    int TotalMoves(0),i(0),j(0);
    vector <vector <char> > m(3, vector <char> (3,'*'));
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
        cout << "Your move X. Enter coordinates:";
        cin >> i >> j;
        if(!minMaxTree->validMove(m,i,j)) goto PLAY;
        else m[i][j] = 'X';
        TotalMoves ++;
        if(minMaxTree->GoalState(m)) goto Done;
        minMaxTree->PlayBot(m, TotalMoves);
        if(minMaxTree->GoalState(m)) goto Done;
        TotalMoves++;
        cout << "total moves :" << TotalMoves << endl;
    }
Done:
    minMaxTree->display(m);
    if(minMaxTree->LooseState(m)) cout << "Bot Loose :(" << endl;
    else if(minMaxTree->WinState(m)) cout << "Bot Win:" << endl;
    else cout << "Draw" << endl;
    return 0;

}*/
