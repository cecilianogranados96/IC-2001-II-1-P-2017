#ifndef MINMAX_H
#define MINMAX_H
#include <iostream>
#include <ArrayList.h>

using namespace std;

class minMax
{
    public:
        minMax();
        ~minMax();
        void BotPlayRand(ArrayList *m);
        void display(ArrayList *m);
        bool validMove(ArrayList *m , int &i, int&j);
        bool WinState (ArrayList *m , char ch = 'O');
        bool DoneGame(ArrayList *m );
        bool LooseState(ArrayList *m );
        int rWeight(char c1, char c2, char c3);
        int Evaluate(ArrayList *m);
        bool GoalState(ArrayList *m, char ch='O');
        int minimax(ArrayList *node, int level, bool IsBot, int &ii, int &jj);
        void PlayBot(ArrayList *m, int level);

    private:
        int print;
};
#endif // MINMAX_H
