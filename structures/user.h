#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>


class User {
	public:
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

		int MCQuestionCount = 0;
		int TFQuestionCount = 0;
		int CompleteQuestionCount = 0;
		double GradePerMCQ = 0;
		double GradePerTFQuestion = 0;
		double GradePerCompleteQuestion = 0;

		User(){};
		~User(){};
		User(string FirstNameInput, string LastNameInput, string UsernameInput, string PasswordInput, bool IsAdminInput){
			FirstName = FirstNameInput;	
			LastName = LastNameInput;
			Username = UsernameInput;
			Password = PasswordInput;
			IsAdmin = IsAdminInput;
		}

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
			int MCQuestionCount = ToEqual.MCQuestionCount;
			int TFQuestionCount = ToEqual.TFQuestionCount;
			int CompleteQuestionCount = ToEqual.CompleteQuestionCount;
			double GradePerMCQ = ToEqual.GradePerMCQ;
			double GradePerTFQuestion = ToEqual.GradePerTFQuestion;
			double GradePerCompleteQuestion = ToEqual.GradePerCompleteQuestion;
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

		void DisplayUserStatistics(const User & CurrentUser){
			cout << "Your score statistics per quiz:" << std::endl;
			cout << "		-Number of quizzes taken: " << CurrentUser.QuizzesTaken << std::endl;
			cout << "		-Highest quiz score: " << CurrentUser.HighestScore << std::endl;
			cout << "		-Lowest quiz score: " << CurrentUser.LowestScore << std::endl;
			cout << "		-Average quiz score: " << CurrentUser.AvgScore << std::endl;
			cout << "Your score statistics per question type:" <<std::endl;
			cout << "		-Number of MC questions: " << CurrentUser.MCQuestionCount << std::endl;
			cout << "		-Number of complete questions: " << CurrentUser.CompleteQuestionCount << std::endl;
			cout << "		-Number of T/F questions: " << CurrentUser.TFQuestionCount << std::endl;
			cout << "		-Average grade for MC questions: " << CurrentUser.GradePerMCQ << std::endl;
			cout << "		-Average grade for Complete questions: " << CurrentUser.GradePerCompleteQuestion << std::endl;
			cout << "		-Average grade for T/F questions: " << CurrentUser.GradePerTFQuestion << std::endl;
		}
};


// Displays user scores
//void DisplayScores() {
//	for (int i = 0; i < UserProfile.QuizzesTakenCount; i++) cout << "Quiz [" << i + 1 << "] >> " << UserProfile.Scores[i] << "/" << QUIZ_QUESTIONS_COUNT << "\n";
//
//	cout << "\nEnter [b] to go back to the main menu\nEnter [e] to exit\n";
//	if (GetUserInput("Your choice") == "b") MainMenu();
//}


#endif