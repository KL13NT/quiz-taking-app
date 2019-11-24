#ifndef INDEXER_H
#define INDEXER_H


class Question;
class User;
class CompleteQuestion;
class TFQuestion;
class MCQQuestion;

int ctoi(const string &);

bool CreateQuestion();
bool IsDuplicateQuestion(const string &);
bool CheckCurrentQuestionPoolSize(int);
bool CheckAnswerValidity(const Question &, const string &);
bool StringIsEqualIgnoreCase(const string &String1, const string &String2);
bool StringIsEqual(const string &String1, const string &String2);
bool VerifyChoice(string &Type, string &CorrectChoice);

string GetUserInput(string);
string StringToLowerCase(string);
string StringToUpperCase(string);
string IndentString(const string, const int);
string FormatQuestionTitle(const string &);
string MakeHeader(const string &ToPrint, int multiplier);
string ParseTFAnswer(const string &);
string StringToNumbers(string);

// All function definitions
void ReadFromFile(string);
void GetFileNameFromUser();
void ShuffleQuestionPoolIndices();
void ShuffleAnswerIndices();
void DisplayAllQuestions();
void GenerateAfterQuizReport(int);
void CreateNewUser();
void DisplayUserStatistics(const User &);
void AdminMenu();
void MainMenu();
void QuestionsMenu();
void QuestionsMenuHandler();
void AllUsersMenu();
void Login();
void DeleteQuestion(int);
void SwitchAccount();
void DisplayAllUsers();
void DisplayScores();


// Question creation
void LoadMCQQuestion(std::ifstream &, string &);
Question CreateMCQQuestion();

CompleteQuestion LoadCompleteQuestion(std::ifstream &, string &);
Question CreateCompleteQuestion();

TFQuestion LoadTFQuestion(std::ifstream &, string &);
Question CreateTFQuestion();

#endif