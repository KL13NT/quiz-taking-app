#ifndef STRING_H
#define STRING_H

#include <string>
#include <cctype>


string StringToLowerCase(string StringToChange){
  int i = 0;
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


// Returns sentence indented by tabs
string IndentString(const string sentence, const int indent) {
	string indented(indent, '\t');
	indented += sentence;
	return indented;
}


#endif