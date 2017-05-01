#ifndef ARRAYLISTC_H
#define ARRAYLISTC_H

class ArrayListC
{
	public:
	    ArrayListC();
		ArrayListC(int pMax);
		virtual ~ArrayListC();
		char getValue();
		void setValue(char element);
		int getPos();
		int getSize();
		void goToStart();
		void goToEnd();
		char goToPos(int pos);
		void previous();
		void next();
		void append(char element);
		void insert(char element);
		int remove();
		void print();
		void clear();

	protected:
		char *elements;
		int max;
		int size;
		int pos;
};
#endif // ARRAYLISTN_H
