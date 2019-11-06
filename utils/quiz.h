#ifndef QUIZ_UTILS_H
#define QUIZ_UTILS_H

// Generates the after-quiz report
void GenerateAfterQuizReport(int CorrectAnswers) {
	cout << "You answered " << CorrectAnswers << "/" << QUIZ_QUESTIONS_COUNT << " questions correctly.\n";
}


// Updates user profile
void UpdateProfileAfterQuiz(int CorrectAnswers) {
	User NewProfile = UserProfile;
	NewProfile.HighestScore =
		CorrectAnswers > UserProfile.HighestScore
		? CorrectAnswers
		: UserProfile.HighestScore;

	NewProfile.LowestScore =
		UserProfile.LowestScore == 0 && UserProfile.QuizzesTakenCount == 0
		? CorrectAnswers
		: CorrectAnswers < UserProfile.LowestScore && UserProfile.LowestScore > 0
		? CorrectAnswers
		: UserProfile.LowestScore;

	NewProfile.QuizzesTaken += 1;
	NewProfile.Scores.push_back(CorrectAnswers);
	NewProfile.AvgScore = std::accumulate(NewProfile.Scores.begin(), NewProfile.Scores.end(), 0.0) / (float)NewProfile.Scores.size();

	UserProfile = NewProfile;
}



// Generates quiz questions by randomly filling an already created GeneratedQuestions array
void GenerateQuizQuestions(Question(&GeneratedQuestions)[QUIZ_QUESTIONS_COUNT]) {
	ShuffleQuestionPool();
	for (int i = 0; i < QUIZ_QUESTIONS_COUNT; i++) {
		GeneratedQuestions[i] = QuestionPool[QuestionPoolIndices[i]];
	}
}


// Starts a new quiz
// void StartNewQuiz() {
// 	Question GeneratedQuestions[QUIZ_QUESTIONS_COUNT];

// 	if (CheckCurrentQuestionPoolSize(QUIZ_QUESTIONS_COUNT)) {
// 		int CorrectAnswers = 0;
// 		GenerateQuizQuestions(GeneratedQuestions);

// 		for (int i = 0; i < QUIZ_QUESTIONS_COUNT; i++) {
// 			DisplayQuestion(GeneratedQuestions[i], i);
// 			int IsCorrect = RandomiseAndPrintAnswers(GeneratedQuestions[i]);
// 			if ((bool) IsCorrect) CorrectAnswers += 1;
// 		}

// 		GenerateAfterQuizReport(CorrectAnswers);
// 		UpdateProfileAfterQuiz(CorrectAnswers);
// 	}
// 	else {
// 		cout << "Please add more questions to the question pool and try again.\n\n";
// 	}

// }


#endif