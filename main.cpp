#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "ActionTable.h"
#include "Tape.h"
using namespace std;

//const int AT_Size = 25;
//void turing(int, ActionTable, tape);

int main() {
	int PtrPos;
	bool exit = false;
	char choice;
	while (exit == false) {							//simple menu system
		cout << "Please enter a choice." << endl;
		cout << "1: Count File" << endl;
		cout << "2: Subtract File" << endl;
		cout << "3: Exit" << endl;
		cin >> choice;
		switch (choice) {
		case '1': {
			PtrPos = 0;
			int StateRegister;
			tape T;
			ActionTable AT[AT_Size];
			string Text = "problem.txt";	//sets file name
			string Line;


			ifstream problem;				//opens the file
			problem.open(Text);

			getline(problem, Line);
			StateRegister = Line[0]- '0';		//initilizes the StateRegister

			getline(problem, Line);
			unsigned int count = 2;

			T.iHead(Line[0]);
			while (count <= Line.length() + 1) {
				T.iTail(Line[count]);
				count += 2;
			}

			char Symbol = '0';
			while (Symbol != '-') {			//this loop initilizes the Action Table
				int i = 0;
				getline(problem, Line);
				//cout << Line << endl;
				Symbol = Line[0];			//gets the first character in the list and sees if it is '-' to end the 
				if (Symbol == '-') {		//initilizing of the Action Table
					break;
				}
				AT[i].CurrentState = int(Line[0]) - 48;		//must subtract 48 to convert the ASCII code to integers
				AT[i].Symbol = Line[2];				//skips odds as they are spaces ' '
				AT[i].NextState = int(Line[4]) - 48;
				AT[i].NewSymbol = Line[6];
				AT[i].Direction = Line[8];
				//cout << AT[i].CurrentState << AT[i].Symbol << AT[i].NextState << AT[i].NewSymbol << AT[i].Direction << endl;
				i++;
			}
			getline(problem, Line);
			//cout << Line << endl;
			for (int i = 0; i < (Line[0] - '0'); i++){
				T.itR();
				PtrPos += 1;
			}
			cout<< endl;
			//T.pList(PtrPos);
			problem.close();
			for (int j = 0; j < 5; j++) {
				T.pList(PtrPos);
				cout << "Value: " << T.read()  << "  StateRegister:" << StateRegister << endl << endl;
				switch (T.read()) {
				case '0':
					switch (StateRegister) {
					case 1:
						T.write('1');
						//T.pList(PtrPos);
						StateRegister = 0;
						break;
					}
					break;
				case '1':
					switch (StateRegister) {
					case 0:
						T.itR();
						PtrPos++;
						//T.pList(PtrPos);
						break;
					case 1:
						T.write('0');
						T.itL();
						PtrPos--;
						//T.pList(PtrPos);
						break;
					}
					break;
				case 'B':
					switch (StateRegister) {
					case 0:
						//T.pList(PtrPos);
						T.itL();
						PtrPos--;
						StateRegister = 1;
						break;
					case 1:
						int x = 1;
					}
					break;
				}
			}



			//turing(StateRegister, AT[AT_Size], T);
			break;
		}
		case '2':
			void subtract();
			break;
		case '3':
			exit = true;
			break;
		default:
			cout << "Invalid choice." << endl;
		}
	}
	return 0;
}
//void turing(int SR, ActionTable AT, tape T) {
	/*for (int i = 0; i <= AT_Size; i++) {
		switch()
	}*/
//}
/*
void subtract() {
	int StateRegister;
	ActionTable AT[AT_Size];
	string Text = "problem.txt";
	string Line;

	ifstream problem;
	problem.open(Text);
	getline(problem, Line);
	StateRegister = Line[1];		//initilizes the StateRegister

	char Symbol = '0';
	while (Symbol != '-') {			//this loop initilizes the Action Table
		int i = 0;
		getline(problem, Line);
		//test line	cout << Line << endl;
		Symbol = Line[0];			//gets the first character in the list and sees if it is '-' to end the 
		if (Symbol == '-') {		//initilizing of the Action Table
			break;
		}
		AT[i].CurrentState = int(Line[0]) - 48;		//must subtract 48 to convert the ASCII code to integers
		AT[i].Symbol = int(Line[2]);				//skips odds as they are spaces ' '
		AT[i].NextState = Line[4] - 48;
		AT[i].NewSymbol = Line[6];
		AT[i].Direction = Line[8];
		//test line cout << AT1[i].CurrentState << AT1[i].Symbol << AT1[i].NextState << AT1[i].NewSymbol << AT1[i].Direction << endl;
		i++;
	}

	problem.close();
}
*/
