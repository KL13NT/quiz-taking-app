#ifndef INDEXER_H
#define INDEXER_H

// All class definitions
class Question;
class User;
class CompleteQuestion;
class TFQuestion;
class MCQQuestion;
class Log;
class PlayerLog;
class Quiz;

int ctoi(const string &);

bool IsDuplicateUser(string);
bool IsDuplicateQuestion(const string &);
bool CheckCurrentQuestionPoolSize(int);
bool StringIsEqualIgnoreCase(const string &, const string &);
bool StringIsEqual(const string &, const string &);
bool VerifyChoice(string &, string &);
bool VerifyAnswer(const Question &, string &);
bool CheckAnswerValidity(const Question &, const string &);
bool CheckUserAnswer(const Question &, string &);

string GetUserInput(string);
string StringToLowerCase(string);
string StringToUpperCase(string);
string IndentString(const string, const int);
string FormatQuestionTitle(const string &);
string MakeHeader(const string &, int);
string ParseTFAnswer(const string &);
string StringToNumbers(string);
string GetMCQChoice(const Question &, string &);

void ReadFromFile(string);
void GetFileNameFromUser();
void ShuffleQuestionPoolIndices();
void ShuffleAnswerIndices();
void DisplayAllQuestions();
void CreateNewUser();
void DisplayUserStatistics(const User &);
void AdminMenu();
void PlayerMenu();
void MainMenu();
void QuestionsMenuHandler();
void QuestionsMenu();
void AllUsersMenu();
void DisplayAllUsers();
void Login();
void DeleteQuestion(int);
void SwitchAccount();
void DisplayScores();
void UpdateGreeting();
void UpdateAccountDetails();
void DisplayLog(Log &);
void GenerateQuizQuestions(Quiz &);
void QuizDisplayQuestion(Question &, int);
void DisplayQuestionWithAnswers(Question &, int);
void CalculateQuizScores(Quiz &, bool, Question &);
void SaveQuizData(Quiz &);
void StartNewQuiz();

// Question creation
void CreateQuestion();

void LoadMCQQuestion(std::ifstream &, string &);
Question CreateMCQQuestion();

CompleteQuestion LoadCompleteQuestion(std::ifstream &, string &);
Question CreateCompleteQuestion();

TFQuestion LoadTFQuestion(std::ifstream &, string &);
Question CreateTFQuestion();

#endif