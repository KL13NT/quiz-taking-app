#ifndef GLOBALS_H
#define GLOBALS_H

// Constants
// QUIZ_QUESTIONS_COUNT should be 5 or its multipliers (10, 15, 20)
const int QUIZ_QUESTIONS_COUNT = 5;

const int MCQCount = (int) (0.4 * QUIZ_QUESTIONS_COUNT);
const int TFCount = (int) (0.4 * QUIZ_QUESTIONS_COUNT);
const int CompleteCount = (int) (0.2 * QUIZ_QUESTIONS_COUNT);
const double HighestPossibleScore = (MCQCount * 2) + TFCount + (CompleteCount * 3);

// Configuration variables
bool IsFirstRun = true;
bool IsLoggedin = false;
int LoggedinUserID = -1;
int POOL_QUESTIONS_COUNT = 0;
int LAST_QUESTION_ID = 0;
string Greeting;

// Storage
vector<int> QuestionPoolIndices; // filled in main
vector<int> AnswerIndices = { 0, 1, 2, 3 };
vector<User> Users;
vector<Question> QuestionPool;
unordered_set<string> QuestionPoolTitles; //used for duplicate question detection
unordered_set<int> QuestionIDs;

#endif
