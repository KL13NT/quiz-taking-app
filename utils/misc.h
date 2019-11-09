#ifndef MISC_H
#define MISC_H

#include <string>
#include <regex>

using std::string;


// Makes sure question titles match the form
string FormatQuestionTitle(const string &QuestionTitle){
	return std::regex_replace (QuestionTitle, std::regex("\\s?\\?"), "");
}


// Checks whether the question is a duplicate
bool IsDuplicateQuestion(const string &Title){
  return QuestionPoolSet.find(Title) != QuestionPoolSet.end();
}


//Checks if question pool has enough questions >= QUIZ_QUESTIONS_COUNT
bool CheckCurrentQuestionPoolSize(int ExpectedSize) {
	return POOL_QUESTIONS_COUNT >= ExpectedSize;
}


// Checks if supplied answer is the correct choice
bool CheckAnswerValidity(const Question &CurrentQuestion, const string &Answer) {
	return StringToLowerCase(Answer) == StringToLowerCase(CurrentQuestion.CorrectChoice);
}


// // Displays a single question as part of a list
// void DisplayQuestion(const Question &CurrentQuestion, int QuestionIndex) {
// 	cout << "[" << QuestionIndex + 1 << "] " << CurrentQuestion.Title << "?\n";
// }

int ctoi(string str){
	// std::stringstream output;  
	// output << str[0];
	char input = str[0];
	if(input >= '1' && input <= '9') return input - '0';
	else return 0;
}


string MakeHeader(const string &ToPrint, int multiplier){
	return '\n' + string(multiplier, '-') + '\n' + ToPrint + "\n" + string(multiplier, '-') + "\n\n" ;
}

// Determines whether two strings are equal, case-insensitive
bool StringIsEqualIgnoreCase(const string &String1, const string &String2){
	return StringToLowerCase(String1) == StringToLowerCase(String2);
}

// Determines whether two strings are equal, case-sensitive
bool StringIsEqual(const string &String1, const string &String2){
	return String1 == String2;
}

// Verifies if question answers are adequate
bool VerifyChoice(string &Type, string &CorrectChoice){
	bool IsValid = false;

	if(Type == "tf") {
		IsValid = 
			StringIsEqualIgnoreCase("true", CorrectChoice) 
			|| StringIsEqualIgnoreCase("t", CorrectChoice)  
			|| StringIsEqualIgnoreCase("false", CorrectChoice) 
			|| StringIsEqualIgnoreCase("f", CorrectChoice);
	}
	else IsValid = CorrectChoice.length() > 0;

	if(Type == "tf" && IsValid == false) cout << "\nTF question answers should be one of: [T]rue, [F]alse.\n";
	else if(Type == "complete" && IsValid == false) cout << "\nComplete question answers should be a string of more than 0 characters.\n";

	return IsValid;
}

#endif