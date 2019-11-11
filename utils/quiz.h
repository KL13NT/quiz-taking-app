#ifndef QUIZ_UTILS_H
#define QUIZ_UTILS_H

// Generates the after-quiz report
void GenerateAfterQuizReport(int CorrectAnswers) {
	cout << "You answered " << CorrectAnswers << "/" << QUIZ_QUESTIONS_COUNT << " questions correctly.\n";
}


// Updates user profile
// void UpdateProfileAfterQuiz(int CorrectAnswers) {
// 	User NewProfile = UserProfile;
// 	NewProfile.HighestScore =
// 		CorrectAnswers > UserProfile.HighestScore
// 		? CorrectAnswers
// 		: UserProfile.HighestScore;

// 	NewProfile.LowestScore =
// 		UserProfile.LowestScore == 0 && UserProfile.QuizzesTakenCount == 0
// 		? CorrectAnswers
// 		: CorrectAnswers < UserProfile.LowestScore && UserProfile.LowestScore > 0
// 		? CorrectAnswers
// 		: UserProfile.LowestScore;

// 	NewProfile.QuizzesTaken += 1;
// 	NewProfile.Scores.push_back(CorrectAnswers);
// 	NewProfile.AvgScore = std::accumulate(NewProfile.Scores.begin(), NewProfile.Scores.end(), 0.0) / (float)NewProfile.Scores.size();

// 	UserProfile = NewProfile;
// }



// Generates quiz questions by randomly filling an already created GeneratedQuestions array
void GenerateQuizQuestions(vector<Question> &GeneratedQuestions) {
	ShuffleQuestionPool();
	for (int i = 0; i < QUIZ_QUESTIONS_COUNT; i++) {
		GeneratedQuestions.push_back(QuestionPool[QuestionPoolIndices[i]]);
	}
}

bool VerifyAnswer(const Question &CurrentQuestion, string &Answer){

	if(CurrentQuestion.Type == "MCQ") {
    if(Answer[0] == 'a' || Answer[0] == 'b' || Answer[0] == 'c' || Answer[0] == 'd' ) return true;
  }

	else if(CurrentQuestion.Type == "TF"){
    if(Answer == "t" || Answer == "f" || Answer == "true" || Answer == "false") return true;
  }

	else if(CurrentQuestion.Type == "COMPLETE") return true;

	return false;
}

// Check whether answer is valid before checking its value
bool CheckUserAnswer(const Question &CurrentQuestion){
	string UserAnswer = StringToLowerCase(GetUserInput("Answer"));

	// Makes sure input is as it's supposed to be as one of the following: [a, b, c, d, t, f, true, false, string with length bigger than 0]
	while(!VerifyAnswer(CurrentQuestion, UserAnswer)){
		cout << "That answer doesn't seem to be valid. Try again.\n";
		UserAnswer = StringToLowerCase(GetUserInput("Answer"));
		cout << "\n" << UserAnswer << "\n";
	}

	if(CurrentQuestion.Type == "MCQ"){
		string Answers[4] = {
			CurrentQuestion.CorrectChoice,
			CurrentQuestion.Choice2,
			CurrentQuestion.Choice3,
			CurrentQuestion.Choice4
		};

		switch (UserAnswer[0]) {
			case 'a':
				return CheckAnswerValidity(CurrentQuestion, Answers[AnswerIndices[0]]);
			case 'b':
				return CheckAnswerValidity(CurrentQuestion, Answers[AnswerIndices[1]]);
			case 'c':
				return CheckAnswerValidity(CurrentQuestion, Answers[AnswerIndices[2]]);
			case 'd':
				return CheckAnswerValidity(CurrentQuestion, Answers[AnswerIndices[3]]);
			}
	}
	else if(CurrentQuestion.Type == "TF"){
		return CheckAnswerValidity(CurrentQuestion, ParseTFAnswer(UserAnswer));
	}

	return CheckAnswerValidity(CurrentQuestion, UserAnswer);
}

void QuizDisplayQuestion(Question &CurrentQuestion, int index){
	string Answers[4] = {
		CurrentQuestion.CorrectChoice,
		CurrentQuestion.Choice2,
		CurrentQuestion.Choice3,
		CurrentQuestion.Choice4
	};

	string Type = CurrentQuestion.Type == "MCQ"? "[Choose one]" : CurrentQuestion.Type == "TF"? "[T]rue | [F]alse": "[Complete]";
	cout << "[" << index + 1 << "]" << CurrentQuestion.Title << "\t" << Type << endl;


	if(CurrentQuestion.Type == "MCQ"){
		string Labels[] = { "[a] ", "[b] ", "[c] ", "[d] " };

		ShuffleAnswers();

		for (int i = 0; i < 4; i++) {
			cout << IndentString((Labels[i] + Answers[AnswerIndices[i]]), 1);
		}
		
		cout << endl;
	}
}

// Starts a new quiz
void StartNewQuiz() {
	vector<Question> GeneratedQuestions;

	if (CheckCurrentQuestionPoolSize(QUIZ_QUESTIONS_COUNT)) {
		int CorrectAnswers = 0;
		int MCQScore = 0;
		int TFScore = 0;
		int CompleteScore = 0;
		
		GenerateQuizQuestions(GeneratedQuestions);

		for (int i = 0; i < QUIZ_QUESTIONS_COUNT; i++) {
			QuizDisplayQuestion(GeneratedQuestions[i], i);

			bool IsCorrectAnswer = CheckUserAnswer(GeneratedQuestions[i]);
			
			if(IsCorrectAnswer) {
				if(GeneratedQuestions[i].Type == "MCQ") MCQScore += 1;
				else if(GeneratedQuestions[i].Type == "TF") TFScore += 1;
				else if(GeneratedQuestions[i].Type == "COMPLETE") CompleteScore += 1;
				
				CorrectAnswers += 1;
			}
			else cout << "Wrong answer\n DEBUGGING\n";
		}

	}
	else {
		cout << "Please add more questions to the question pool and try again.\n\n";
	}

}


#endif
