#include "minMax.h"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <sstream>
#include <string>
minMax::minMax()
{
    //ctor
}

minMax::~minMax()
{
    //dtor
}


void minMax::BotPlayRand(ArrayList *m) {
    int i(rand()%3), j(rand()%3);
    m->goToPos(i)->goToPos(j);
    m->getValue()->setValue('O');
    return;
}
void minMax::display(ArrayList *m) {
    cout << "Estado del juego:" << endl;
    for(int i=0; i < m->getSize(); i++) {
        m->goToPos(i);
        for(int j=0; j < m->getValue()->getSize(); j++){
            m->getValue()->goToPos(j);
            cout << m->getValue()->getValue() << " ";
        }
        cout << endl;
   }
   return;
}

string minMax::tostring(int val){
    stringstream ss;
    ss << val;
    string str = ss.str();
    return str;
}

string minMax::display_r(ArrayList *m) {
    string x;
    for(int i=0; i < m->getSize(); i++) {
        m->goToPos(i);
        for(int j=0; j < m->getValue()->getSize(); j++){
            m->getValue()->goToPos(j);
            x = x + "#" + tostring(i) + tostring(j) +"-"+ m->getValue()->getValue() + "~";
        }
   }
   return x;
}


bool minMax::validMove(ArrayList *m , int &i, int&j) {
     m->goToPos(i);
     m->getValue()->goToPos(j);
    return (i < m->getSize())     &&
           (j < m->getValue()->getSize())  &&
           (m->getValue()->goToPos(j) == '*');
}

bool minMax::WinState (ArrayList *m , char ch) {
    for(int i=0;i < m->getSize();i++) {
        if(ch == m->goToPos(i)->goToPos(0) && m->goToPos(i)->goToPos(0) == m->goToPos(i)->goToPos(1) && m->goToPos(i)->goToPos(1) == m->goToPos(i)->goToPos(2)) return true;
        if(ch == m->goToPos(0)->goToPos(i) && m->goToPos(0)->goToPos(i) == m->goToPos(1)->goToPos(i) && m->goToPos(1)->goToPos(i) == m->goToPos(2)->goToPos(i)) return true;
    }
    if(ch == m->goToPos(0)->goToPos(0) && m->goToPos(0)->goToPos(0) == m->goToPos(1)->goToPos(1) && m->goToPos(1)->goToPos(1) == m->goToPos(2)->goToPos(2)) return true;
    if(ch == m->goToPos(2)->goToPos(0) && m->goToPos(2)->goToPos(0) == m->goToPos(1)->goToPos(1) && m->goToPos(1)->goToPos(1) == m->goToPos(0)->goToPos(2)) return true;
    return false;
}

bool minMax::DoneGame(ArrayList *m ) {
    for(int i=0;i < m->getSize();i++)
        for(int j=0;j < m->goToPos(i)->getSize();j++) if(m->goToPos(i)->goToPos(j) == '*') return false;
    return true;
}

bool minMax::LooseState(ArrayList *m ) {
    return WinState(m, 'X');
}

int minMax::rWeight(char c1, char c2, char c3)
{
    ArrayListC* row = new ArrayListC(3);
    row->goToStart();
    row->append(c1);
    row->append(c2);
    row->append(c3);
	int numX = 0;
	int numO = 0;

	for (int i = 0; i < 3; ++i)
	{
		if (row->goToPos(i) == 'X') numX++;
		if (row->goToPos(i) == 'O') numO++;
	}
    delete row;
	if (numX == numO) return 0;
	else if (numO == 3) return 100;
	else if (numO == 2) return 10;
	else if (numO == 1) return 1;
	else if (numX == 3) return -100;
	else if (numX == 2) return -10;
	else if (numX == 1) return -1;
	else return 0;
}

int minMax::Evaluate(ArrayList *m) {
    return rWeight(m->goToPos(0)->goToPos(0), m->goToPos(0)->goToPos(1), m->goToPos(0)->goToPos(2)) + rWeight(m->goToPos(1)->goToPos(0), m->goToPos(1)->goToPos(1), m->goToPos(1)->goToPos(2))
	+ rWeight(m->goToPos(2)->goToPos(0), m->goToPos(2)->goToPos(1), m->goToPos(2)->goToPos(2)) + rWeight(m->goToPos(0)->goToPos(0), m->goToPos(1)->goToPos(0), m->goToPos(2)->goToPos(0))
	+ rWeight(m->goToPos(0)->goToPos(1), m->goToPos(1)->goToPos(1), m->goToPos(2)->goToPos(1)) + rWeight(m->goToPos(0)->goToPos(2), m->goToPos(1)->goToPos(2), m->goToPos(2)->goToPos(2))
	+ rWeight(m->goToPos(0)->goToPos(0), m->goToPos(1)->goToPos(1), m->goToPos(2)->goToPos(2)) + rWeight(m->goToPos(0)->goToPos(2), m->goToPos(1)->goToPos(1), m->goToPos(2)->goToPos(0));
}

bool minMax::GoalState(ArrayList *m, char ch) {
    return WinState(m,ch) || LooseState(m) || DoneGame(m);
}

int minMax::minimax(ArrayList *node, int level, bool IsBot, int &ii, int &jj) {
    if(GoalState(node)) return Evaluate(node);   // return the heuristic value
    int bestval, tempval, lf(10 - level), iii , jjj;
    if(IsBot) {
        bestval = INT_MIN;
        for(int i = 0; i<node->getSize(); i++) {
            for(int j = 0; j<node->goToPos(i)->getSize(); j++) {
                if(node->goToPos(i)->goToPos(j) == '*') {
                    node->getValue()->setValue('O');
                    tempval = minimax(node, level + 1, false, ii , jj);
                    if(tempval > bestval) {
                        bestval = tempval;
                        iii = i;
                        jjj = j;
                    }
                    node->goToPos(i)->goToPos(j);
                    node->getValue()->setValue('*');
                }
           }
        }
    ii = iii;
    jj = jjj;
    } else {
        bestval = INT_MAX;
        for(int i = 0; i < node->getSize(); i++) {
            for(int j = 0; j<node->goToPos(i)->getSize(); j++) {
                if(node->goToPos(i)->goToPos(j) == '*') {
                    node->goToPos(i)->goToPos(j);
                    node->getValue()->setValue('X');
                    tempval = minimax(node, level + 1, true, ii, jj);
                    if(tempval < bestval ) {
                        bestval = tempval;
                        ii = i;
                        jj = j;
                    }
                    node->goToPos(i)->goToPos(j);
                    node->getValue()->setValue('*');
                }
            }
        }
    }
    return bestval;
}

void minMax::PlayBot(ArrayList *m, int level) {
    int playi(0), playj(0);
    int bestval = INT_MIN, tempval;
    print = level;
    bestval = minimax(m, level, true, playi, playj);
    cout << "Bestval:" << bestval
         << " Bestmove: (" << playi << ", " << playj << ")" << endl;
    m->goToPos(playi)->goToPos(playj);
    m->getValue()->setValue('O');
}
