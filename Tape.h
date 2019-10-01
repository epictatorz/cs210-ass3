#include <iostream>
#include <cstdlib>
#include <string>

#ifndef tape_h
#define tape_h

using namespace std;

template <typename bn>
struct cell
{
	cell<bn>* prev = new cell<bn>;
	cell<bn>* next = new cell<bn>;

	bn* dta = new bn;
};

template <typename bn>
class tape
{
	cell<bn>* curr;
	cell<bn>* tip;
	cell<bn>* tail;

	int* cnt;
	bool* itrt;

	//insert

	void iSortedR(bn);
	void iSortedL(bn);

	//find

	bool findSortedR(bn);
	bool findSortedL(bn);

	//delete

	void delH();
	void delT();

public:

	tape();
	void resetP();
	void itR();
	void itL();
	bool isPset();
	int getP();
	void setP(bn);
	bn read();
	void write(bn);
	int length();
	bool isEmpty();
	bool isFull();

	//insert

	void iHead(bn);
	void iTail(bn);
	 // void iSorted(bn);

	//find

	//bool find(bn);
	//bool findSorted(bn);

	//delete

	void del();
	void clear();
};

#endif
