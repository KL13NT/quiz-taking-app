/*
Team Name: 2Scoops
Members:
	Nabil Tharwat: 20180305
	Amr Samy: 20180187
	Muhammad Hisham Shaarawy: 20180243
	Omar Mustafa: 20180182
Original Repo: https://github.com/KL13NT/quiz-taking-app
*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set> 
#include <numeric> //accumulate

// custom definitions
#include "./structures/index.h"
#include "./globals.h"
#include "./utils/index.h"
#include "./menus.h"


using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::unordered_set;

std::string GetUserInput(std::string Additional = "  "){
  std::string Input;
  
  getline(std::cin, Input);
		if (Input[1] == '\0'){
			if (Input >="0" || Input <= "9"){
				char *Output = new char[];
				Output[0] = Input[0];
				return Output;
  		}

  else if(Input >= "a" || Input <= "z"){
				char *Output = new char[];
				Output[0] = Input [0];
				return Output;
  		}
		}
		else return Input;


}

bool DeleteQuestion(int QuestionIndex){
	if (QuestionIndex <= POOL_QUESTIONS_COUNT) {
			std::cout << "\nDeleted the following question: " << QuestionPool[QuestionIndex - 1].QuestionTitle << "\n\n";

			std::vector<Question>::iterator it = QuestionPool.begin();
			std::vector<int>::iterator rit = RandomlyGeneratedQuestions.begin();
			std::advance(it, QuestionIndex-1);
			std::advance(rit, QuestionIndex-1);
			QuestionPool.erase(it);
			RandomlyGeneratedQuestions.erase(rit);
			POOL_QUESTIONS_COUNT -= 1;
			for (int i = 0; i < POOL_QUESTIONS_COUNT; i++) {
				RandomlyGeneratedQuestions[i] = i;
			}
			return true;
		}
		else {
			std::cout << "We didn't quite catch that, try again, perhaps?\n\n";
			return false;
		}
}
// Handles questions menu interactions
void QuestionsMenuHandler() {
	std::cout << std::string(15, '-') << "\nEnter [d] without the brackets followed by the question ID to delete a question (Example: d 2)\nEnter [b] to go back to the main menu\n\n";
	std::string UserChoice = GetUserInput("		");

	if (UserChoice == "b") return MainMenu();
	else if (UserChoice[0] == 'd' && UserChoice[1] == ' ') {
		std::string QuestionIndexAsString;
		QuestionIndexAsString = UserChoice.substr(2);
		std::stringstream ToInteger(QuestionIndexAsString);
		int QuestionIndex;
		ToInteger >> QuestionIndex;
		DeleteQuestion(QuestionIndex);
		if(DeleteQuestion(QuestionIndex)==1){
			return MainMenu();
		}
		else return QuestionsMenuHandler();
	}
	else {
		std::cout << "We didn't quite catch that, try again, perhaps?\n\n";
		return QuestionsMenuHandler();
	}
}


// Displays questions-related menu
void QuestionsMenu() {
	std::cout << "\n\nNumber of questions available: " << POOL_QUESTIONS_COUNT << "\n\n";
	if (CheckCurrentQuestionPoolSize(1)) {
		std::cout << "Questions list:\n---------------\n";

		DisplayAllQuestions();
		QuestionsMenuHandler();

	}
	else {
		std::cout << "Please add more questions to the question pool and try again.\n\n";
		return MainMenu();
	}
}
int main() {
	ReadFromFile("exam2_questions.txt");

	// Generates random integers
	for (int i = 0; i < 4; i++) AnswerIndices.push_back(i);

	MainMenu();


	return 0;
}

void AdminMenu() {
    std::cout << "Welcome, " << UserProfile.Name << ", please choose from the following options:\n";
	std::cout << "[1] Switch accounts\n";
	std::cout << "[2] Update your name\n";
	std::cout << "[3] View all users\n";
	std::cout << "[4] Add new user\n";
	std::cout << "[5] View all questions\n";
	std::cout << "[6] Add new question\n";
    std::cout << "[7] Load questions from file\n";
    std::cout << "[8] Exit\n";
}

void PlayerMenu() {
    std::cout << "Welcome, " << UserProfile.Name << ", please choose from the following options:\n";
	std::cout << "[1] Switch accounts\n";
	std::cout << "[2] Update your name\n";
	std::cout << "[3] Start a new quiz\n";
	std::cout << "[4] Display your scores statistics\n";
	std::cout << "[5] Display all your scores\n";
	std::cout << "[6] Display details of your last 2 quizzes\n";
    std::cout << "[7] Exit\n";
}

class User{
    public:
        User(){
            std::string Username = "";
            std::string Userpassword = "";
        };
};

class Admin : public User{
    public:
        std::string username = "admin";
        std::string password = "admin";
};

bool Checklogin(){
	Admin ad;
    std::string Name, Password;
    std::cout << "Enter your username:";
    getline(std::cin, Name);
    std::cout << "Enter your password:";
    getline(std::cin, Password);
    if(Name == ad.username && Password == ad.password){
        return true;
    }
    else{
        return false;
        }
}

int main(){
    bool status = Checklogin();
    if(!status){
        std::cout << "Failed!!\n";
    }
    else {
        std::cout << "Logged in Successfully!!\n";
		AdminMenu();
    }
}