#ifndef LOG_H
#define LOG_H

//each log represents a quiz
class Log{
  public:
    bool IsAdminLog = false;
    int CorrectAnswers = 0;
    double UserScore = 0;
    
    vector<Question> QuizQuestions;
    vector<string> Answers;
    vector<double> QuestionScores;
    Log(){};
    ~Log(){};
};


class PlayerLog: public Log{
  public:
    PlayerLog(Quiz &CurrentQuiz){
      QuizQuestions = CurrentQuiz.QuizQuestions;
      UserScore = CurrentQuiz.UserScore;
      Answers = CurrentQuiz.Answers;
      QuestionScores = CurrentQuiz.QuestionScores;
      CorrectAnswers = CurrentQuiz.CorrectAnswers;
      IsAdminLog = false;
    }
	friend void DisplayLog(Log & CurrentLog);
};


#endif
