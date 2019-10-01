#include "ActionTable.h"
#include "Tape.h"
/*
void ActionTable::turing(int SR, tape T) {
	cout << "HI" << endl;
	for (int i = 0; i <= AT_Size; i += 2) {
		cout << T.read() << endl;
		switch (T.read()) {
		case '0':
			switch (SR) {
			case '1':
				T.write(1);
				SR = 0;
				T.pList();
				break;

			}
			break;
		case '1':
			switch (SR) {
			case '0':
				T.itR();
				T.pList();
				break;
			case '1':
				T.write(0);
				T.itL();
				T.pList();
				break;
			}
			break;
		case 'B':
			switch (SR) {
			case '0':
				SR = 1;
				T.itL();
				T.pList();
				break;
			}
			break;
		}
		return;
	}
}
*/