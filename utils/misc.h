#ifndef MISC_H
#define MISC_H

#include <regex>
#include <string>

using std::string;


// Makes sure question titles match the form
string FormatQuestionTitle(string QuestionTitle){
  return std::regex_replace (QuestionTitle, std::regex("\\s?\\?"), "");
}


// Checks whether the question is a duplicate
bool IsDuplicateQuestion(const string Title, const unordered_set<string> &QuestionPoolSet){
  if(QuestionPoolSet.find(Title) != QuestionPoolSet.end()) return true;
  return false;
}


//Checks if question pool has enough questions >= QUIZ_QUESTIONS_COUNT
bool CheckCurrentQuestionPoolSize(int ExpectedSize, int POOL_QUESTIONS_COUNT) {
	if (POOL_QUESTIONS_COUNT >= ExpectedSize) return true;
	return false;
}


// Checks if supplied answer is the correct choice
bool CheckAnswerValidity(const Question &CurrentQuestion, const string &Answer) {
	if (Answer == CurrentQuestion.CorrectChoice) {
		return true;
	}
	else return false;
}

bool StringIsEqual(string String1, string String2){
	if(String1 == String2) return true;
	return false;
}


// Displays a single question as part of a list
void DisplayQuestion(Question CurrentQuestion, int QuestionIndex) {
	cout << "[" << QuestionIndex + 1 << "] " << CurrentQuestion.Title << "?\n";
}

int ctoi(string str){
	// std::stringstream output;  
	// output << str[0];
	char input = str[0];
	if(input >= '1' && input <= '9') return input - '0';
	else return 0;
}

string MakeHeader(const string &ToPrint){
	return string(20, '-') + '\n' + ToPrint + "\n" + string(20, '-') + '\n';
}

#endif