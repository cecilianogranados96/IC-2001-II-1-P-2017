#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include "ArrayListC.h"
#include <cstddef>
#include <string>

using namespace std;

class ArrayList{
	public:
	    ArrayList();
		ArrayList(int pMax);
		virtual ~ArrayList();
		ArrayListC* getValue();
		int getPos();
		int getSize();
		int getMax();
		void goToStart();
		void goToEnd();
		ArrayListC* goToPos(int pos);
		void previous();
		void next();
		void append(ArrayListC*  element);
		void insert(ArrayListC*  element);
		ArrayListC* remove();
		void removeElement(ArrayListC* element);
		int find(ArrayListC* element);
		void print();
        string r_print();
		void clear();

	protected:
		ArrayListC* elements[4];
		int max;
		int size;
		int pos;
};
#endif
