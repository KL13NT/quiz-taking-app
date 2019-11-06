#ifndef MISC_H
#define MISC_H

#include <regex>
#include <string>

using std::string;


string FormatQuestionTitle(string QuestionTitle){
  return std::regex_replace (QuestionTitle, std::regex("\\s?\\?"), "");
}


#endif