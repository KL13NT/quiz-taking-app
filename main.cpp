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

using std::string;
using std::vector;
using std::unordered_set;
using std::cin;
using std::cout;


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