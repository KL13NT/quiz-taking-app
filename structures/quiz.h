#ifndef QUIZ_H
#define QUIZ_H


class Quiz {
public:
  int CorrectAnswers = 0;
  int MCQScore = 0;
  int TFScore = 0;
  int CompleteScore = 0;

  int MCQCount = 0;
  int TFCount = 0;
  int CompleteCount = 0;
  
  int UserScore = 0;
  vector<Question> QuizQuestions;
  vector<string> Answers;
  vector<double> QuestionScores;

  Quiz(){};
};


#endif