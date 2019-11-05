#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector> 
#include <fstream>
#include <unordered_set>

#include "../utils/index.h"


class Question{
  public:
    int Weight = 1;
    std::string Title = "";
		std::string Type = "";
		std::string CorrectChoice = "";
    
		Question();
    ~Question();
		Question(int WeightInput, std::string TypeInput){
      Weight = WeightInput;
			Type = TypeInput;
    }
		
		bool operator == (const Question &Comparable){
			if(Comparable.Title == Title) return true;
			return false;
		}
};

class MCQQuestion: public Question{
  public:
    std::string Choice2;
    std::string Choice3;
    std::string Choice4;
    
		MCQQuestion(std::ifstream &File, std::string &Line): Question(2, "MCQ"){
			getline(File, Line);
			Title = Line;

			getline(File, Line);
      CorrectChoice = Line;

			getline(File, Line);
      Choice2 = Line;

			getline(File, Line);
      Choice3 = Line;

			getline(File, Line);
      Choice4 = Line;
    }

    void operator = (const MCQQuestion &ToEqual){
			Title = ToEqual.Title;
      CorrectChoice = ToEqual.CorrectChoice;
      Choice2 = ToEqual.Choice2;
      Choice3 = ToEqual.Choice3;
      Choice4 = ToEqual.Choice4;
		}
};

class CompleteQuestion: public Question{
  public:
    CompleteQuestion(std::ifstream &File, std::string &Line): Question(3, "COMPLETE"){
      getline(File, Line);
			Title = Line;
			
			getline(File, Line);
			CorrectChoice = Line;
    }
    
    void operator = (const CompleteQuestion &ToEqual){
			Title = ToEqual.Title;
      CorrectChoice = ToEqual.CorrectChoice;
		}
};

class TFQuestion: public Question{
  public:
    TFQuestion(std::ifstream &File, std::string &Line): Question(1, "TF"){
      getline(File, Line);
			Title = Line;
			
			getline(File, Line);
			CorrectChoice = Line;
    }

    void operator = (const TFQuestion &ToEqual){
			Title = ToEqual.Title;
      CorrectChoice = ToEqual.CorrectChoice;
		}
};



// // Custom hasher for tables
// struct UsernameHasher {
//   size_t operator()(const User &CurrentUser) const {
//     return std::hash<std::string> ()(CurrentUser.Username + to_string(CurrentUser.ID);
//   }
// };

// struct QuestionComparator {
//   bool operator()(const string &Username1, const string &Username2) const {
//     int index = std::stoi(str.substr(str.find_last_of(" ")).erase(0, 1)); //parse 
//     // str.erase(str.find_last_of(" "));
// 		return Username1 == Username2? true: false;
//   }
// };


#endif
