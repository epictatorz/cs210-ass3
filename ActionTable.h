#ifndef ActionTable_h
#define ActionTable_h
#include "Tape.h"

const int AT_Size = 25;
struct ActionTable {
	int CurrentState;	// value of current cell
	char Symbol;		// B = blank
	int NextState;		// value of next cell
	char NewSymbol;		// symbol to insert
	char Direction;		// L = left, R = right, '-' = no movement, H = hault
	//void turing(int, tape);
};
#endif
