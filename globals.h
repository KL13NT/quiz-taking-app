#ifndef GLOBALS_H
#define GLOBALS_H


int QUIZ_QUESTIONS_COUNT = 5;
int POOL_QUESTIONS_COUNT = 0;


vector<Question> QuestionPool;
unordered_set<string> QuestionPoolSet; //used for duplicate question detection
vector<int> QuestionPoolIndices; // filled in main
vector<User> Users;
User *UserProfile = &Users[0];

#endif