#ifndef INDEXER_H
#define INDEXER_H

// All class declarations
class Log;
class PlayerLog;
class User;
class Question;
class MCQQuestion;
class TFQuestion;
class CompleteQuestion;

// All function definitions
void ReadFromFile(string);
void GetFileNameFromUser();
void DisplayQuestion(Question, int);
void DisplayQuestionWithAnswers(Question, int);
void ShuffleQuestionPool();
void ShuffleAnswers(vector<string>&);
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
bool CheckCurrentQuestionPoolSize(int, int);
bool CheckAnswerValidity(const Question &, const string &);
bool CreateQuestion();
bool RandomiseAndPrintAnswers(Question);
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