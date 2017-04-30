#ifndef ARRAYLISTB_H
#define ARRAYLISTB_H
#include "Baraja.h"

class ArrayListB{
	public:
	    ArrayListB();
		ArrayListB(int pMax);
		virtual ~ArrayListB();
		Baraja* getValue();
		int getPos();
		int getSize();
		void goToStart();
		void goToEnd();
		void goToPos(int pos);
		void previous();
		void next();
		void append(Baraja* element);
		void insert(Baraja* element);
		Baraja* remove();
		void print();
		void clear();

	protected:
		Baraja *elements[];
		int max;
		int size;
		int pos;
};
#endif
