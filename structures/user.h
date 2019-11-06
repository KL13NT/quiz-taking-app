#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>


using std::cout;
using std::string;

class User {
	private:
		bool IsAdmin = false;
		string FirstName = "";
		string LastName = "";
		string Username = "";
		string Password = "";
		vector<Log> Logs = {};
		int HighestScore = 0;
		int LowestScore = 0;
		int QuizzesTaken = 0;
		double AvgScore = 0;
	
	public:
		User();
		~User();
		User(string FirstNameInput, string LastNameInput, string UsernameInput, string PasswordInput, bool IsAdminInput){
			FirstName = FirstNameInput;	
			LastName = LastNameInput;
			Username = UsernameInput;
			Password = PasswordInput;
			IsAdmin = IsAdminInput;
		}
		
		// void DisplayUserStatistics(){
		// 	cout << "Your score statistics: \n\t- Number of quizzes taken: " << QuizzesTaken
		// 	<< "\n\t- Highest Score: " 
		// 	<< HighestScore << "/" << QUIZ_QUESTIONS_COUNT 
		// 	<< "\n\t- Lowest Score: " 
		// 	<< LowestScore << "/" << QUIZ_QUESTIONS_COUNT 
		// 	<< "\n\t- Average Score: " 
		// 	<< AvgScore << "/" << QUIZ_QUESTIONS_COUNT 
		// 	<< "\nEnter [b] to go back to the main menu\nEnter [e] to exit\n";
		// }

		void UpdateUserData(string NewName, string NewUsername, string NewPassword){
			
		}

		void operator = (const User &ToEqual){
			bool IsAdmin = ToEqual.IsAdmin;
			string FirstName = ToEqual.FirstName;
			string LastName = ToEqual.LastName;
			string Username = ToEqual.Username;
			string Password = ToEqual.Password;
			vector<Log> Logs = ToEqual.Logs;
			int HighestScore = ToEqual.HighestScore;
			int LowestScore = ToEqual.LowestScore;
			int QuizzesTaken = ToEqual.QuizzesTaken;
			double AvgScore = ToEqual.AvgScore;
		}

		bool operator == (const User &ToEqual){
			return ToEqual.Username == Username? true: false;
		}
		
		void DisplayInfo(){
			string IsAdminString = IsAdmin? "Admin\n": "Player\n";
			cout << "Full Name: " << FirstName << " " << LastName << "\n";
			cout << "Username: " << Username << "\n";
			cout << "Role: " << IsAdminString << "\n\n";
		}

		friend void Login(const User &);
		friend void DisplayUserStatistics(const User &);
};

void DisplayUserStatistics(const User & CurrentUser){
	cout << "Number of quizzes taken: " << CurrentUser.QuizzesTaken <<std::endl;
	cout << "Highest quiz score: " << CurrentUser.HighestScore << std::endl;
	cout << "Lowest quiz score: " << CurrentUser.LowestScore << std::endl;
	cout << "Average quiz score: " << CurrentUser.AvgScore << std::endl;
}

// Displays user scores
void DisplayScores() {
	for (int i = 0; i < UserProfile.QuizzesTakenCount; i++) cout << "Quiz [" << i + 1 << "] >> " << UserProfile.Scores[i] << "/" << QUIZ_QUESTIONS_COUNT << "\n";

	cout << "\nEnter [b] to go back to the main menu\nEnter [e] to exit\n";
	if (GetUserInput("Your choice") == "b") MainMenu();
}


#endif