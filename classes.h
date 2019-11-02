#include <string>
#include <vector> 

class Question{
  public:
    int Weight = 1;
    std::string Title = "";
		std::string CorrectChoice = "";
    
		Question(std::string TitleInput, int WeightInput){
      Title = TitleInput;
      Weight = WeightInput;
    }
};

class MCQQuestion: public Question{
  public:
    std::string Choice2;
    std::string Choice3;
    std::string Choice4;
    
		MCQQuestion(std::string TitleInput, std::vector <std::string> Choices): Question(TitleInput, 2){
      CorrectChoice = Choices[0];
      Choice2 = Choices[1];
      Choice3 = Choices[2];
      Choice4 = Choices[3];
    }
};

class CompleteQuestion: public Question{
  public:
    CompleteQuestion(std::string TitleInput, std::string CorrectChoiceInput): Question(TitleInput, 3){
      CorrectChoice = CorrectChoiceInput;
    }
};

class TFQuestion: public Question{
  public:
    bool CorrectChoice = false;
    TFQuestion(std::string TitleInput, bool CorrectChoiceInput): Question(TitleInput, 1){
      CorrectChoice = CorrectChoiceInput;
    }
};