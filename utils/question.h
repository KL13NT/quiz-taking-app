#ifndef QUESTION_UTILS_H
#define QUESTION_UTILS_H


#include <string>
#include <unordered_set>
#include <vector>
#include <ctime>
#include <chrono> //system_clock
#include <random>	//default_random_engine
#include <algorithm> //shuffle


#include "../structures/question.h"
#include "../globals.h"


using std::cout;
using std::vector;
using std::string;
using std::unordered_set;


// Checks whether the question is a duplicate
bool IsDuplicateQuestion(const Question &CurrentQuestion, const unordered_set<string> &QuestionPoolSet){
	auto QuestionIterator = QuestionPoolSet.find(CurrentQuestion.Title);
	
  if(QuestionIterator != QuestionPoolSet.end()) return true;
  return false;
}


//Checks if question pool has enough questions >= QUIZ_QUESTIONS_COUNT
bool CheckCurrentQuestionPoolSize(int ExpectedSize, int POOL_QUESTIONS_COUNT) {
	if (POOL_QUESTIONS_COUNT >= ExpectedSize) return true;
	return false;
}


// Shuffles question pool
void ShuffleQuestionPool() {
	vector<Question> NewPool;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(QuestionPoolIndices.begin(), QuestionPoolIndices.end(), std::default_random_engine(seed));

	for (int i = 0; i < POOL_QUESTIONS_COUNT; i++) NewPool.push_back(QuestionPool[QuestionPoolIndices[i]]); // Copies pool away randomly
	for (int i = 0; i < POOL_QUESTIONS_COUNT; i++) QuestionPool[i] = NewPool[i]; // Copies randomised questions over again
}


// Shuffles answers
void ShuffleAnswers(vector<string>(&Answers)) {
	vector<string> NewAnswers;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(AnswerIndices.begin(), AnswerIndices.end(), std::default_random_engine(seed));

	for (int i = 0; i < 4; i++) NewAnswers.push_back(Answers[AnswerIndices[i]]); // Copies pool away randomly
	for (int i = 0; i < 4; i++) Answers[i] = NewAnswers[i]; // Copies randomised questions over again
}


// Checks if supplied answer is the correct choice
bool CheckAnswerValidity(const Question &CurrentQuestion, const string &Answer) {
	if (Answer == CurrentQuestion.CorrectChoice) {
		return true;
	}
	else return false;
}


MCQQuestion LoadMCQQuestion(std::ifstream &File, std::string &Line){
	MCQQuestion CurrentQuestion;
	
	getline(File, Line);
	CurrentQuestion.Title = Line;

	getline(File, Line);
	CurrentQuestion.CorrectChoice = Line;

	getline(File, Line);
	CurrentQuestion.Choice2 = Line;

	getline(File, Line);
	CurrentQuestion.Choice3 = Line;

	getline(File, Line);
	CurrentQuestion.Choice4 = Line;

	return CurrentQuestion;
}


CompleteQuestion LoadCompleteQuestion(std::ifstream &File, std::string &Line){
	CompleteQuestion CurrentQuestion;
	
	getline(File, Line);
	Title = Line;
	
	getline(File, Line);
	CorrectChoice = Line;

	return CurrentQuestion
}


TFQuestion LoadTFQuestion(std::ifstream &File, std::string &Line){
	TFQuestion CurrentQuestion;

	getline(File, Line);
	Title = Line;
	
	getline(File, Line);
	CorrectChoice = Line;

	return CurrentQuestion;
}


MCQQuestion CreateMCQQuestion(){
	MCQQuestion CurrentQuestion;

	CurrentQuestion.Title = GetUserInput("Enter Question without the question mark");
	CurrentQuestion.CorrectChoice = GetUserInput("Enter the correct choice");
	CurrentQuestion.Choice2 = GetUserInput("Second Choice");
	CurrentQuestion.Choice3 = GetUserInput("Third Choice");
	CurrentQuestion.Choice4 = GetUserInput("Last Choice");

	return CurrentQuestion;
}


CompleteQuestion CreateCompleteQuestion(){
	CompleteQuestion CurrentQuestion;

	CurrentQuestion.Title = GetUserInput("Enter Question without the question mark");
	CurrentQuestion.CorrectChoice = GetUserInput("Enter the correct choice");

	return CurrentQuestion;
}


TFQuestion CreateMCQQuestion(){
	TFQuestion CurrentQuestion;

	CurrentQuestion.Title = GetUserInput("Enter Question without the question mark");
	CurrentQuestion.CorrectChoice = GetUserInput("Enter the correct choice");

	return CurrentQuestion;
}

//Controls the addition of new questions
// void AddQuestion() {
// 	//TODO: modify this to reflect changes
// 	Question NewQuestion;

// 	NewQuestion.Title = GetUserInput("Question without question mark");
// 	NewQuestion.CorrectChoice = GetUserInput("Correct Choice");
// 	NewQuestion.Choice2 = GetUserInput("Second Choice");
// 	NewQuestion.Choice3 = GetUserInput("Third Choice");
// 	NewQuestion.Choice4 = GetUserInput("Last Choice");
// 	cout << "\nAdded new question: " << NewQuestion.Title << "\n\n";
// 	QuestionPool.push_back(NewQuestion);

// 	POOL_QUESTIONS_COUNT += 1;
// 	QuestionPoolIndices.push_back(POOL_QUESTIONS_COUNT - 1);
// }


// Displays a single question as part of a list
void DisplayQuestion(Question CurrentQuestion, int QuestionIndex) {
	cout << "[" << QuestionIndex + 1 << "] " << CurrentQuestion.Title << "?\n";
}


// Displays a question followed by its answers
// void DisplayQuestionWithAnswers(Question CurrentQuestion, int QuestionIndex) {
// 	DisplayQuestion(CurrentQuestion, QuestionIndex);

// 	vector<string> Answers = { CurrentQuestion.CorrectChoice, CurrentQuestion.Choice2, CurrentQuestion.Choice3, CurrentQuestion.Choice4 };
// 	string Labels[] = { "[a] ", "[b] ", "[c] ", "[d] " };
// 	ShuffleAnswers(Answers);

// 	for (int i = 0; i < 4; i++) {
// 		string AnswerWithLabel;

// 		if (Answers[i] == CurrentQuestion.CorrectChoice) {
// 			AnswerWithLabel += '*';
// 			AnswerWithLabel += Labels[i] + Answers[i];
// 		}
// 		else AnswerWithLabel += Labels[i] + Answers[i];

// 		cout << IndentString(AnswerWithLabel, 1);
// 	}

// 	cout << "\n\n";

// 	// cout << IndentString("*[a] ", 1) <<  << IndentString("[b] ", 1) <<  << IndentString("[c] ", 1) <<  << IndentString("[d] ", 1) <<  << "\n\n";
// }




// Randomises passed question answers and returns true if the user chose correctly
// bool RandomiseAndPrintAnswers(Question CurrentQuestion) {
// 	vector<string> Answers{ CurrentQuestion.CorrectChoice, CurrentQuestion.Choice2, CurrentQuestion.Choice3, CurrentQuestion.Choice4 };

// 	ShuffleAnswers(Answers);

// 	cout << IndentString("[a] ", 1) << Answers[0] << IndentString("[b] ", 1) << Answers[1] << IndentString("[c] ", 1) << Answers[2] << IndentString("[d] ", 1) << Answers[3] << "\n\n";

// 	bool IsAnswerCorrect;
// 	bool IsValidChoice = false;
// 	do {
// 		switch (GetUserInput("Answer letter")) {
// 		case 'a':
// 			IsAnswerCorrect = CheckAnswerValidity(CurrentQuestion, Answers[0]);
// 			IsValidChoice = true;
// 			break;
// 		case 'b':
// 			IsAnswerCorrect = CheckAnswerValidity(CurrentQuestion, Answers[1]);
// 			IsValidChoice = true;
// 			break;
// 		case 'c':
// 			IsAnswerCorrect = CheckAnswerValidity(CurrentQuestion, Answers[2]);
// 			IsValidChoice = true;
// 			break;
// 		case 'd':
// 			IsAnswerCorrect = CheckAnswerValidity(CurrentQuestion, Answers[3]);
// 			IsValidChoice = true;
// 			break;
// 		default:
// 			IsValidChoice = false;
// 		}
// 	} while (IsValidChoice == false);

// 	return IsAnswerCorrect;
// }



//Displays all quesitons in the question pool
//void DisplayAllQuestions() {
//	for (int i = 0; i < POOL_QUESTIONS_COUNT; i++) {
//		DisplayQuestionWithAnswers(QuestionPool[i], i);
//	}
//}



bool DeleteQuestion(int QuestionIndex){
	if (QuestionIndex <= POOL_QUESTIONS_COUNT) {
			std::cout << "\nDeleted the following question: " << QuestionPool[QuestionIndex - 1].QuestionTitle << "\n\n";

			std::vector<Question>::iterator it = QuestionPool.begin();
			std::vector<int>::iterator rit = QuestionPoolIndices.begin();
			std::advance(it, QuestionIndex-1);
			std::advance(rit, QuestionIndex-1);
			QuestionPool.erase(it);
			QuestionPoolIndices.erase(rit);
			POOL_QUESTIONS_COUNT -= 1;
			for (int i = 0; i < POOL_QUESTIONS_COUNT; i++) {
				QuestionPoolIndices[i] = i;
			}
			return true;
		}
		else {
			std::cout << "We didn't quite catch that, try again, perhaps?\n\n";
			return false;
		}
}


#endif