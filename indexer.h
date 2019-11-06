#ifndef INDEXER_H
#define INDEXER_H


void ReadFromFile(string FileName);
void GetFileNameFromUser();
std::string GetUserInput(std::string Additional = "  ");
bool IsDuplicateQuestion(const Question &CurrentQuestion, const unordered_set<string> &QuestionPoolSet);
bool CheckCurrentQuestionPoolSize(int ExpectedSize, int POOL_QUESTIONS_COUNT);
void ShuffleQuestionPool();
void ShuffleAnswers(vector<string>(&Answers));
bool CheckAnswerValidity(const Question &CurrentQuestion, const string &Answer);
MCQQuestion LoadMCQQuestion(std::ifstream &File, std::string &Line);
CompleteQuestion LoadCompleteQuestion(std::ifstream &File, std::string &Line);
TFQuestion LoadTFQuestion(std::ifstream &File, std::string &Line);
MCQQuestion CreateMCQQuestion();
CompleteQuestion CreateCompleteQuestion();
TFQuestion CreateTFQuestion();
bool CreateQuestion();
void DisplayQuestion(Question CurrentQuestion, int QuestionIndex);
// void DisplayQuestionWithAnswers(Question CurrentQuestion, int QuestionIndex);
// bool RandomiseAndPrintAnswers(Question CurrentQuestion);
// bool DeleteQuestion(int QuestionIndex);
//void DisplayAllQuestions();
void GenerateAfterQuizReport(int CorrectAnswers);
// void UpdateProfileAfterQuiz(int CorrectAnswers);
string StringToLowerCase(string StringToChange);
string StringToUpperCase(string StringToChange);
string IndentString(const string sentence, const int indent);
void CreateNewUser();
string FormatQuestionTitle(string QuestionTitle);

#endif