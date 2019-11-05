#ifndef GLOBALS_H
#define GLOBALS_H

#include <vector>
#include <string>
#include <unordered_set>

#include "./structures/index.h"

using std::vector;
using std::string;
using std::unordered_set;


int QUIZ_QUESTIONS_COUNT = 5;
int POOL_QUESTIONS_COUNT = 0;
int LOGGEDIN_USER_INDEX = 0;


vector<Question> QuestionPool;
unordered_set<string> QuestionPoolSet; //used for duplicate question detection
vector<int> AnswerIndices; // filled in main before program starts
vector<int> QuestionPoolIndices; // filled in main
vector<User> Users;
unordered_set<string> UserUsernames; 
User LoggedInUser;

#endif