#include <iostream>
#include <cstdlib>
#include <string>

#ifndef Tape_h
#define Tape_h

using namespace std;

struct cell
{
	cell* prev;
	cell* next;

	char dta;
};

class tape
{
	cell* curr;
	cell* tip;
	cell* tail;

	int cnt;
	bool itrt;

	//insert

	void iSortedR(char);
	void iSortedL(char);

	//find

	bool findSortedR(char);
	bool findSortedL(char);

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
	void setP(cell*);
	char read();
	void write(char);
	int length();
	bool isEmpty();
	bool isFull();

	//insert

	void iHead(char);
	void iTail(char);
	// void iSorted(bn);

	//find

	bool find(char);
	//bool findSorted(bn);

	//delete

	void del();
	void clear();
};
#endif

#include "Tape.cpp"
