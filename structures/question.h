#include <string>
#include <vector> 
#include <fstream>
#include <unordered_set>

class Question{
  public:
    int Weight = 1;
    std::string Title = "";
		std::string Type = "";
		std::string CorrectChoice = "";
    
		Question();
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
};

class CompleteQuestion: public Question{
  public:
    CompleteQuestion(std::ifstream &File, std::string &Line): Question(3, "COMPLETE"){
      getline(File, Line);
			Title = Line;
			
			getline(File, Line);
			CorrectChoice = Line;
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
};

// Custom hasher for tables
// struct QuestionHasher {
//   size_t operator()(const Question &CurrentQuestion) const {
//     return std::hash<std::string> ()(CurrentQuestion.Title);
//   }
// };

// struct QuestionComparator {
//   bool operator()(const Question &Question1, const Question &Question2) const {
// 		return Question1.Title == Question2.Title? true: false;
//   }
// };
