#include "TTextLink.h"
#include <iostream>
using namespace std;

TTextMem TTextLink::MemHeader;
void printMenu() {
	cout << "Text Editor" << endl;
	cout << "Commands:" << endl;
	cout << " 1 - Read text from file" << endl;
	cout << " 2 - Print text on console" << endl;
	cout << " 3 - Save text to file" << endl;
	cout << " 4 - Go to first line" << endl;
	cout << " 5 - Go to next line" << endl;
	cout << " 6 - Go to down line" << endl;
	cout << " 7 - Go to previous line" << endl;
	cout << " 8 - Edit current line" << endl;
	cout << " 9 - Add a line to this level" << endl;
	cout << "10 - Add a line to down level" << endl;
	cout << "11 - Add a section to this level" << endl;
	cout << "12 - Add a section to down level" << endl;
	cout << "13 - Delete line from this level" << endl;
	cout << "14 - Delete line from down level" << endl;
	cout << "15 - Exit" << endl << endl;
}

int main() {
	TTextLink::InitMemSystem(100);
	try {
		int choice;
		string new_line;
		TText text;
		printMenu();
		do {
			cin >> choice;
			switch(choice) {
			case 1: {
				cout << "Enter file name" << endl;
				getline(cin >> ws, new_line);
				ifstream ifs(new_line);
				text.Read(new_line);
				break;
			}
			case 2:
				cout << text;
				break;
			case 3:
				cout << "Enter file name" << endl;
				getline(cin >> ws, new_line);
				text.Write(new_line);
				break;
			case 4:
				text.GoFirstLink();
				break;
			case 5:
				text.GoNextLink();;
				break;
			case 6:
				text.GoDownLink();
				break;
			case 7:
				text.GoPrevLink();
				break;
			case 8:
				cout << "Enter new line" << endl;
				getline(cin >> ws, new_line);
				text.SetLine(new_line);
				break;
			case 9:
				cout << "Enter new line" << endl;
				getline(cin >> ws, new_line);
				text.InsNextLine(new_line);
				cout << endl;
				break;
			case 10:
				cout << "Enter new line" << endl;
				getline(cin >> ws, new_line);
				text.InsDownLine(new_line);
				cout << endl;
				break;
			case 11:
				cout << "Enter new line" << endl;
				getline(cin >> ws, new_line);
				text.InsNextSection(new_line);
				cout << endl;
				break;
			case 12:
				cout << "Enter new line" << endl;
				getline(cin >> ws, new_line);
				text.InsDownSection(new_line);
				cout << endl;
				break;
			case 13:
				text.DelNext();
				break;
			case 14:
				text.DelDown();
				break;
			case 15: 
				cout << "End of session" << endl;
				break;
			}
			system("cls");
			printMenu();
			cout << text;

		} while (choice != 15);
		
	}
	catch (int a) {
		cout << "oof" << endl;
	}
}