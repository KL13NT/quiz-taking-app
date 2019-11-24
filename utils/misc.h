#ifndef MISC_H
#define MISC_H

#include <string>
#include <regex>

using std::string;


// Makes sure question titles match the form
string FormatQuestionTitle(const string &QuestionTitle){
	return std::regex_replace (QuestionTitle, std::regex("(!*)(\\s?\\?)(!*)"), "");
}

// Leaves only numbers
string StringToNumbers(string StringToReplace){
	return std::regex_replace (StringToReplace, std::regex("[^0-9]"), "");
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

// Parses [f | t | false | true] to their respective uppercase string
string ParseTFAnswer(const string &Answer){
	if(Answer == "f" || Answer == "false") return "FALSE";
	else if(Answer == "t" || Answer == "true") return "TRUE";
}

// Converts a character into an integer ranging from 1 to 9. Used for menus
int ctoi(string InputString){
	if(InputString.length() > 0){
		char Input = InputString[0];
		
		if(Input >= '0' && Input <= '9') return Input - '0';
	} 
	
	return -1;
}

// Shuffles question pool
void ShuffleQuestionPool() {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(QuestionPoolIndices.begin(), QuestionPoolIndices.end(), std::default_random_engine(seed));
}

// Shuffles answers
void ShuffleAnswers() {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(AnswerIndices.begin(), AnswerIndices.end(), std::default_random_engine(seed));
}

string MakeHeader(const string &ToPrint, int Multiplier){
	int OutMultiplier = Multiplier == 0? 20: Multiplier;
	return '\n' + string(OutMultiplier, '-') + '\n' + ToPrint + "\n" + string(OutMultiplier, '-') + "\n" ;
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