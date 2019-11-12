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

		// logs
		vector<Log> Logs = {};
		int QuizzesTaken = 0;
		double HighestQuizScore = 0;
		double LowestQuizScore = 0;
		double AvgQuizScore = 0;

		// quiz fields
		int MCQCount = 0;
		int TFCount = 0;
		int CompleteCount = 0;
		double AvgMCQScore = 0;
		double AvgTFScore = 0;
		double AvgCompleteScore = 0;

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
				FirstName = NewFirstname;
				LastName = NewLastname;
				Username = NewUsername;
				Password = NewPassword;
		}

		bool operator == (const User &ToEqual){
			return ToEqual.Username == Username;
		}

		void DisplayInfo(){
			string IsAdminString = IsAdmin? "Admin\n": "Player\n";
			cout << "Full Name: " << FirstName << " " << LastName << "\n";
			cout << "Username: " << Username << "\n";
			cout << "Role: " << IsAdminString << "\n\n";
		}

		void DisplayUserStatistics(){
			cout << IndentString("Your score statistics per quiz: ", 1) << std::endl;
			cout << IndentString("-Number of quizzes taken: ", 1) << QuizzesTaken << std::endl;
			cout << IndentString("-Highest quiz score: ", 1) << HighestQuizScore << std::endl;
			cout << IndentString("-Lowest quiz score: ", 1) << LowestQuizScore << std::endl;
			cout << IndentString("-Average quiz score: ", 1) << AvgQuizScore << std::endl;
			cout << IndentString("Your score statistics per question type:", 1) <<std::endl;
			cout << IndentString("-Number of MC questions: ", 1) << MCQCount << std::endl;
			cout << IndentString("-Number of complete questions: ", 1) << CompleteCount << std::endl;
			cout << IndentString("-Number of T/F questions: ", 1) << TFCount << std::endl;
			cout << IndentString("-Average grade for MC questions: ", 1) << AvgMCQScore << std::endl;
			cout << IndentString("-Average grade for T/F questions: ", 1) << AvgTFScore << std::endl;
			cout << IndentString("-Average grade for Complete questions: ", 1) << AvgCompleteScore << std::endl;
		}

		void UpdateQuizData(Quiz CurrentQuiz){
			// Averages
			AvgMCQScore = ((AvgMCQScore * MCQCount) + (CurrentQuiz.MCQScore * 2)) / (CurrentQuiz.MCQCount + MCQCount);
			AvgTFScore = ((AvgTFScore * TFCount) + CurrentQuiz.TFScore) / (CurrentQuiz.TFCount + MCQCount);
			AvgCompleteScore = ((AvgCompleteScore * CurrentQuiz.CompleteCount) + (CurrentQuiz.CompleteScore * 3)) / (CurrentQuiz.CompleteCount + CompleteCount);
			AvgQuizScore = ((AvgQuizScore * QuizzesTaken) + CurrentQuiz.UserScore) / (QuizzesTaken + 1);

			// Question Counters
			MCQCount += CurrentQuiz.MCQCount;
			TFCount += CurrentQuiz.TFCount;
			CompleteCount += CurrentQuiz.CompleteCount;

			// Quiz scores
			HighestQuizScore =
				CurrentQuiz.CorrectAnswers > HighestQuizScore
				? CurrentQuiz.CorrectAnswers
				: HighestQuizScore;

			LowestQuizScore =
				LowestQuizScore == 0 && QuizzesTaken == 0
					? CurrentQuiz.CorrectAnswers
					: CurrentQuiz.CorrectAnswers < LowestQuizScore && LowestQuizScore > 0
						? CurrentQuiz.CorrectAnswers
						: LowestQuizScore;

			QuizzesTaken += 1;
		}

		//TODO: Move this outside of structures. Structures are pure and shouldn't depend on utils. Move this to Users utilities
		// void UpdateYourName(){
		// 	FirstName = GetUserInput("Please Enter Your New First Name: ");
		// 	LastName = GetUserInput("Please Enter Your New Last Name: ");
		// }
};


// Displays user scores
//void DisplayScores() {
//	for (int i = 0; i < UserProfile.QuizzesTakenCount; i++) cout << "Quiz [" << i + 1 << "] >> " << UserProfile.Scores[i] << "/" << QUIZ_QUESTIONS_COUNT << "\n";
//
//	cout << "\nEnter [b] to go back to the main menu\nEnter [e] to exit\n";
//	if (GetUserInput("Your choice") == "b") MainMenu();
//}


#endif
