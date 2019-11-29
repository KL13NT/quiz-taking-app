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
    



## Utilities
