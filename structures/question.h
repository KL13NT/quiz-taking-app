#ifndef QUESTION_H
#define QUESTION_H

#include <fstream>
#include <string>

using std::string;

class Question {
public:
  int Weight = 1;
  string Title = "";
  string Type = "";
  string CorrectChoice = "";
  string Choice2 = "";
  string Choice3 = "";
  string Choice4 = "";

  Question(){};
  ~Question(){};
  Question(int WeightInput, string TypeInput) {
    Weight = WeightInput;
    Type = TypeInput;
  }

  bool operator == (const Question &Comparable) {
    if (Comparable.Title == Title) return true;
    return false;
  }

  void DisplayQuestion() { cout << Title << "\n"; }
};

class MCQQuestion : public Question {
public:

  MCQQuestion(string TitleInput, string CC, string C2, string C3, string C4): Question(2, "MCQ") {
    Title = TitleInput;
    CorrectChoice = CC;
    Choice2 = C2;
    Choice3 = C3;
    Choice4 = C4;
  }
};

class CompleteQuestion : public Question {
public:
  CompleteQuestion(string TitleInput, string CC) : Question(3, "COMPLETE") {
    Title = TitleInput;
    CorrectChoice = CC;
  }
};

class TFQuestion : public Question {
public:
  TFQuestion(string TitleInput, string CC) : Question(1, "TF") {
    Title = TitleInput;
    CorrectChoice = CC;
  }
};

// // Custom hasher for tables
// struct UsernameHasher {
//   size_t operator()(const User &CurrentUser) const {
//     return std::hash<string> ()(CurrentUser.Username +
//     to_string(CurrentUser.ID);
//   }
// };

// struct QuestionComparator {
//   bool operator()(const string &Username1, const string &Username2) const {
//     int index = std::stoi(str.substr(str.find_last_of(" ")).erase(0, 1));
//     //parse
//     // str.erase(str.find_last_of(" "));
// 		return Username1 == Username2? true: false;
//   }
// };


#endif
