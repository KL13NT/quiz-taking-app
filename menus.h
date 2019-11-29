#include <sstream>
#include <string>


using std::string;
using std::cout;


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
	cout << string(15, '-') << "\nEnter [d] without the brackets followed by the question ID to delete a question (Example: d 2)\nEnter [b] to go back to the main menu\nKeep in mind that negative numbers are taken as positive.\n\n";

	string UserChoice = GetUserInput("Your Choice");
	char Type = UserChoice[0];

	if (Type == 'b' && UserChoice.length() == 1) return;
	else if (Type == 'd' && UserChoice.length() > 2) {
		
		if(StringToNumbers(UserChoice.substr(2)).length() == 0){
			cout << "Unexpected input. Try again.\n";
			return QuestionsMenuHandler();
		}

		int QuestionIndex = std::stoi(StringToNumbers(UserChoice.substr(2)));

		if(QuestionIDs.find(QuestionIndex) == QuestionIDs.end()){
			cout << "No question with this ID exists. Try again.\n\n";
			return QuestionsMenuHandler();
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

        if((int) MCQQuestions.size() != 0){
            cout << MakeHeader("MCQ Questions List (Total: " + std::to_string(MCQQuestions.size()) + " Questions)", 40);
            for(int i = 0; i < (int) MCQQuestions.size(); i++){
                DisplayQuestionWithAnswers(MCQQuestions[i], i);
            }
        }
        if((int) TFQuestions.size() != 0){
            cout << MakeHeader("True or False Questions List (Total: " + std::to_string(TFQuestions.size()) + " Questions)", 40);
            for(int i = 0; i < (int) TFQuestions.size(); i++){
                DisplayQuestionWithAnswers(TFQuestions[i], i);
            }
        }

        if((int) CompleteQuestions.size() != 0){
            cout << MakeHeader("Complete Questions List (Total: " + std::to_string(CompleteQuestions.size()) + " Questions)", 40);
            for(int i = 0; i < (int) CompleteQuestions.size(); i++){
                DisplayQuestionWithAnswers(CompleteQuestions[i], i);
            }
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

void DisplayDetailsOfLastQuizzes(){
	vector<Log> Logs = Users[LoggedinUserID].Logs;

	cout << MakeHeader("Quizzes log", 20);

	// To avoid taking input when there are no quizzes at all
	if((int) Logs.size() == 0) {
		cout << "No available quizzes found for this account. Try starting a new quiz.\n";
		return;
	}

	cout << "Number of available quizzes: " << (int) Logs.size() << "\n\n";
	string UserInput = StringToNumbers(GetUserInput("How many quizzes would you like to view?\nNumber"));

	while(UserInput.length() == 0) return DisplayDetailsOfLastQuizzes();

	int Input = std::stoi(UserInput);

	if(Input > 0) {
		if((int) Logs.size() >= Input){
			cout << MakeHeader("Viewing last " + UserInput + " quizzes", 40);

			for(int i = (int) Logs.size() - 1; i > (((int) Logs.size() - 1) - Input); i--){
				Log *CurrentLog = &(Logs[i]);
				cout << "Your total score in this quiz is: " << CurrentLog -> UserScore << "/" << HighestPossibleScore << "\n";

				DisplayLog(Logs[i]);
			}
		}
		else {
			cout << "Not enough quizzes for your query. The number of available quizzes is: " << (int) Logs.size() << "\n";
		}
	}
	else {
		cout << "Couldn't understand your input or the number you entered is too small. Try again?\n";
		return DisplayDetailsOfLastQuizzes();
	}
}

void PlayerMenu(){
	cout << MakeHeader(Greeting, 50);
	cout << IndentString("[1] Start a new quiz\n", 1);
	cout << IndentString("[2] Display details of your last quizzes\n", 1);
	cout << IndentString("[3] Display your score statistics\n", 1);
	cout << IndentString("[4] Display your scores\n", 1);
	cout << IndentString("[5] Update account details\n", 1);
	cout << IndentString("[6] Switch account\n", 1);
	cout << IndentString("[7] Exit\n", 1);

	switch (ctoi(GetUserInput("Your choice"))) {
	case 1:
		StartNewQuiz();
		break;
	case 2:
		DisplayDetailsOfLastQuizzes();
    break;
	case 3:
		Users[LoggedinUserID].DisplayUserStatistics();
    break;
	case 4:
		DisplayScores();
    break;
	case 5:
		UpdateAccountDetails();
		break;
	case 6:
		return SwitchAccount();
	case 7:
		return;
	default:
		cout << "We didn't quite understand that, try again, perhaps?\n";
	}

	return PlayerMenu();
}

void Login(){
	cout << MakeHeader("Login", 10);
	string Username = GetUserInput("Username");
	string Password = GetUserInput("Password");

	for (int i = 0; i < (int) Users.size(); i++){
		if(Username == Users[i].Username && Password == Users[i].Password){
			cout << "User found.\n";

			IsLoggedin = true;
			LoggedinUserID = i;
			UpdateGreeting();

			return Users[i].IsAdmin? AdminMenu(): PlayerMenu();
		}
	}
  cout << "User not found. Try again.\n";
  return Login();
}

void DisplayScores(){
	const int QuizzesTaken = Users[LoggedinUserID].QuizzesTaken;
	const vector<Log> Logs = Users[LoggedinUserID].Logs;
	const string IsPlural = QuizzesTaken == 1? " quiz.\n" : " quizzes.\n";

	cout << MakeHeader("Scores", 20);
	cout << "The total number of quizzes you took is: " << QuizzesTaken << IsPlural;

	if((int) Logs.size() == 0) {
		cout << "You haven't taken any quizzes yet. Go try out a quiz and try again.\n";
		return;
	}

	for(int i = 0; i < (int) (Logs).size(); i++){
		cout << "Quiz " << i + 1 << "\n";
		cout << IndentString("Correct answers: ", 1) << Logs[i].CorrectAnswers << "\n";
		cout << IndentString("Your score: ", 1) << Logs[i].UserScore << "/" << HighestPossibleScore << "\n";
	}
}

void MainMenu(){
	if(Users.size() == 0) {
		CreateNewUser();
		return MainMenu();
	}
	else if(Users.size() > 0 && IsLoggedin) return Users[LoggedinUserID].IsAdmin? AdminMenu(): PlayerMenu();
	else if(Users.size() > 0 && !IsLoggedin) return Login();
}

void SwitchAccount(){
	string Answer = GetUserInput("Are you sure you wish to switch accounts? [Y]es or [N]o");

	while(!(StringIsEqualIgnoreCase(Answer, "Y") || StringIsEqualIgnoreCase(Answer, "N") || StringIsEqualIgnoreCase(Answer, "Yes") || StringIsEqualIgnoreCase(Answer, "No"))) {
		Answer = StringToLowerCase(GetUserInput("We didn't catch that, please try again.\nDo you wish to log out? [Y]es or [N]o"));
	}

	if(StringIsEqualIgnoreCase(Answer, "Y") || StringIsEqualIgnoreCase(Answer, "Yes") ){
		cout << "Logged out successfully...\n";
		IsLoggedin = false;
        LoggedinUserID = -1;
		return MainMenu();
	}

	else return MainMenu();

}
