#include <string>
#include <cctype>


using std::string;


string StringToLowerCase(string StringToChange){
  int i = 0;
  char curr;
  string ResultingString = StringToChange;

  while (StringToChange[i]){
    ResultingString[i] = tolower(StringToChange[i]);
    
    i++;
  }

  return ResultingString;
}


string StringToUpperCase(string StringToChange){
  int i = 0;
  string ResultingString = StringToChange;

  while (StringToChange[i]){
    ResultingString[i] = toupper(StringToChange[i]);
    
    i++;
  }

  return ResultingString;
}