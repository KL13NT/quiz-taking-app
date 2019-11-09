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
#include <numeric> //accumulate

using std::string;
using std::vector;
using std::unordered_set;
using std::cin;
using std::cout;

// Definitions reference
#include "structures/index.h"

// Function definitions
#include "indexer.h"

// custom methods
#include "globals.h"
#include "utils/index.h"
#include "menus.h"



int main() {
	ReadFromFile("exam2_questions.txt");


	// MainMenu();
	AdminMenu();


	return 0;
}