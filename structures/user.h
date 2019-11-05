#ifndef USER_H
#define USER_H

#include "../utils/index.h"
#include "../menus.h"

// Updates username
void UpdateUserName() {
	UserProfile.Name = GetUserString("New name");
}


// Displays user score statistics
void DisplayStatistics() {
	cout << "Your score statistics: \n\t- Number of quizzes taken: " << UserProfile.QuizzesTakenCount << "\n\t- Highest Score: " << UserProfile.HighestScore << "/" << QUIZ_QUESTIONS_COUNT << "\n\t- Lowest Score: " << UserProfile.LowestScore << "/" << QUIZ_QUESTIONS_COUNT << "\n\t- Average Score: " << UserProfile.AvgScore << "/" << QUIZ_QUESTIONS_COUNT << "\nEnter [b] to go back to the main menu\nEnter [e] to exit\n";

	if (GetUserChar("Your choice") == 'b') MainMenu();
}


// Displays user scores
void DisplayScores() {
	for (int i = 0; i < UserProfile.QuizzesTakenCount; i++) cout << "Quiz [" << i + 1 << "] >> " << UserProfile.Scores[i] << "/" << QUIZ_QUESTIONS_COUNT << "\n";

	cout << "\nEnter [b] to go back to the main menu\nEnter [e] to exit\n";
	if (GetUserChar("Your choice") == 'b') MainMenu();
}


#endif