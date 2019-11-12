#ifndef GLOBALS_H
#define GLOBALS_H

// QUIZ_QUESTIONS_COUNT should be 5 or its multipliers (10, 15, 20)
const int QUIZ_QUESTIONS_COUNT = 5;
const double MCQCount = 0.4 * QUIZ_QUESTIONS_COUNT;
const double TFCount = 0.4 * QUIZ_QUESTIONS_COUNT;
const double CompleteCount = 0.2 * QUIZ_QUESTIONS_COUNT;
const double HighestPossibleScore = (MCQCount * 2) + TFCount + (CompleteCount * 3);
int POOL_QUESTIONS_COUNT = 0;

vector<int> QuestionPoolIndices; // filled in main
vector<int> AnswerIndices = { 0, 1, 2, 3 };
vector<User> Users;
vector<Question> QuestionPool;
unordered_set<string> QuestionPoolSet; //used for duplicate question detection
User *UserProfile;
bool IsLoggedin = false;
bool IsFirstRun = true;
string Greeting;

#endif