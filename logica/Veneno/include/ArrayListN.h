#ifndef ARRAYLISTN_H
#define ARRAYLISTN_H

class ArrayListN
{
	public:
	    ArrayListN();
		ArrayListN(int pMax);
		virtual ~ArrayListN();
		int getValue();
		int getPos();
		int getSize();
		void goToStart();
		void goToEnd();
		void goToPos(int pos);
		void previous();
		void next();
		void append(int element);
		void insert(int element);
		int remove();
		void print();
		void clear();

	protected:
		int *elements;
		int max;
		int size;
		int pos;
};
#endif // ARRAYLISTN_H
