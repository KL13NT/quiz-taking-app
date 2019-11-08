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
#include "./indexer.h"

// custom definitions
#include "./structures/index.h"
#include "./globals.h"
#include "./utils/index.h"
#include "./menus.h"



int main() {
	ReadFromFile("exam2_questions.txt");

	// Generates random integers
	for (int i = 0; i < 4; i++) AnswerIndices.push_back(i);

	MainMenu();


	return 0;
}