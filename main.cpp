/*
Team Name: 2Scoops
Members:
	Nabil Tharwat: 20180305
	Amr Samy: 20180187
	Muhammad Hisham Shaarawy: 20180243
	Omar Mustafa: 20180182
Original Repo: https://github.com/KL13NT/quiz-taking-app
*/


#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using std::string;
using std::vector;
using std::unordered_set;
using std::cin;
using std::cout;
using std::endl;

// Definitions reference
#include "indexer.h"

// Structures
#include "structures/index.h"

// Globals
#include "globals.h"

// Utilities and methods
#include "utils/index.h"

// Menus
#include "menus.h"


int main() {
	cout << MakeHeader("Welcome to Quizzy", 20);

	ReadFromFile("exam2_questions.txt");

	MainMenu();

	return 0;
}