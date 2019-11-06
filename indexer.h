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
void ReadFromFile(string FileName);
void GetFileNameFromUser();
void DisplayQuestion(Question CurrentQuestion, int QuestionIndex);
void DisplayQuestionWithAnswers(Question CurrentQuestion, int QuestionIndex);
void ShuffleQuestionPool();
void ShuffleAnswers(vector<string>(&Answers));
void DisplayAllQuestions();
void GenerateAfterQuizReport(int CorrectAnswers);
void UpdateProfileAfterQuiz(int CorrectAnswers);
void CreateNewUser();
bool CheckCurrentQuestionPoolSize(int ExpectedSize, int POOL_QUESTIONS_COUNT);
bool CheckAnswerValidity(const Question &CurrentQuestion, const string &Answer);
bool CreateQuestion();
bool RandomiseAndPrintAnswers(Question CurrentQuestion);
bool DeleteQuestion(int QuestionIndex);
bool IsDuplicateQuestion(const Question &CurrentQuestion, const unordered_set<string> &QuestionPoolSet);
string GetUserInput(std::string Additional = "  ");
string StringToLowerCase(string StringToChange);
string StringToUpperCase(string StringToChange);
string IndentString(const string sentence, const int indent);
string FormatQuestionTitle(string QuestionTitle);
MCQQuestion LoadMCQQuestion(std::ifstream &File, std::string &Line);
MCQQuestion CreateMCQQuestion();
CompleteQuestion LoadCompleteQuestion(std::ifstream &File, std::string &Line);
CompleteQuestion CreateCompleteQuestion();
TFQuestion LoadTFQuestion(std::ifstream &File, std::string &Line);
TFQuestion CreateTFQuestion();

#endif