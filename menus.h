#include "./utils/index.h"

void AdminMenu();
void MainMennu();

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
