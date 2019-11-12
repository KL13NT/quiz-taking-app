#ifndef LOG_UTILS_H
#define LOG_UTILS_H

void DisplayLog(Log &CurrentLog){
  for(int i = 0; i < (int) CurrentLog.QuizQuestions.size(); i++) {
    string UserAnswer = (CurrentLog.QuizQuestions[i].Type == "TF"? ParseTFAnswer(CurrentLog.Answers[i]): CurrentLog.Answers[i]);
    
    cout << "Q. ";
    CurrentLog.QuizQuestions[i].DisplayQuestion();
    cout << "\n";
    cout << IndentString("Your score for this question was: ", 1) << CurrentLog.QuestionScores[i] << "/" << CurrentLog.QuizQuestions[i].Weight << "\n";
    cout << IndentString("You answered: ", 1) << UserAnswer << (CurrentLog.QuestionScores[i] == 0? " [WRONG]": " [CORRECT]") << "\n";

    if(CurrentLog.QuestionScores[i] == 0) cout << IndentString("The correct answer is: ", 1) << CurrentLog.QuizQuestions[i].CorrectChoice << "\n";


    cout << "\n";
  }
}


#endif