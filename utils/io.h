#ifndef IO_H
#define IO_H


#include <string>
#include <iostream>


using std::string;
using std::cout;
using std::cin;

// Takes user input string and returns it
string GetUserString(string Additional = "  ") {
	string Input;
	if (Additional != "  ") {
		cout << Additional << ": ";
		getline(cin, Input);
		return Input;
	}
	getline(cin, Input);
	cout << "\n";
	return Input;
}


// Takes integer and returns it
int GetUserInt(string Additional = "  ") {
	int InputChar;
	if (Additional != "  ") {
		cout << Additional << ": ";
		cin >> InputChar;
		cin.ignore(1000, '\n');
		return InputChar;
	}
	cin >> InputChar;
	cin.ignore(1000, '\n');
	cout << "\n";
	return InputChar;
}


// Gets a character from the user
char GetUserChar(string Additional = "  ") {
	char InputChar;
	if (Additional != "  ") {
		cout << Additional << ": ";
		cin >> InputChar;
		cin.ignore(1000, '\n');
		cout << "\n";
		return InputChar;
	}
	cin >> InputChar;
	cin.ignore(1000, '\n');
	cout << "\n";
	return InputChar;
}

#endif