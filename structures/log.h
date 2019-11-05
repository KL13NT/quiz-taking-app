#ifndef LOG_H
#define LOG_H

#include <vector>
#include <string>

using std::string;
using std::vector;


//each log represents a quiz
class Log{
  private:
    bool IsAdminLog = false;
  public:
    Log();
    ~Log();
    friend Log ViewLog(const Log &);
};


// class AdminLog: public Log{
//   private: 
//     vector<string> Questions = {};
//     vector<string> Answers = {};

// };


class PlayerLog: public Log{
  private:
    int TotalScore;
    int UserScore;
    vector<Question> QuizQuestions;
    vector<string> Answers;
  public:
    PlayerLog(vector<Question> Questions, int TotalScoreInput, int UserScore, vector<string> Answers){
      TotalScore = TotalScoreInput;
      UserScore = UserScore;
      QuizQuestions = Questions;
      Answers = Answers;
    }
};


#endif