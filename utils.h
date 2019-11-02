#include <string>
#include <cctype>

std::string StringToLowerCase(std::string StringToChange){
  int i = 0;
  char curr;
  std::string ResultingString = StringToChange;

  while (StringToChange[i]){
    ResultingString[i] = tolower(StringToChange[i]);
    
    i++;
  }

  return ResultingString;
}

std::string StringToUpperCase(std::string StringToChange){
  int i = 0;
  char curr;
  std::string ResultingString = StringToChange;

  while (StringToChange[i]){
    ResultingString[i] = toupper(StringToChange[i]);
    
    i++;
  }

  return ResultingString;
}