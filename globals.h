#ifndef GLOBALS_H
#define GLOBALS_H


const int QUIZ_QUESTIONS_COUNT = 5;
int POOL_QUESTIONS_COUNT = 0;


vector<Question> QuestionPool;
unordered_set<string> QuestionPoolSet; //used for duplicate question detection
vector<int> QuestionPoolIndices; // filled in main
vector<int> AnswerIndices = { 0, 1, 2, 3 };
vector<User> Users;
User *UserProfile;
bool IsLoggedin = false;
bool IsFirstRun = false;

#endif