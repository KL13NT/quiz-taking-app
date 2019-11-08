#ifndef INDEXER_H
#define INDEXER_H

#include "structures/index.h"

// All function definitions
void ReadFromFile(string);
void GetFileNameFromUser();
void ShuffleQuestionPool();
void DisplayAllQuestions();
void GenerateAfterQuizReport(int);
void UpdateProfileAfterQuiz(int);
void CreateNewUser();
void DisplayUserStatistics(const User &);
void AdminMenu();
void MainMenu();
void QuestionsMenu();
void QuestionsMenuHandler();
void AllUsersMenu();
void Login(const User &);

bool CheckCurrentQuestionPoolSize(int, int);
bool CheckAnswerValidity(const Question &, const string &);
bool CreateQuestion();
// bool RandomiseAndPrintAnswers(Question);
bool DeleteQuestion(int);
bool IsDuplicateQuestion(const Question &, const unordered_set<string> &);

string GetUserInput(string);
string StringToLowerCase(string);
string StringToUpperCase(string);
string IndentString(const string, const int);
string FormatQuestionTitle(string);

MCQQuestion LoadMCQQuestion(std::ifstream &, string &);
MCQQuestion CreateMCQQuestion();

CompleteQuestion LoadCompleteQuestion(std::ifstream &, string &);
CompleteQuestion CreateCompleteQuestion();

TFQuestion LoadTFQuestion(std::ifstream &, string &);
TFQuestion CreateTFQuestion();

#endif