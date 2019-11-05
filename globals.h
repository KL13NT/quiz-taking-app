#ifndef GLOBALS_H
#define GLOBALS_H

#include <vector>
#include <string>
#include <unordered_set>

#include "./structures/index.h"

using std::vector;
using std::string;
using std::unordered_set;


const int QUIZ_QUESTIONS_COUNT = 5;
int POOL_QUESTIONS_COUNT = 0;

struct Profile {
	string Name = "USER";
	vector<int> Scores; //{2}
	int QuizzesTakenCount = 0;
	int HighestScore = 0;
	int LowestScore = 0;
	float AvgScore = 0.0;
} UserProfile;


vector<Question> QuestionPool;
unordered_set<string> QuestionPoolSet; //used for duplicate question detection
vector<int> AnswerIndices; // filled in main before program starts
vector<int> QuestionPoolIndices; // filled in main

#endif