#ifndef ActionTable_h
#define ActionTable_h

struct ActionTable {
	int CurrentState;	// value of current cell
	char Symbol;		// B = blank
	int NextState;		// value of next cell
	char NewSymbol;		// symbol to insert
	char Direction;		// L = left, R = right, '-' = no movement, H = hault
};
#endif
