#ifndef INDEXER_H
#define INDEXER_H

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
void Login();

bool CheckCurrentQuestionPoolSize(int, int);
bool CheckAnswerValidity(const Question &, const string &);
bool CreateQuestion();
// bool RandomiseAndPrintAnswers(Question);
bool DeleteQuestion(int);
bool IsDuplicateQuestion(const string, const unordered_set<string> &);

string GetUserInput(string);
string StringToLowerCase(string);
string StringToUpperCase(string);
string IndentString(const string, const int);
string FormatQuestionTitle(string);

void LoadMCQQuestion(std::ifstream &, string &);
Question CreateMCQQuestion();

CompleteQuestion LoadCompleteQuestion(std::ifstream &, string &);
Question CreateCompleteQuestion();

TFQuestion LoadTFQuestion(std::ifstream &, string &);
Question CreateTFQuestion();

#endif