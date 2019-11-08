#include <sstream>
#include <string>

#include "./utils/index.h"
#include "./globals.h"


using std::string;
using std::cout;

// Displays main menu
void MainMenu() {
	cout << "Welcome " << UserProfile -> FirstName << ", please choose from the following options:\n";
	cout << IndentString("[1] Go to administration menu\n", 1);
	cout << IndentString("[2] Update your name\n", 1);
	cout << IndentString("[3] Start a new quiz\n", 1);
	cout << IndentString("[4] Display your scores statistics\n", 1);
	cout << IndentString("[5] Display all your scores\n", 1);
	cout << IndentString("[6] Exit\n", 1);
	//TODO: Fix

	switch (GetUserInput("Your choice")[0]) {
	case 1:
		return AdminMenu();
	case 2:
//		UpdateUserName();
		return MainMenu();
	case 3:
//		StartNewQuiz();
		return MainMenu();
	case 4:
//		return DisplayUserStatistics(CurrentUser);
	case 5:
//		return DisplayScores();
	case 6:
		return;
	default:
		cout << "We didn't quite understand that, try again, perhaps?\n";
		return MainMenu();
	}
}


// Displays administration menu
bool AdminMenu() {
	cout << "Welcome to the administration menu, please choose from the following options:\n";
	cout << IndentString("[1] View all questions\n", 1);
	cout << IndentString("[2] Add new question\n", 1);
	cout << IndentString("[3] Load questions from file\n", 1);
	cout << IndentString("[4] Display all users\n", 1);
	cout << IndentString("[5] Add a new user\n", 1);

	switch (GetUserInput("Your choice")[0]) {
	case 1:
		QuestionsMenu();
	case 2:
		CreateQuestion() == true? AdminMenu(): 0;
	case 3:
		GetFileNameFromUser();
	case 4:
		AllUsersMenu();
	default:
		cout << "We didn't quite understand that, try again, perhaps?\n";
	}

	return AdminMenu();
}


// Handles questions menu interactions
bool QuestionsMenuHandler() {
	cout << string(15, '-') << "\nEnter [d] without the brackets followed by the question ID to delete a question (Example: d 2)\nEnter [b] to go back to the main menu\n\n";
	
	string UserChoice = GetUserInput("Your Choice");
	char Type = UserChoice[0];

	if (Type == 'b') return true;
	else if (Type == 'd') {
		int QuestionIndex = std::stoi(UserChoice.substr(2)) - 1;
		if(POOL_QUESTIONS_COUNT >= QuestionIndex){
//		DeleteQuestion(QuestionIndex);
//		if(DeleteQuestion(QuestionIndex)==1){
//			return MainMenu();
//		}
//		else return QuestionsMenuHandler();
		}
	}
	else {
		cout << "We didn't quite catch that, try again, perhaps?\n\n";
		return QuestionsMenuHandler();
	}
}

// Displays questions-related menu
bool QuestionsMenu() {
	cout << "\n\nNumber of questions available: " << POOL_QUESTIONS_COUNT << "\n\n";
	
	if (CheckCurrentQuestionPoolSize(1, POOL_QUESTIONS_COUNT)) {
		cout << "Questions list:\n---------------\n";

		// DisplayAllQuestions();
		return QuestionsMenuHandler();

	}
	else {
		cout << "Please add more questions to the question pool and try again.\n\n";
		return true;
	}
}


void AllUsersMenu(){
  cout << "\n\nExisting users in the system:\n" << string('=', 10) << "\n";
	for (auto & User : Users) {
    User.DisplayInfo();
	}	
}