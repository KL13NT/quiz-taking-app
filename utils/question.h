#ifndef QUESTION_UTILS_H
#define QUESTION_UTILS_H

#include <ctime>
#include <chrono> //system_clock
#include <random>	//default_random_engine
#include <algorithm> //shuffle


// Shuffles question pool
void ShuffleQuestionPool() {
	vector<Question> NewPool;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(QuestionPoolIndices.begin(), QuestionPoolIndices.end(), std::default_random_engine(seed));

	for (int i = 0; i < POOL_QUESTIONS_COUNT; i++) NewPool.push_back(QuestionPool[QuestionPoolIndices[i]]); // Copies pool away randomly
	for (int i = 0; i < POOL_QUESTIONS_COUNT; i++) QuestionPool[i] = NewPool[i]; // Copies randomised questions over again
}


// Shuffles answers
void ShuffleAnswers(vector<string> (&Answers)) {
	vector<string> NewAnswers;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(AnswerIndices.begin(), AnswerIndices.end(), std::default_random_engine(seed));

	//REFACTORME: Perhaps use a single loop
	for (int i = 0; i < 4; i++) NewAnswers.push_back(Answers[AnswerIndices[i]]); // Copies pool away randomly
	for (int i = 0; i < 4; i++) Answers[i] = NewAnswers[i]; // Copies randomised questions over again
}


// Loads a "MCQ" question using an ifstream  
MCQQuestion LoadMCQQuestion(std::ifstream &File, std::string &Line){
	getline(File, Line);
	string Title = FormatQuestionTitle(Line);

	getline(File, Line);
	string CorrectChoice = Line;

	getline(File, Line);
	string Choice2 = Line;

	getline(File, Line);
	string Choice3 = Line;

	getline(File, Line);
	string Choice4 = Line;

	return MCQQuestion(Title, CorrectChoice, Choice2, Choice3, Choice4);
}


// Loads a "complete" question using an ifstream  
CompleteQuestion LoadCompleteQuestion(std::ifstream &File, std::string &Line){
	getline(File, Line);
	string Title = FormatQuestionTitle(Line);
	
	getline(File, Line);
	string CorrectChoice = Line;

	return CompleteQuestion(Title, CorrectChoice);
}


// Loads a "TF" question using an ifstream  
TFQuestion LoadTFQuestion(std::ifstream &File, std::string &Line){
	getline(File, Line);
	string Title = FormatQuestionTitle(Line);
	
	getline(File, Line);
	string CorrectChoice = Line;

	return TFQuestion(Title, CorrectChoice);
}


// Creates and returns a question
MCQQuestion CreateMCQQuestion(){
	string Title = FormatQuestionTitle(GetUserInput("Enter Question without the question mark")) + '?';
	string CC = GetUserInput("Enter the correct choice");
	string C2 = GetUserInput("Enter choice 2");
	string C3 = GetUserInput("Enter choice 3");
	string C4 = GetUserInput("Enter choice 4");
	
	return MCQQuestion(Title, CC, C2, C3, C4);
}


// Creates and returns a question
CompleteQuestion CreateCompleteQuestion(){
	string Title = FormatQuestionTitle(GetUserInput("Enter Question without the question mark")) + '?';
	string CorrectChoice = GetUserInput("Enter the correct choice");

	return CompleteQuestion(Title, CorrectChoice);
}


// Creates and returns a question
TFQuestion CreateTFQuestion(){
	string Title = FormatQuestionTitle(GetUserInput("Enter Question without the question mark")) + '?';
	string CorrectChoice = GetUserInput("Enter the correct choice");

	return TFQuestion(Title, CorrectChoice);
}


// Question creation menu
bool CreateQuestion(){
	Question NewQuestion;
	
	string UserChoice = StringToLowerCase(GetUserInput("Enter the type of question you'd like to change: [TF/Complete/MCQ]. Alternatively, you can enter 'cancel' to go back to the main menu."));
	
	if(UserChoice ==  "tf") NewQuestion = CreateTFQuestion(); 
	else if(UserChoice == "complete") NewQuestion = CreateCompleteQuestion();
	else if(UserChoice == "mcq") NewQuestion = CreateMCQQuestion();
	else if(UserChoice == "cancel") return true;
	else{
		cout << "We didn't catch that, please try again.\n\n";
		return CreateQuestion();
	}

	if(!IsDuplicateQuestion(NewQuestion, QuestionPoolSet)){
		QuestionPool.push_back(NewQuestion);
		QuestionPoolSet.insert(NewQuestion.Title);

		QuestionPoolIndices.push_back(POOL_QUESTIONS_COUNT);
		POOL_QUESTIONS_COUNT += 1;
	}
	else cout << "\nThis question already exists. Try adding a different question.\n";
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



// Displays all quesitons in the question pool
void DisplayAllQuestions() {
	for (auto & Question : QuestionPool) {
		DisplayQuestionWithAnswers(QuestionPool[i], i);
	}
}



// bool DeleteQuestion(int QuestionIndex){
// 	if (QuestionIndex <= POOL_QUESTIONS_COUNT) {
// 			std::cout << "\nDeleted the following question: " << QuestionPool[QuestionIndex - 1].QuestionTitle << "\n\n";

// 			std::vector<Question>::iterator it = QuestionPool.begin();
// 			std::vector<int>::iterator rit = QuestionPoolIndices.begin();
// 			std::advance(it, QuestionIndex-1);
// 			std::advance(rit, QuestionIndex-1);
// 			QuestionPool.erase(it);
// 			QuestionPoolIndices.erase(rit);
// 			POOL_QUESTIONS_COUNT -= 1;
// 			for (int i = 0; i < POOL_QUESTIONS_COUNT; i++) {
// 				QuestionPoolIndices[i] = i;
// 			}
// 			return true;
// 		}
// 		else {
// 			std::cout << "We didn't quite catch that, try again, perhaps?\n\n";
// 			return false;
// 		}
// }


#endif