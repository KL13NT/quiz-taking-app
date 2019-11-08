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

using std::string;
using std::vector;
using std::unordered_set;
using std::cin;
using std::cout;

// Definitions reference
#include "./indexer.h"

// custom definitions
#include "./structures/index.h"
#include "./globals.h"
#include "./utils/index.h"
#include "./menus.h"



int main() {
	ReadFromFile("exam2_questions.txt");

	// Generates random integers
	for (int i = 0; i < 4; i++) AnswerIndices.push_back(i);

	MainMenu();


	return 0;
}

void Login(const User &user){
	std::string Name, Password;
	bool found = user.IsAdmin;
	std::cout << "Enter your username: ";
	getline(std::cin, Name);
	std::cout << "Enter your password: ";
	getline(std::cin, Password);
	if(Name == user.Username && Password == user.Userpassword){
			found = true;
	}
	else{
			found = false;
	}
	if(!found){
			std::cout << "Incorrect username or password, Please Try Again.\n";
			Login(user);
	}
	else {
			std::cout << "Logged in Successfully!!\n";
	return AdminMenu();
	}
}

void RegisterUser(const User &user){
	int Choice;
	char Confirmation;
	std::string username, password;
	std::cout << "Please enter your username: ";
	getline(std::cin, username);
	std::cout << "Please enter your password: ";
	getline(std::cin, password);
	std::cout << "Username -  "<< username << "\nPassword -  " << password;
	std::cout << "\nAre you sure that username and password are correct? [Y/N]\n";
	std::cin >> Confirmation;
	std::cin.ignore(1000, '\n');
	if(Confirmation == 'y' || Confirmation == 'Y'){
		//user.Username = username;
		//user.Userpassword = password;
		std::cout << "Would you like this account be Admin or normal user? \n[1]Admin \n[2]Normal User\n";
		std::cin >> Choice;
		std::cin.ignore(1000, '\n');
		switch(Choice){
			case 1:
				//user.IsAdmin = true;
				return AdminMenu();
				break;
			case 2:
				return AdminMenu();
				break;
			default:
				std::cout << "Invalid Input!!";
				RegisterUser(user);
		}
	}
	else if(Confirmation == 'n' || Confirmation == 'N'){
		RegisterUser(user);
	}
}