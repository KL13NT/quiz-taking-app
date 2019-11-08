#ifndef QUESTION_H
#define QUESTION_H

#include <fstream>
#include <string>
#include <unordered_set>
#include <vector>

using std::string;

class Question {
public:
  int Weight = 1;
  string Title = "";
  string Type = "";
  string CorrectChoice = "";

  Question(){};
  ~Question(){};
  Question(int WeightInput, string TypeInput) {
    Weight = WeightInput;
    Type = TypeInput;
  }

  bool operator==(const Question &Comparable) {
    if (Comparable.Title == Title)
      return true;
    return false;
  }

  void DisplayQuestion() { cout << Title; }

  virtual void DisplayQuestionWithAnswers() = 0;
};

class MCQQuestion : public Question {
public:
  string Choice2;
  string Choice3;
  string Choice4;

  MCQQuestion(string TitleInput, string CC, string C2, string C3, string C4): Question(2, "MCQ") {
    Title = TitleInput;
    CorrectChoice = CC;
    Choice2 = C2;
    Choice3 = C3;
    Choice4 = C4;
  }

  void operator=(const MCQQuestion &ToEqual) {
    Title = ToEqual.Title;
    CorrectChoice = ToEqual.CorrectChoice;
    Choice2 = ToEqual.Choice2;
    Choice3 = ToEqual.Choice3;
    Choice4 = ToEqual.Choice4;
  }

  void DisplayQuestionWithAnswers() {
    string Answers[4] = { CorrectChoice, Choice2, Choice3, Choice4 };
		string Labels[] = { "[a] ", "[b] ", "[c] ", "[d] " };
		
		DisplayQuestion();
		ShuffleAnswers(Answers);

		for (int i = 0; i < 4; i++) cout << Answers[i] == CorrectChoice? IndentString("*" + Labels[i] + Answers[i], 1) : IndentString(Labels[i] + Answers[i]);

		cout << "\n";
};

class CompleteQuestion : public Question {
public:
  CompleteQuestion(string TitleInput, string CC) : Question(3, "COMPLETE") {
    Title = TitleInput;
    CorrectChoice = CC;
  }

  void operator=(const CompleteQuestion &ToEqual) {
    Title = ToEqual.Title;
    CorrectChoice = ToEqual.CorrectChoice;
  }

	void DisplayQuestionWithAnswers(){
		DisplayQuestion();
		cout << "Correct answer is: " << CorrectChoice << "\n";
	}
};

class TFQuestion : public Question {
public:
  TFQuestion(string TitleInput, string CC) : Question(1, "TF") {
    Title = TitleInput;
    CorrectChoice = CC;
  }

  void operator=(const TFQuestion &ToEqual) {
    Title = ToEqual.Title;
    CorrectChoice = ToEqual.CorrectChoice;
  }

	void DisplayQuestionWithAnswers(){
		DisplayQuestion();
		cout << "Correct answer is: " << CorrectChoice << "\n";
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
