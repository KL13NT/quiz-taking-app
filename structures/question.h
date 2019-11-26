#ifndef QUESTION_H
#define QUESTION_H

#include <fstream>
#include <string>

using std::string;

class Question {
public:
  int Weight = 0;
  string Title = "";
  string Type = "";
  string CorrectChoice = "";
  string Choice2 = "";
  string Choice3 = "";
  string Choice4 = "";
  int ID = 0;

  Question(){};
  ~Question(){};
  Question(string TypeInput) {
    Type = TypeInput;
  }

  bool operator == (const Question &Comparable) {
    if (Comparable.Title == Title) return true;
    return false;
  }

  void DisplayQuestion() { cout << Title; }
};

class MCQQuestion : public Question {
public:
  MCQQuestion(string TitleInput, string CC, string C2, string C3, string C4, int IDInput): Question("MCQ") {
    Weight = 2;
    Title = TitleInput;
    CorrectChoice = CC;
    Choice2 = C2;
    Choice3 = C3;
    Choice4 = C4;
    ID = IDInput;
  }
};

class CompleteQuestion : public Question {
public:
  CompleteQuestion(string TitleInput, string CC, int IDInput) : Question("COMPLETE") {
    Weight = 3;
    Title = TitleInput;
    CorrectChoice = CC;
    ID = IDInput;
  }
};

class TFQuestion : public Question {
public:
  TFQuestion(string TitleInput, string CC, int IDInput) : Question("TF") {
    Weight = 1;
    Title = TitleInput;
    ID = IDInput;
    
    if(CC == "f" || CC == "false") CorrectChoice = "FALSE";
    else if(CC == "t" || CC == "true") CorrectChoice = "TRUE";
  }
};


#endif
