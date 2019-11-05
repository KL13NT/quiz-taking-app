/*
Team Name: 2Scoops
Members:
	Nabil Tharwat: 20180305
	Amr Samy: 20180187
	Muhammad Hisham Shaarawy: 20180243
	Omar Mustafa: 20180182
Original Repo: https://github.com/KL13NT/quiz-taking-app
*/

// standard headers
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set> 
#include <numeric> //accumulate
#include <algorithm> //shuffle
#include <random>	//default_random_engine
#include <chrono> //system_clock


// custom definitions
#include "./structures/index.h"
#include "./globals.h"
#include "./utils/index.h"

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::unordered_set;


string IndentString(string sentence, int indent); //!TESTED
bool CheckAnswerValidity(Question CurrentQuestion, string Answer); //!TESTED
bool RandomiseAndPrintAnswers(Question CurrentQuestion); //!AWAITING
void MainMenu(); //!TESTED
void AdminMenu(); //!TESTED
void StartNewQuiz(); //!AWAITING
void UpdateProfileAfterQuiz(int CorrectAnswers); //!TESTED
void UpdateUserName(); //!TESTED
void AddQuestion(); //!TESTED
void DisplayAllQuestions(); //!TESTED
void DisplayQuestionWithAnswers(Question CurrentQuestion, int QuestionIndex); //!TESTED
void DisplayQuestion(Question CurrentQuestion, int QuestionIndex); //!TESTED
void ShuffleAnswers(vector<string>(&Answers));
void GenerateQuizQuestions(Question(&GeneratedQuestions)[QUIZ_QUESTIONS_COUNT]); //!TESTED
void DisplayStatistics(); //!TESTED
void DisplayScores(); //!TESTED
void GenerateAfterQuizReport(int CorrectAnswers); //!TESTED
void QuestionsMenu(); //!TESTED
void QuestionsMenuHandler(); //!TESTED



// Controls the addition of new questions
// void AddQuestion() {
// 	//TODO: modify this to reflect changes
// 	Question NewQuestion;

// 	NewQuestion.Title = GetUserString("Question without question mark");
// 	NewQuestion.CorrectChoice = GetUserString("Correct Choice");
// 	NewQuestion.Choice2 = GetUserString("Second Choice");
// 	NewQuestion.Choice3 = GetUserString("Third Choice");
// 	NewQuestion.Choice4 = GetUserString("Last Choice");
// 	cout << "\nAdded new question: " << NewQuestion.Title << "\n\n";
// 	QuestionPool.push_back(NewQuestion);

// 	POOL_QUESTIONS_COUNT += 1;
// 	QuestionPoolIndices.push_back(POOL_QUESTIONS_COUNT - 1);
// }


// Updates username
void UpdateUserName() {
	UserProfile.Name = GetUserString("New name");
}


// Checks if supplied answer is the correct choice
bool CheckAnswerValidity(const Question CurrentQuestion, const string Answer) {
	if (Answer == CurrentQuestion.CorrectChoice) {
		return true;
	}
	else return false;
}


// Randomises passed question answers and returns true if the user chose correctly
// bool RandomiseAndPrintAnswers(Question CurrentQuestion) {
// 	vector<string> Answers{ CurrentQuestion.CorrectChoice, CurrentQuestion.Choice2, CurrentQuestion.Choice3, CurrentQuestion.Choice4 };

// 	ShuffleAnswers(Answers);

// 	cout << IndentString("[a] ", 1) << Answers[0] << IndentString("[b] ", 1) << Answers[1] << IndentString("[c] ", 1) << Answers[2] << IndentString("[d] ", 1) << Answers[3] << "\n\n";

// 	bool IsAnswerCorrect;
// 	bool IsValidChoice = false;
// 	do {
// 		switch (GetUserChar("Answer letter")) {
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


// Generates the after-quiz report
void GenerateAfterQuizReport(int CorrectAnswers) {
	cout << "You answered " << CorrectAnswers << "/" << QUIZ_QUESTIONS_COUNT << " questions correctly.\n";
}


// Updates user profile
void UpdateProfileAfterQuiz(int CorrectAnswers) {
	Profile NewProfile = UserProfile;
	NewProfile.HighestScore =
		CorrectAnswers > UserProfile.HighestScore
		? CorrectAnswers
		: UserProfile.HighestScore;

	NewProfile.LowestScore =
		UserProfile.LowestScore == 0 && UserProfile.QuizzesTakenCount == 0
		? CorrectAnswers
		: CorrectAnswers < UserProfile.LowestScore && UserProfile.LowestScore > 0
		? CorrectAnswers
		: UserProfile.LowestScore;

	NewProfile.QuizzesTakenCount += 1;
	NewProfile.Scores.push_back(CorrectAnswers);
	NewProfile.AvgScore = std::accumulate(NewProfile.Scores.begin(), NewProfile.Scores.end(), 0.0) / (float)NewProfile.Scores.size();

	UserProfile = NewProfile;
}


// Generates quiz questions by randomly filling an already created GeneratedQuestions array
void GenerateQuizQuestions(Question(&GeneratedQuestions)[QUIZ_QUESTIONS_COUNT]) {
	ShuffleQuestionPool();
	for (int i = 0; i < QUIZ_QUESTIONS_COUNT; i++) {
		GeneratedQuestions[i] = QuestionPool[QuestionPoolIndices[i]];
	}
}


// Displays all quesitons in the question pool
// void DisplayAllQuestions() {
// 	for (int i = 0; i < POOL_QUESTIONS_COUNT; i++) {
// 		DisplayQuestionWithAnswers(QuestionPool[i], i);
// 	}
// }


// Handles questions menu interactions
void QuestionsMenuHandler() {
	cout << string(15, '-') << "\nEnter [d] without the brackets followed by the question ID to delete a question (Example: d 2)\nEnter [b] to go back to the main menu\n\n";
	string UserChoice = GetUserString("Your choice");

	if (UserChoice == "b") return MainMenu();
	else if (UserChoice[0] == 'd' && UserChoice[1] == ' ' && UserChoice[2]) {
		char IndexOfQuestionAsChar = UserChoice[2];
		int IndexOfQuestion = IndexOfQuestionAsChar - '0';
		if (IndexOfQuestion <= POOL_QUESTIONS_COUNT) {
			cout << "\nDeleted the following question: " << QuestionPool[IndexOfQuestion - 1].Title << "\n\n";

			vector<Question>::iterator it = QuestionPool.begin();
			vector<int>::iterator rit = QuestionPoolIndices.begin();
			std::advance(it, IndexOfQuestion-1);
			std::advance(rit, IndexOfQuestion-1);
			QuestionPool.erase(it);
			QuestionPoolIndices.erase(rit);
			POOL_QUESTIONS_COUNT -= 1;
			for (int i = 0; i < POOL_QUESTIONS_COUNT; i++) {
				QuestionPoolIndices[i] = i;
			}
		}
		else {
			cout << "We didn't quite catch that, try again, perhaps?\n\n";
			return QuestionsMenuHandler();
		}
		return MainMenu();
	}
	else {
		cout << "We didn't quite catch that, try again, perhaps?\n\n";
		return QuestionsMenuHandler();
	}
}


// Displays questions-related menu
void QuestionsMenu() {
	cout << "\n\nNumber of questions available: " << POOL_QUESTIONS_COUNT << "\n\n";
	if (CheckCurrentQuestionPoolSize(1, POOL_QUESTIONS_COUNT)) {
		cout << "Questions list:\n---------------\n";

//		DisplayAllQuestions();
		QuestionsMenuHandler();

	}
	else {
		cout << "Please add more questions to the question pool and try again.\n\n";
		return MainMenu();
	}
}


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


// Starts a new quiz
// void StartNewQuiz() {
// 	Question GeneratedQuestions[QUIZ_QUESTIONS_COUNT];

// 	if (CheckCurrentQuestionPoolSize(QUIZ_QUESTIONS_COUNT)) {
// 		int CorrectAnswers = 0;
// 		GenerateQuizQuestions(GeneratedQuestions);

// 		for (int i = 0; i < QUIZ_QUESTIONS_COUNT; i++) {
// 			DisplayQuestion(GeneratedQuestions[i], i);
// 			int IsCorrect = RandomiseAndPrintAnswers(GeneratedQuestions[i]);
// 			if ((bool) IsCorrect) CorrectAnswers += 1;
// 		}

// 		GenerateAfterQuizReport(CorrectAnswers);
// 		UpdateProfileAfterQuiz(CorrectAnswers);
// 	}
// 	else {
// 		cout << "Please add more questions to the question pool and try again.\n\n";
// 	}

// }


// Returns sentence indented by tabs
string IndentString(const string sentence, const int indent) {
	string indented(indent, '\t');
	indented += sentence;
	return indented;
}





// Displays main menu
void MainMenu() {
	cout << "Welcome " << UserProfile.Name << ", please choose from the following options:\n";
	cout << IndentString("[1] Go to administration menu\n", 1);
	cout << IndentString("[2] Update your name\n", 1);
	cout << IndentString("[3] Start a new quiz\n", 1);
	cout << IndentString("[4] Display your scores statistics\n", 1);
	cout << IndentString("[5] Display all your scores\n", 1);
	cout << IndentString("[6] Exit\n", 1);
	//TODO: Take user input and push it through a switch

	switch (GetUserInt("Your choice")) {
	case 1:
		return AdminMenu();
	case 2:
		UpdateUserName();
		return MainMenu();
	case 3:
//		StartNewQuiz();
		return MainMenu();
	case 4:
		return DisplayStatistics();
	case 5:
		return DisplayScores();
	case 6:
		return;
	default:
		cout << "We didn't quite understand that, try again, perhaps?\n";
		return MainMenu();
	}
}


// Displays administration menu
void AdminMenu() {
	cout << "Welcome to the administration menu, please choose from the following options:\n";
	cout << IndentString("[1] View all questions\n", 1);
	cout << IndentString("[2] Add new question\n", 1);
	cout << IndentString("[3] Load questions from file\n", 1);
	cout << IndentString("[4] Go back to main menu\n", 1);

	switch (GetUserInt("Your choice")) {
	case 1:
		return QuestionsMenu();
	case 2:
//		AddQuestion();
		return AdminMenu();
	case 3:
		GetFileNameFromUser();
		return AdminMenu();
	case 4:
		return MainMenu();
	default:
		cout << "We didn't quite understand that, try again, perhaps?\n";
		return AdminMenu();
	}
	//TODO: Take user input and push it through a switch
}


// Shuffles answers
void ShuffleAnswers(vector<string>(&Answers)) {
	vector<string> NewAnswers;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(AnswerIndices.begin(), AnswerIndices.end(), std::default_random_engine(seed));

	for (int i = 0; i < 4; i++) NewAnswers.push_back(Answers[AnswerIndices[i]]); // Copies pool away randomly
	for (int i = 0; i < 4; i++) Answers[i] = NewAnswers[i]; // Copies randomised questions over again
}


// Displays user score statistics
void DisplayStatistics() {
	cout << "Your score statistics: \n\t- Number of quizzes taken: " << UserProfile.QuizzesTakenCount << "\n\t- Highest Score: " << UserProfile.HighestScore << "/" << QUIZ_QUESTIONS_COUNT << "\n\t- Lowest Score: " << UserProfile.LowestScore << "/" << QUIZ_QUESTIONS_COUNT << "\n\t- Average Score: " << UserProfile.AvgScore << "/" << QUIZ_QUESTIONS_COUNT << "\nEnter [b] to go back to the main menu\nEnter [e] to exit\n";

	if (GetUserChar("Your choice") == 'b') MainMenu();
}


// Displays user scores
void DisplayScores() {
	for (int i = 0; i < UserProfile.QuizzesTakenCount; i++) cout << "Quiz [" << i + 1 << "] >> " << UserProfile.Scores[i] << "/" << QUIZ_QUESTIONS_COUNT << "\n";

	cout << "\nEnter [b] to go back to the main menu\nEnter [e] to exit\n";
	if (GetUserChar("Your choice") == 'b') MainMenu();
}


int main() {
	ReadFromFile("exam_questions.txt");

	// Generates random integers
	for (int i = 0; i < 4; i++) AnswerIndices.push_back(i);

	MainMenu();


	return 0;
}
