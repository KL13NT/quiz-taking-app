#ifndef QUESTION_H
#define QUESTION_H

#include <fstream>
#include <string>

using std::string;

class Question {
public:
  const static int Weight = 1;
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
  const static int Weight = 2;
  MCQQuestion(string TitleInput, string CC, string C2, string C3, string C4, int IDInput): Question("MCQ") {
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
  const static int Weight = 3;
  CompleteQuestion(string TitleInput, string CC, int IDInput) : Question("COMPLETE") {
    Title = TitleInput;
    CorrectChoice = CC;
    ID = IDInput;
  }
};

class TFQuestion : public Question {
public:
  const static int Weight = 1;
  TFQuestion(string TitleInput, string CC, int IDInput) : Question("TF") {
    Title = TitleInput;
    ID = IDInput;
    
    if(CC == "f" || CC == "false") CorrectChoice = "FALSE";
    else if(CC == "t" || CC == "true") CorrectChoice = "TRUE";
  }
};


#endif
