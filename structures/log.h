#ifndef LOG_H
#define LOG_H

//each log represents a quiz
class Log{
  private:
    bool IsAdminLog = false;
  public:
    Log(){};
    ~Log(){};
    friend Log ViewLog(const Log &);
};


//TODO: Possible extra, implement admin log
// class AdminLog: public Log{
//   private: 
//     vector<string> Questions = {};
//     vector<string> Answers = {};
// };


class PlayerLog: public Log{
  private:
    int TotalScore;
    int UserScore;
    int CorrectAnswers;
    vector<Question> QuizQuestions;
    vector<string> Answers;
    vector<double> QuestionScores;
  
  public:
    PlayerLog(vector<Question> Questions, int TotalScoreInput, int UserScoreInput, vector<string> UserAnswers){
      TotalScore = TotalScoreInput;
      QuizQuestions = Questions;
      UserScore = UserScoreInput;
      Answers = UserAnswers;
    }

    DisplayLog(){
      
    }
};


#endif