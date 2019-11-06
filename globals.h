#ifndef GLOBALS_H
#define GLOBALS_H

int QUIZ_QUESTIONS_COUNT = 5;
int POOL_QUESTIONS_COUNT = 0;
int LOGGEDIN_USER_INDEX = 0;


vector<Question> QuestionPool;
unordered_set<string> QuestionPoolSet; //used for duplicate question detection
vector<int> AnswerIndices; // filled in main before program starts
vector<int> QuestionPoolIndices; // filled in main
vector<User> Users;
User LoggedInUser;

#endif