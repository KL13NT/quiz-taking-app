#include <sstream>
#include <string>


using std::string;
using std::cout;

// Displays main menu
// TODO: remove MainMenu
//void MainMenu() {
//	cout << "Welcome " << UserProfile -> FirstName << ", please choose from the following options:\n";
//	cout << IndentString("[1] Go to administration menu\n", 1);
//	cout << IndentString("[2] Update your name\n", 1);
//	cout << IndentString("[3] Start a new quiz\n", 1);
//	cout << IndentString("[4] Display your scores statistics\n", 1);
//	cout << IndentString("[5] Display all your scores\n", 1);
//	cout << IndentString("[6] Exit\n", 1);
//	//TODO: Fix
//
//	switch (GetUserInput("Your choice")[0]) {
//	case 1:
//		return AdminMenu();
//	case 2:
////		UpdateUserName();
//		return MainMenu();
//	case 3:
////		StartNewQuiz();
//		return MainMenu();
//	case 4:
////		return DisplayUserStatistics(CurrentUser);
//	case 5:
////		return DisplayScores();
//	case 6:
//		return;
//	default:
//		cout << "We didn't quite understand that, try again, perhaps?\n";
//		return MainMenu();
//	}
//}


// Displays administration menu
void AdminMenu() {
	cout << MakeHeader(Greeting, 50);
	cout << IndentString("[1] View all questions\n", 1);
	cout << IndentString("[2] Add new question\n", 1);
	cout << IndentString("[3] Load questions from file\n", 1);
	cout << IndentString("[4] Display all users\n", 1);
	cout << IndentString("[5] Add a new user\n", 1);
	cout << IndentString("[6] Update account details\n", 1);
	cout << IndentString("[7] Switch account\n", 1);
	cout << IndentString("[8] Exit\n", 1);

	switch (ctoi(GetUserInput("Your choice"))) {
	case 1:
		QuestionsMenu();
		break;
	case 2:
		CreateQuestion();
    break;
	case 3:
		GetFileNameFromUser();
    break;
	case 4:
		DisplayAllUsers();
    break;
	case 5:
		CreateNewUser();
    break;
	case 6:
		UpdateAccountDetails();
		break;
	case 7:
		return SwitchAccount();
	case 8:
		return;
	default:
		cout << "We didn't quite understand that, try again, perhaps?\n";
	}

	return AdminMenu();
}


// Handles questions menu interactions
void QuestionsMenuHandler() {
	cout << string(15, '-') << "\nEnter [d] without the brackets followed by the question ID to delete a question (Example: d 2)\nEnter [b] to go back to the main menu\n\n";

	string UserChoice = GetUserInput("Your Choice");
	char Type = UserChoice[0];

	if (Type == 'b') return;
	else if (Type == 'd') {
		int QuestionIndex = std::stoi(UserChoice.substr(2));

		while(!(POOL_QUESTIONS_COUNT >= QuestionIndex)){
			QuestionIndex = std::stoi(GetUserInput("No question with this ID exists. Try again.\nYour choice").substr(2));
		}


		DeleteQuestion(QuestionIndex);
	}
	else {
		cout << "We didn't quite catch that, try again, perhaps?\n\n";
		return QuestionsMenuHandler();
	}
}

// Displays questions-related menu
void QuestionsMenu() {
	cout << "\n\nNumber of questions available: " << POOL_QUESTIONS_COUNT << "\n\n";

	if (CheckCurrentQuestionPoolSize(1)) {
		vector<Question> MCQQuestions;
		vector<Question> TFQuestions;
		vector<Question> CompleteQuestions;

		for(Question & CurrentQuestion : QuestionPool){
			if(CurrentQuestion.Type == "MCQ") MCQQuestions.push_back(CurrentQuestion);
			else if(CurrentQuestion.Type == "TF") TFQuestions.push_back(CurrentQuestion);
			else if(CurrentQuestion.Type == "COMPLETE") CompleteQuestions.push_back(CurrentQuestion);
		}

		cout << MakeHeader("MCQ Questions List (Total: " + std::to_string(MCQQuestions.size()) + " Questions)", 40);
		for(int i = 0; i < (int) MCQQuestions.size(); i++){
			DisplayQuestionWithAnswers(MCQQuestions[i], i);
		}

		cout << MakeHeader("True or False Questions List (Total: " + std::to_string(TFQuestions.size()) + " Questions)", 40);
		for(int i = 0; i < (int) TFQuestions.size(); i++){
			DisplayQuestionWithAnswers(TFQuestions[i], i);
		}

		cout << MakeHeader("Complete Questions List (Total: " + std::to_string(CompleteQuestions.size()) + " Questions)", 40);
		for(int i = 0; i < (int) CompleteQuestions.size(); i++){
			DisplayQuestionWithAnswers(CompleteQuestions[i], i);
		}

		return QuestionsMenuHandler();
	}

	cout << "Please add more questions to the question pool and try again.\n\n";
}


void DisplayAllUsers(){
  cout << MakeHeader("Existing users in the system:", 30);

	for (auto & User : Users) {
    User.DisplayInfo();
	}
}

void PlayerMenu(){
	cout << MakeHeader(Greeting, 50);
	cout << IndentString("[1] Start a new quiz\n", 1);
	cout << IndentString("[2] Display details of your last quizzes\n", 1);
	cout << IndentString("[3] Load questions from file\n", 1);
	cout << IndentString("[4] Display your score statistics\n", 1);
	cout << IndentString("[5] Display your scores\n", 1);
	cout << IndentString("[6] Update account details\n", 1);
	cout << IndentString("[7] Switch account\n", 1);
	cout << IndentString("[8] Exit\n", 1);

	switch (ctoi(GetUserInput("Your choice"))) {
	case 1:
		StartNewQuiz();
		break;
	case 2:
		CreateQuestion();
    break;
	case 3:
		GetFileNameFromUser();
    break;
	case 4:
		UserProfile -> DisplayUserStatistics();
    break;
	case 5:
		// DisplayScores();
    break;
	case 6:
		UpdateAccountDetails();
		break;
	case 7:
		return SwitchAccount();
	case 8:
		return;
	default:
		cout << "We didn't quite understand that, try again, perhaps?\n";
	}

	return AdminMenu();
}

void Login(){
	cout << MakeHeader("Login", 10);
	string Username = GetUserInput("Username");
	string Password = GetUserInput("Password");

	for (User & CurrentUser : Users){
		if(Username == CurrentUser.Username && Password == CurrentUser.Password){
			cout << "User found.\n";

			UserProfile = &CurrentUser;
			IsLoggedin = true;
			Greeting = "Hello, " + UserProfile -> FirstName + " " + UserProfile -> LastName + ". You are an admin.";
			
			return CurrentUser.IsAdmin? AdminMenu(): StartNewQuiz();
		}
	}
  cout << "User not found. Try again.\n";
  return Login();
}

void MainMenu(){
	if(Users.size() == 0) {
		CreateNewUser();
		return MainMenu();
	}
	else if(Users.size() > 0 && IsLoggedin) return UserProfile -> IsAdmin? AdminMenu(): PlayerMenu();
	else if(Users.size() > 0 && !IsLoggedin) return Login();
}

void SwitchAccount(){
	string Answer = GetUserInput("Are you sure you wish to switch accounts? [Y]es or [N]o");

	while(!(StringIsEqualIgnoreCase(Answer, "Y") || StringIsEqualIgnoreCase(Answer, "N") || StringIsEqualIgnoreCase(Answer, "Yes") || StringIsEqualIgnoreCase(Answer, "No"))) {
		Answer = StringToLowerCase(GetUserInput("We didn't catch that, please try again.\nDo you wish to log out? [Y]es or [N]o"));
	}

	if(StringIsEqualIgnoreCase(Answer, "Y") || StringIsEqualIgnoreCase(Answer, "Yes") ){
		cout << "Logged out successfully...\n";
		UserProfile = NULL; //Leaving no trace of the logged out user.
		IsLoggedin = false;

		return MainMenu();
	}

	else return MainMenu();

}
