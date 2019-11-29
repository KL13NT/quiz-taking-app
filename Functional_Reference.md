# Functional Reference
> This document refers declarations and implementations and where they exist.

## Structures
Where classes reside
- [log.h](/structures/log.h)
  - Log{}
    - IsAdminLog: bool
    - CorrectAnswers: bool
    - UserScore: double
    - QuizQuestions: vector<Question>
    - Answers: vector<string>
    - QuestionScores: vector<double>
    - DisplayLog(): void
  
  - PlayerLog{}: Log

- [question.h](/structures/question.h)
  - Question{}
    - Weight: int
    - Title: string
    - Type: string
    - CorrectChoice: string
    - ID: int
    - DisplayQuestion(): void
    - operator ==: bool
  
  - MCQQuestion{}: Question
    - Choice2: string
    - Choice3: string
    - Choice4: string
  
  - CompleteQuestion{}: Question
  
  - TFQuestion{}: Question

- [quiz.h](/structures/quiz.h)
  - Quiz{}
    - CorrectAnswers: int
    - MCQScore: int
    - TFScore: int
    - CompleteScore: int
    - MCQCount: int
    - TFCount: int
    - CompleteCount: int
    - UserScore: int
    - QuizQuestions: vector<Question>
    - Answers: vector<string>
    - QuestionScores: vector<double>
    
- [user.h](/structures/user.h)
  - User{}
    - IsAdmin: bool
    - FirstName: string
    - LastName: string
    - Username: string
    - Password: string
    - Logs: vector<Log>
    - QuizzesTaken: int 
    - HighestQuizScore: double
    - LowestQuizScore: double
    - AvgQuizScore: double
    - MCQCount: int
    - TFCount: int
    - CompleteCount: int
    - AvgMCQScore: double
    - AvgTFScore: double
    - AvgCompleteScore: double
    - UpdateUserData(): void
    - operator ==: bool
    - DisplayInfo(): void
    - DisplayUserStatistics(): void
    - UpdateQuizData(): void
    - UpdateUserData(): void


## Utilities
- [file.h](/utils/file.h)
  - ReadFromFile(string): void
  - GetFileNameFromUser(): void

- [io.h](/utils/io.h)
  - GetUserInput(string): string

- [log.h](/utils/log.h)
  - DisplayLog(Log &): void

- [misc.h](/utils/misc.h)
  - ctoi(const string &): int
  - CheckCurrentQuestionPoolSize(int): bool
  - StringIsEqualIgnoreCase(const string &, const string &): bool
  - StringIsEqual(const string &, const string &): bool
  - VerifyChoice(string &, string &): bool
  - CheckAnswerValidity(const Question &, const string &): bool
  - IsDuplicateQuestion(const string &): bool
  - FormatQuestionTitle(const string &): string
  - MakeHeader(const string &, int): string
  - ParseTFAnswer(const string &): string
  - StringToNumbers(string): string
  - ShuffleQuestionPoolIndices(): void
  - ShuffleAnswerIndices(): void

- [question.h](/utils/question.h)
  - CreateQuestion(): void
  - LoadMCQQuestion(std::ifstream &, string &): void
  - LoadCompleteQuestion(std::ifstream &, string &): CompleteQuestion
  - LoadTFQuestion(std::ifstream &, string &): TFQuestion
  - DisplayQuestionWithAnswers(Question &, int): void
  - DeleteQuestion(int): void
  
  
- [quiz.h](/utils/quiz.h)
  - CheckUserAnswer(const Question &, string &): bool
  - VerifyAnswer(const Question &, string &): bool
  - GenerateQuizQuestions(Quiz &): void
  - GetMCQChoice(const Question &, string &): string
  - SaveQuizData(Quiz &): void
  - QuizDisplayQuestion(Question &, int): void
  - CalculateQuizScores(Quiz &, bool, Question &): void
  - StartNewQuiz(): void
  
- [string.h](/utils/string.h)
  - StringToLowerCase(string): string
  - StringToUpperCase(string): string
  - IndentString(const string, const int): string
  
- [user.h](/utils/user.h)
  - CreateNewUser(): void
  - IsDuplicateUser(string): bool
  - UpdateAccountDetails(): void
  
- [menus.h](/menus.h)
  - AdminMenu(): void
  - PlayerMenu(): void
  - MainMenu(): void
  - Login(): void
  - QuestionsMenuHandler(): void
  - QuestionsMenu(): void
  - DisplayAllUsers(): void
  - SwitchAccount(): void
  - DisplayScores(): void
  - UpdateGreeting(): void  
