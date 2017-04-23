#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include "Naipe.h"

class ArrayList{
	public:
	    ArrayList();
		ArrayList(int pMax);
		virtual ~ArrayList();
		Naipe* getValue();
		int getPos();
		int getSize();
		int getMax();
		void goToStart();
		void goToEnd();
		void goToPos(int pos);
		void previous();
		void next();
		void append(Naipe* element);
		void insert(Naipe* element);
		Naipe* remove();
		void removeElement(Naipe* element);
		int find(Naipe* element);
		void print();
        string r_print();
		void clear();

	protected:
		Naipe* elements[1024];
		int max;
		int size;
		int pos;
};
#endif
