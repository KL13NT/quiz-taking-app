#ifndef QUIZ_UTILS_H
#define QUIZ_UTILS_H


// Generates the after-quiz report
void GenerateAfterQuizReport(int CorrectAnswers) {
	cout << "You answered " << CorrectAnswers << "/" << QUIZ_QUESTIONS_COUNT << " questions correctly.\n";
}

// Generates quiz questions by randomly filling an already created CurrentQuiz.QuizQuestions array
void GenerateQuizQuestions(Quiz &CurrentQuiz) {
	ShuffleQuestionPool();

	double GeneratedMCQ = 0;
	double GeneratedTF = 0;
	double GeneratedComplete = 0;

	for (int i = 0; i < POOL_QUESTIONS_COUNT; i++) {
		if(GeneratedMCQ < MCQCount || GeneratedTF < TFCount || GeneratedComplete < CompleteCount){
			bool IsValid = false;

			if(QuestionPool[QuestionPoolIndices[i]].Type == "MCQ" && GeneratedMCQ < MCQCount){
				IsValid = true;
				GeneratedMCQ += 1;
			}
			else if(QuestionPool[QuestionPoolIndices[i]].Type == "TF" && GeneratedTF < TFCount){
				IsValid = true;
				GeneratedTF += 1;
			}
			else if(QuestionPool[QuestionPoolIndices[i]].Type == "COMPLETE" && GeneratedComplete < CompleteCount){
				IsValid = true;
				GeneratedComplete += 1;
			}

			if(IsValid) CurrentQuiz.QuizQuestions.push_back(QuestionPool[QuestionPoolIndices[i]]);
		}
		else break;
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
bool CheckUserAnswer(const Question &CurrentQuestion, string &UserAnswer){
	// REFACTORME
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

void CalculateQuizScores(Quiz &CurrentQuiz, bool IsCorrectAnswer, Question &CurrentQuestion){
	if(CurrentQuestion.Type == "MCQ") {
		if(IsCorrectAnswer){
			CurrentQuiz.MCQScore = CurrentQuiz.MCQScore + 2;
			CurrentQuiz.UserScore += 2;
		}
		CurrentQuiz.QuestionScores.push_back(IsCorrectAnswer? 2: 0);
		CurrentQuiz.MCQCount += 1;
	}
	else if(CurrentQuestion.Type == "TF") {
		if(IsCorrectAnswer){
			CurrentQuiz.TFScore = CurrentQuiz.TFScore + 1;
			CurrentQuiz.UserScore += 1;
		}
		CurrentQuiz.QuestionScores.push_back(IsCorrectAnswer? 1: 0);
		CurrentQuiz.TFCount += 1;
	}
	else if(CurrentQuestion.Type == "COMPLETE") {
		if(IsCorrectAnswer){
			CurrentQuiz.CompleteScore = CurrentQuiz.CompleteScore + 3;
			CurrentQuiz.UserScore += 3;
		}
		CurrentQuiz.QuestionScores.push_back(IsCorrectAnswer? 3: 0);
		CurrentQuiz.CompleteCount += 1;
	}

	if(IsCorrectAnswer) CurrentQuiz.CorrectAnswers += 1;
}

void LogQuizData(Quiz &CurrentQuiz){
	UserProfile -> UpdateQuizData(CurrentQuiz);
	
	PlayerLog CurrentLog(CurrentQuiz);
	UserProfile -> Logs.push_back(CurrentLog);
}

string GetMCQChoice(Question &CurrentQuestion, string &UserAnswer){
	string Answers[4] = {
		CurrentQuestion.CorrectChoice,
		CurrentQuestion.Choice2,
		CurrentQuestion.Choice3,
		CurrentQuestion.Choice4
	};

	switch (UserAnswer[0]) {
		case 'a':
			return Answers[AnswerIndices[0]];
		case 'b':
			return Answers[AnswerIndices[1]];
		case 'c':
			return Answers[AnswerIndices[2]];
		case 'd':
			return Answers[AnswerIndices[3]];
	}
}
// Starts a new quiz
void StartNewQuiz() {
	if (CheckCurrentQuestionPoolSize(QUIZ_QUESTIONS_COUNT)) {
		Quiz CurrentQuiz;

		GenerateQuizQuestions(CurrentQuiz);

		for (int i = 0; i < QUIZ_QUESTIONS_COUNT; i++) {
			QuizDisplayQuestion(CurrentQuiz.QuizQuestions[i], i);

			string UserAnswer = StringToLowerCase(GetUserInput("Answer"));
			// Makes sure input is as it's supposed to be as one of the following:
			// [a, b, c, d, t, f, true, false, string with length bigger than 0]
			while(!VerifyAnswer(CurrentQuiz.QuizQuestions[i], UserAnswer)){
				cout << "That answer doesn't seem to be valid. Try again.\n";
				UserAnswer = StringToLowerCase(GetUserInput("Answer"));
			}

			// REFACTORME
			CurrentQuiz.Answers.push_back(CurrentQuiz.QuizQuestions[i].Type == "MCQ"? GetMCQChoice(CurrentQuiz.QuizQuestions[i], UserAnswer): UserAnswer);
			
			bool IsCorrectAnswer = CheckUserAnswer(CurrentQuiz.QuizQuestions[i], UserAnswer);

			CalculateQuizScores(CurrentQuiz, IsCorrectAnswer, CurrentQuiz.QuizQuestions[i]);
		}

		LogQuizData(CurrentQuiz);

	}
	else {
		cout << "Please add more questions to the question pool and try again.\n\n";
	}

}


#endif
