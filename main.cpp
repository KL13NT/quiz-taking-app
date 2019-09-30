#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <fstream>
#include <ctime>

// Questions per quiz required
const int QUIZ_QUESTIONS_COUNT = 5;
int POOL_QUESTIONS_COUNT = 0;

struct Question{
  std::string QuestionTitle;
  std::string CorrectChoice;
  std::string Choice2;
  std::string Choice3;
  std::string Choice4;
  int QuestionID;
  // std::string Choices[4] = {CorrectChoice, Choice2, Choice3, Choice4};
};

struct Profile{
  std::string Name = "USER";
  std::vector<int> Scores;
  int QuizzesTakenCount = 0;
  int HighestScore = 0;
  int LowestScore = 0;
  float AvgScore = 0.0;
} UserProfile;


struct Quiz{
  int CorrectAnswersCount = 0;
  int WrongAnswersCount = 0;
  Question QuizQuestions[QUIZ_QUESTIONS_COUNT];
};

/*
  Read file line by line (Function)
    lineGroup = 0;
    Question NewQuestion;
    vector<Question>
    0 > question
    1 > correct choice
    2 > 2nd
    3 > 3rd
    4 > 4th
    ------------
    while iterating



*/

std::vector<Question> QuestionPool;

std::string GetUserString(); //!TESTED
std::string GetUserInt(); //!TESTED
std::string IndentString(std::string sentence, int indent); //!TESTED
int GenerateRandomInteger(); //!TESTED
bool CheckDuplicateQuestion(Question CurrentQuizQuestions[], Question CurrentQuestion); //!TESTED
bool CheckAnswerValidity(Question CurrentQuestion, std::string Answer); //!TESTED
bool CheckCurrentQuestionPoolSize(int ExpectedSize); //!TESTED
bool ArrayIncludes(std::string Searchables[], std::string Searchable, int ArraySize); //!TESTED
bool RandomiseAndPrintAnswers(Question CurrentQuestion); //!AWAITING
void MainMenu(); //!TESTED
void AdminMenu(); //!TESTED
void StartNewQuiz(); //!AWAITING
void UpdateProfile(Profile NewProfile); //!AWAITING
void UpdateUserName(); //!TESTED
void AddQuestion(); //!TESTED
void DisplayAllQuestions(); //!TESTED
void DisplayQuestionWithAnswers(Question CurrentQuestion, int QuestionIndex); //!TESTED
void DisplayQuestion(Question CurrentQuestion, int QuestionIndex); //!TESTED
Profile GenerateReport(std::string Name); //!AWAITING
void GenerateQuizQuestions(Question (&GeneratedQuestions)[QUIZ_QUESTIONS_COUNT]); //!AWAITING
// Quiz UpdateQuizState(Quiz CurrentQuiz, int CorrectAnswersCount = NULL, int WrongAnswersCount = NULL); //!AWAITING


//HELPERS

// Generate a random integer
int GenerateRandomInteger(int limit = 10){
  srand(time(NULL));
  return rand() % limit;
}

//Checks if question pool has enough questions >= QUIZ_QUESTIONS_COUNT
bool CheckCurrentQuestionPoolSize(int ExpectedSize){
  if(POOL_QUESTIONS_COUNT >= ExpectedSize) return true;
  return false;
}

// Takes user input string and returns it
std::string GetUserString(std::string Additional = "  "){
  std::string Input;
  if(Additional != "  "){
    std::cout << Additional << ": ";
    getline(std::cin, Input);
    return Input;
  }
  getline(std::cin, Input);
  std::cout << "\n";
  return Input;
}


char GetUserChar(std::string Additional = "  "){
  char InputChar;
  if(Additional != "  "){
    std::cout << Additional << ": ";
    std::cin >> InputChar;
    std::cin.ignore(1000, '\n');
    return InputChar;
  }
  std::cin >> InputChar;
  std::cin.ignore(1000, '\n');
  std::cout << "\n";
  return InputChar;
}


/*
  @description Takes user input character and returns it
*/
int GetUserInt(std::string Additional = "  "){
  int InputChar;
  if(Additional != "  "){
    std::cout << Additional << ": ";
    std::cin >> InputChar;
    std::cin.ignore(1000, '\n');
    return InputChar;
  }
  std::cin >> InputChar;
  std::cin.ignore(1000, '\n');
  std::cout << "\n";
  return InputChar;
}

// Controls the addition of new questions
void AddQuestion(){
  Question NewQuestion;

  NewQuestion.QuestionTitle = GetUserString("Question without question mark");
  NewQuestion.CorrectChoice = GetUserString("Correct Choice");
  NewQuestion.Choice2 = GetUserString("Second Choice");
  NewQuestion.Choice3 = GetUserString("Third Choice");
  NewQuestion.Choice4 = GetUserString("Last Choice");
  NewQuestion.QuestionID = POOL_QUESTIONS_COUNT;
  std::cout << "\nAdded new question: " <<  NewQuestion.QuestionTitle << "\n\n";
  QuestionPool.push_back(NewQuestion);
  POOL_QUESTIONS_COUNT += 1;
}

// Updates username
void UpdateUserName(){
  UserProfile.Name = GetUserString("New name");
}


// Quiz UpdateQuizState(Quiz CurrentQuiz, int CorrectAnswersCount = NULL, int WrongAnswersCount = NULL){
//   if(CorrectAnswersCount == NULL || WrongAnswersCount == NULL) return;

//   if(CorrectAnswersCount != NULL) CurrentQuiz.CorrectAnswersCount = CorrectAnswersCount;
//   if(WrongAnswersCount != NULL) CurrentQuiz.WrongAnswersCount = WrongAnswersCount;

//   return CurrentQuiz;
// }


void UpdateProfile(Profile NewProfile){
  if(
    UserProfile.QuizzesTakenCount != NewProfile.QuizzesTakenCount ||
    UserProfile.HighestScore != NewProfile.HighestScore ||
    UserProfile.LowestScore != NewProfile.LowestScore ||
    UserProfile.AvgScore != NewProfile.AvgScore ||
    UserProfile.Scores != NewProfile.Scores
    )
      UserProfile = NewProfile;
}

bool CheckAnswerValidity(Question CurrentQuestion, std::string Answer){
  if(Answer == CurrentQuestion.CorrectChoice){
    return true;
  }
  else return false;
}

/**
 * creating Vectors for each answer type
 * [{"swan"}, "duck", "hen", "emu"]
 * randomise
 * ["duck", "emu", "hen", {"swan"}]
 * ["duck", 0, "emu", 0,  "hen", 0, {"swan"}, 1]
 * ['a', 'b', 'c', 'd']
 * Question.CorrectChoice == "swan" > correct
 * cout << "a b c d"
 * [a, 1, b, 0, c, 0, d, 0]
 * input > [b] false wrong | 1 > true correct
 *
*/

//Checks if array includes element
bool ArrayIncludes(std::string Searchables[], std::string Searchable, int ArraySize){
  for(int i = 0; i < ArraySize; i++){
     if(Searchables[i] == Searchable){
        return true;
     }
  }
  return false;
}


bool RandomiseAndPrintAnswers(Question CurrentQuestion){
  std::string AnswersBeforeRandomising[4] = { CurrentQuestion.CorrectChoice, CurrentQuestion.Choice2, CurrentQuestion.Choice3, CurrentQuestion.Choice4 };
  std::string AnswersAfterRandomising[4];
  std::string ArrayCheck [4];
  int Index;

  for (int Counter = 0; Counter < 4; ++Counter){
    Index = GenerateRandomInteger(4);
    ArrayCheck[Counter] = AnswersBeforeRandomising[Index];

    if (ArrayIncludes(ArrayCheck, AnswersBeforeRandomising[Index], 4) == 0){
      AnswersBeforeRandomising[Counter] = AnswersAfterRandomising[Index];
    }
    else {
      Index = GenerateRandomInteger(4);
      AnswersBeforeRandomising[Counter] = AnswersAfterRandomising[Index];
    }
  }
  std::string RandomisedAnswers[4];
  std::cout << IndentString("[a] ", 1) << RandomisedAnswers[0] << IndentString("[b] ", 1) << RandomisedAnswers[1] << IndentString("[c] ", 1) << RandomisedAnswers[2] << IndentString("[d] ", 1) << RandomisedAnswers[3] << "\n\n";

  bool IsAnswerCorrect;
  bool IsValidChoice = false;
  do{
    switch(GetUserChar("Answer letter")){
      case 'a':
        IsAnswerCorrect = CheckAnswerValidity(CurrentQuestion, AnswersAfterRandomising[0]);
        IsValidChoice = true;
        break;
      case 'b':
        IsAnswerCorrect = CheckAnswerValidity(CurrentQuestion, AnswersAfterRandomising[1]);
        IsValidChoice = true;
        break;
      case 'c':
        IsAnswerCorrect = CheckAnswerValidity(CurrentQuestion, AnswersAfterRandomising[2]);
        IsValidChoice = true;
        break;
      case 'd':
        IsAnswerCorrect = CheckAnswerValidity(CurrentQuestion, AnswersAfterRandomising[3]);
        IsValidChoice = true;
        break;
      default:
        IsValidChoice = false;
    }
  }
  while(IsValidChoice == false);

  return IsAnswerCorrect;
}


void GenerateAfterQuizReport(int CorrectAnswers){
  std::cout << "You answered " << CorrectAnswers << "/" << QUIZ_QUESTIONS_COUNT << " questions correctly.\n";
  // Profile NewProfile;
  // int QuizzesTakenCount = 0;
  // int HighestScore = 0;
  // int LowestScore = 0;
  // float AvgScore = 0.0;
}


bool CheckDuplicateQuestion(Question CurrentQuizQuestions[], Question CurrentQuestion){

  for(int Counter = 0; Counter < QUIZ_QUESTIONS_COUNT; ++Counter){

    if(CurrentQuizQuestions[Counter].QuestionTitle == CurrentQuestion.QuestionTitle) return true;
    else return false;

  }
}


void GenerateQuizQuestions(Question (&GeneratedQuestions)[QUIZ_QUESTIONS_COUNT]){

  int Counter = 0;

    while(Counter < QUIZ_QUESTIONS_COUNT){
      int RandomlyGeneratedIndex = GenerateRandomInteger(QUIZ_QUESTIONS_COUNT);
      if(RandomlyGeneratedIndex < POOL_QUESTIONS_COUNT){

      if(!CheckDuplicateQuestion(GeneratedQuestions, QuestionPool.at(RandomlyGeneratedIndex))){
        GeneratedQuestions[Counter] = QuestionPool.at(RandomlyGeneratedIndex);
      }
    }
    ++Counter;
  }
}


// Displays all quesitons in the question pool
void DisplayAllQuestions(){
  if(CheckCurrentQuestionPoolSize(1)){
    for(int i = 0; i < POOL_QUESTIONS_COUNT; i++){
      DisplayQuestionWithAnswers(QuestionPool[i], i);
    }
  }
  else{
    std::cout << "Please add more questions to the question pool and try again.\n\n";
  }
}

void QuestionsMenuHandler(){
  std::cout << std::string (15, '-') << "\nEnter [d] without the brackets followed by the question ID to delete a question (Example: d 2)\nEnter [b] to go back to the main menu\n\n";
  std::string UserChoice =  GetUserString("Your choice");
  
  if(UserChoice == "b") MainMenu();
  else if(UserChoice[0] == 'd' && UserChoice[1] == ' ' && UserChoice[2]){
    char IndexOfQuestionAsChar = UserChoice[2];
    int IndexOfQuestion = IndexOfQuestionAsChar - '0';
    if(IndexOfQuestion <= POOL_QUESTIONS_COUNT){
      std::cout << "\nDeleted the following question: " << QuestionPool[IndexOfQuestion].QuestionTitle << "\n\n";

      std::vector<Question>::iterator it = QuestionPool.begin();
      std::advance(it, UserChoice[2]);
      QuestionPool.erase(it);
      MainMenu();
    }
    else{
      std::cout << "We didn't quite catch that, try again, perhaps?\n\n";
      QuestionsMenuHandler();
      return;
    }
  }
  else{
    std::cout << "We didn't quite catch that, try again, perhaps?\n\n";
    QuestionsMenuHandler();
    return ;
  }
}

void QuestionsMenu(){
  std::cout << "\n\nNumber of questions available: " << POOL_QUESTIONS_COUNT << "\n\n";
  if(CheckCurrentQuestionPoolSize(1)){
    std::cout << "Questions list:\n---------------\n";

    DisplayAllQuestions();
    QuestionsMenuHandler();

  }
}

// Displays a single question as part of a list
void DisplayQuestion(Question CurrentQuestion, int QuestionIndex){
  std::cout << "[" << QuestionIndex << "] " << CurrentQuestion.QuestionTitle << "?\n";
}

// Displays a question followed by its answers
void DisplayQuestionWithAnswers(Question CurrentQuestion, int QuestionIndex){
  DisplayQuestion(CurrentQuestion, QuestionIndex);
  std::cout << IndentString("[a] ", 1) << CurrentQuestion.CorrectChoice << IndentString("[b] ", 1) << CurrentQuestion.Choice2[1] << IndentString("[c] ", 1) << CurrentQuestion.Choice2 << IndentString("[d] ", 1) << CurrentQuestion.Choice3 << "\n\n";
}

// Starts a new quiz
void StartNewQuiz(){
  Quiz NewQuiz;
  Question GeneratedQuestions[QUIZ_QUESTIONS_COUNT];

  if(CheckCurrentQuestionPoolSize(QUIZ_QUESTIONS_COUNT)){
    int CorrectAnswers = 0;
    GenerateQuizQuestions(GeneratedQuestions);

    for(int i = 0; i < QUIZ_QUESTIONS_COUNT; i++){
      DisplayQuestion(GeneratedQuestions[i], i);
      if(RandomiseAndPrintAnswers(GeneratedQuestions[i]) == true) CorrectAnswers += 1;
    }

    GenerateAfterQuizReport(CorrectAnswers);
  }
  else{
    std::cout << "Please add more questions to the question pool and try again.\n\n";
  }

  //TODO: Display report
  //TODO: update profile
  //TODO: return to main menu
}


// Returns sentence indented by tabs
std::string IndentString(std::string sentence, int indent){
  std::string indented(indent, '\t');
  indented += sentence;
  return indented;
}

// Displays main menu
void MainMenu(){
  std::cout << "Welcome " << UserProfile.Name << ", please choose from the following options:\n";
  std::cout << IndentString("[1] Go to administration menu\n", 1);
  std::cout << IndentString("[2] Update your name\n", 1);
  std::cout << IndentString("[3] Start a new quiz\n", 1);
  std::cout << IndentString("[4] Display your scores statistics\n", 1);
  std::cout << IndentString("[5] Display all your scores\n", 1);
  std::cout << IndentString("[6] Exit\n", 1);
  //TODO: Take user input and push it through a switch

  switch(GetUserInt("Your choice")){
    case 1:
      AdminMenu();
      break;
    case 2:
      UpdateUserName();
      break;
    case 3:
      StartNewQuiz();
      break;
    case 4:
      //DisplayStatistics();
      break;
    case 5:
      //DisplayAllScores();
      break;
    case 6:
      // Exit();
      break;
    default:
      std::cout << "We didn't quite understand that, try again, perhaps?\n";
      MainMenu();
  }
  MainMenu();
}


// Displays administration menu
void AdminMenu(){
  std::cout << "Welcome to the administration menu, please choose from the following options:\n";
  std::cout << IndentString("[1] View all questions\n", 1);
  std::cout << IndentString("[2] Add new question\n", 1);
  std::cout << IndentString("[3] Load questions from file\n", 1);
  std::cout << IndentString("[4] Go back to main menu\n", 1);

  switch(GetUserInt("Your choice")){
    case 1:
      QuestionsMenu();
      break;
    case 2:
      AddQuestion();
      break;
    case 3:
      //LoadQuestions()
      break;
    case 4:
      MainMenu();
      break;
    default:
      std::cout << "We didn't quite understand that, try again, perhaps?\n";
      AdminMenu();
  }
  //TODO: Take user input and push it through a switch
}


int main(){
  MainMenu();

  //std::cout << Input; // Testing Input
  return 0;
}
