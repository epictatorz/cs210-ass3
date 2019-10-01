#ifndef Tape_cpp
#define Tape_cpp

#include "Tape.h"


tape::tape()
{
	curr = NULL;
	tip = NULL;
	tail = NULL;
	cnt = 0;
	itrt = false;
}


void tape::resetP()
{
	curr = tip;
}


void tape::itR()
{
	if (curr->next == NULL)
		curr = tip;
	else
		curr = curr->next;
}


void tape::itL()
{
	if (curr->prev == NULL)
		curr = tail;
	else
		curr = curr->prev;
}


bool tape::isPset()
{
	if (curr == NULL)
	{
		cout << "isPset()" << endl;
		return false;
	}
	else
		return true;
}


int tape::getP()
{
	cell* nw = tip;

	int pos = 0;

	while (nw != curr)
	{
		pos++;
		nw = nw->next;
	}

	delete nw;
	return pos;
}


void tape::setP(cell* inD)
{
	isEmpty();

	while (curr->next != NULL && curr != inD)
	{
		curr = curr->next;
	}

	isPset();
}


char tape::read()
{
	isPset();

	return curr->dta;
}


void tape::write(char inD)
{
	curr->dta = inD;
}


int tape::length()
{
	////resetP();

	////cnt = 1;

	////while (curr->next != NULL)
	////{
	////	curr = curr->next;
	////	cnt++;
	////}

	return cnt;
}


bool tape::isEmpty()
{
	if (tip->next == NULL)
		return true;
}


bool tape::isFull()
{
	try { cell* tst = new cell; }

	catch (bad_alloc)
	{
		cout << "List is full" << endl;
		return true;
	}

	return false;
}


//insert



void tape::iHead(char inD)
{
	isFull();

	cell* nw = new cell;

	nw->dta = inD;
	nw->prev = NULL;

	if (tip == NULL) {
		nw->next = NULL;
	}
	else {
		tip->prev = nw;
		nw->next = tip;
	}
	tip = nw;
	curr = tip;
	cnt++;

	/*curr = tip;

	cnt++;

	delete nw;*/
}


void tape::iTail(char inD)
{
	isFull();
	isEmpty();
	isPset();

	cell* nw = new cell;
	nw->dta = inD;
	nw->next = NULL;
	tail = curr->prev;
	while (curr != NULL) {
		tail = curr;
		curr = curr->next;
	}
	tail->next = nw;
	nw->prev = tail;
	curr = nw;
	cnt++;

	/*while (curr->next != NULL)
	{
		curr = curr->next;
	}

	tail = curr;

	cell* nw = new cell;

	nw->dta = inD;
	nw->next = NULL;
	nw->prev = tail;

	tail->next = nw;
	tail = nw;

	curr = tail;

	cnt++;

	delete nw;*/
}
/*

void tape<char>::iSorted(char inD)
{
isFull();
isEmpty();
isPset();

if (inD < curr->dta)
iSortedL(inD);
else if (inD >= curr->dta)
iSortedR(inD);


while (curr->next != NULL && curr->dta < inD)
{
curr = curr->next;
}

cell<char>* nw = new cell<char>;

nw->dta = inD;
nw->next = curr->next;
nw->prev = curr;

curr->next->perv = nw;
curr->next = nw;

delete nw;

}


void tape<char>::iSortedR(char inD)
{
while (curr->next != NULL && curr->dta < inD)
{
curr = curr->next;
}

cell<char>* nw = new cell<char>;

nw->dta = inD;
nw->next = curr->next;
nw->prev = curr;

curr->next->perv = nw;
curr->next = nw;

delete nw;
}


void tape<char>::iSortedL(char inD)
{
while (curr->prev != NULL && curr->dta < inD)
{
curr = curr->prev;
}

cell<char>* nw = new cell<char>;

nw->dta = inD;
nw->next = curr;
nw->prev = curr->prev;

curr->prev->next = nw;
curr->prev = nw;

delete nw;
}

*/
//find



bool tape::find(char inD)
{
	isEmpty();
	resetP();

	while (curr->next != NULL && curr->dta != inD)
	{
		curr = curr->next;
	}

	if (curr->dta == inD)
		return true;
	else
		return false;
}
/*

bool tape<char>::findSorted(char inD)
{
isPset();

if (inD < curr->dta)
findSortedL(inD);
else if (inD > curr->dta)
findSortedR(inD);
else
return true;
}


bool tape<char>::findSortedR(char inD)
{
while (curr->next != NULL && curr->dta != inD)
{
curr = curr->next;
}

if (curr->dta == inD)
return true;
else
return false;
}


bool tape<char>::findSortedL(char inD)
{
while (curr->prev != NULL && curr->dta != inD)
{
curr = curr->prev;
}

if (curr->dta == inD)
return true;
else
return false;
}
*/

//delete



void tape::del()
{
	isPset();

	if (curr->prev == NULL)
		delH();
	else if (curr->next == tail)
		delT();
	else
	{
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
	}

	delete curr;
	cnt--;

	resetP();
}

void tape::delH()
{
	tip = curr->next;
	tip->prev = NULL;
}


void tape::delT()
{
	tail = curr->prev;
	tail->next = NULL;
}


void tape::clear()
{
	while (tip->next != NULL)
	{
		curr = tip;
		tip = tip->next;
		delete curr;
	}
	curr = NULL;
	cnt = 0;
}

#endif
