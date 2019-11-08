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

        void UpdateUserData(std::string NewFirstname, std::string NewLastname, std::string NewUsername, std::string NewPassword){
            Firstname = NewFirstname;
            Lastname = NewLastname;
            Username = NewUsername;
            Userpassword = NewPassword;
        }

		void operator = (const User &ToEqual){
			IsAdmin = ToEqual.IsAdmin;
			FirstName = ToEqual.FirstName;
			LastName = ToEqual.LastName;
			Username = ToEqual.Username;
			Password = ToEqual.Password;
			Logs = ToEqual.Logs;
			HighestScore = ToEqual.HighestScore;
			LowestScore = ToEqual.LowestScore;
			QuizzesTaken = ToEqual.QuizzesTaken;
			AvgScore = ToEqual.AvgScore;
			MCQuestionCount = ToEqual.MCQuestionCount;
			TFQuestionCount = ToEqual.TFQuestionCount;
			CompleteQuestionCount = ToEqual.CompleteQuestionCount;
			GradePerMCQ = ToEqual.GradePerMCQ;
			GradePerTFQuestion = ToEqual.GradePerTFQuestion;
			GradePerCompleteQuestion = ToEqual.GradePerCompleteQuestion;
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
		void UpdateYourName(){
    		FirstName = GetUserInput("Please Enter Your New First Name: ");
    		LastName = GetUserInput("Please Enter Your New Last Name: ");
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