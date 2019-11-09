#ifndef QUESTION_UTILS_H
#define QUESTION_UTILS_H

#include <ctime>
#include <chrono> //system_clock
#include <random>	//default_random_engine
#include <algorithm> //shuffle

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

// Loads a "MCQ" question using an ifstream  
MCQQuestion LoadMCQQuestion(std::ifstream &File, string &Line, string Title){
	getline(File, Line);
	string CorrectChoice = Line;

	getline(File, Line);
	string Choice2 = Line;

	getline(File, Line);
	string Choice3 = Line;

	getline(File, Line);
	string Choice4 = Line;

	return MCQQuestion(Title, CorrectChoice, Choice2, Choice3, Choice4, POOL_QUESTIONS_COUNT);
}

// Loads a "complete" question using an ifstream  
CompleteQuestion LoadCompleteQuestion(std::ifstream &File, std::string &Line, string Title){
	getline(File, Line);
	string CorrectChoice = Line;

	return CompleteQuestion(Title, CorrectChoice, POOL_QUESTIONS_COUNT);
}

// Loads a "TF" question using an ifstream  
TFQuestion LoadTFQuestion(std::ifstream &File, std::string &Line, string Title){
	getline(File, Line);
	string CorrectChoice = Line;

	return TFQuestion(Title, CorrectChoice, POOL_QUESTIONS_COUNT);
}

// Creates a question
MCQQuestion CreateMCQQuestion(string Title, string CC){
	string C2 = GetUserInput("Enter choice 2");
	string C3 = GetUserInput("Enter choice 3");
	string C4 = GetUserInput("Enter choice 4");
	
	return MCQQuestion(Title, CC, C2, C3, C4, POOL_QUESTIONS_COUNT);
}


// Question creation menu
bool CreateQuestion(){
	Question NewQuestion;
	
	string QuestionType = StringToLowerCase(GetUserInput("Enter the type of question you'd like to change: [TF/Complete/MCQ]\nAlternatively, you can enter 'cancel' to go back to the main menu.\nYour Choice"));
	
	if(QuestionType == "tf" || QuestionType == "mcq" || QuestionType == "complete"){
		string Title = FormatQuestionTitle(GetUserInput("Enter Question without the question mark")) + '?';

		if(!IsDuplicateQuestion(Title)){
			string CorrectChoice;
			
			do {
				CorrectChoice = GetUserInput("Enter correct choice");
			}
			while(!VerifyChoice(QuestionType, CorrectChoice));

			if(QuestionType == "mcq") QuestionPool.push_back(CreateMCQQuestion(Title, CorrectChoice));
			else if(QuestionType == "complete") QuestionPool.push_back(CompleteQuestion(Title, CorrectChoice, POOL_QUESTIONS_COUNT));
			else if(QuestionType == "tf") QuestionPool.push_back(TFQuestion(Title, CorrectChoice, POOL_QUESTIONS_COUNT));
			
			cout << "\nQuestion added successfully.\n\n";

			QuestionPoolSet.insert(Title);
			QuestionPoolIndices.push_back(POOL_QUESTIONS_COUNT);
			POOL_QUESTIONS_COUNT += 1;
			POOL_QUESTIONS_COUNT += 1;
		}
		else cout << "\nThis question already exists. Try adding a different question.\n";
	
	}
	else if(QuestionType == "cancel") return true;
	else {
		cout << "We didn't catch that, please try again.\n\n";
		return CreateQuestion();
	}

	return true;
}

void DisplayQuestionWithAnswers(Question &CurrentQuestion, int index) {
	bool IsList = index > -1;
	
	if(IsList) cout << "[" << index + 1 << "] (ID: " << CurrentQuestion.ID << ") " << CurrentQuestion.Title << "\n";

	if(CurrentQuestion.Type == "MCQ"){
			vector<string> Answers = { 
			CurrentQuestion.CorrectChoice, 
			CurrentQuestion.Choice2, 
			CurrentQuestion.Choice3, 
			CurrentQuestion.Choice4 
		};
		string Labels[] = { "[a] ", "[b] ", "[c] ", "[d] " };

		
		ShuffleAnswers();

		for (int i = 0; i < 4; i++) {
			bool IsCorrectAnswer = Answers[AnswerIndices[i]] == CurrentQuestion.CorrectChoice;
			
			string Result = IsCorrectAnswer ? 
				IndentString(("*" + Labels[i] + Answers[AnswerIndices[i]]), 1) :
				IndentString((Labels[i] + Answers[AnswerIndices[i]]), 1);
			
			cout << Result;
		}

		cout << "\n";
	}
	else{
		cout << "\tAnswer: " + CurrentQuestion.CorrectChoice << "\n";
	}
}

// Displays all questions in the question pool
void DisplayAllQuestions() {
	for (Question & CurrentQuestion : QuestionPool) {
		DisplayQuestionWithAnswers(CurrentQuestion, -1);
	}
}


bool DeleteQuestion(int QuestionIndex){
	std::cout << "\nDeleted the following question: " << QuestionPool[QuestionIndex].Title << "\n\n";

	std::vector<Question>::iterator it = QuestionPool.begin();
	std::vector<int>::iterator rit = QuestionPoolIndices.begin();

	std::advance(it, QuestionIndex);
	std::advance(rit, QuestionIndex);
	
	QuestionPoolSet.erase(QuestionPool[QuestionIndex].Title);
	QuestionPool.erase(it);
	QuestionPoolIndices.erase(rit);
	
	POOL_QUESTIONS_COUNT -= 1;
	
	for (int i = 0; i < POOL_QUESTIONS_COUNT; i++) {
		QuestionPoolIndices[i] = i;
	}
}


#endif