#ifndef IO_H
#define IO_H


#include <string>
#include <iostream>


using std::string;
using std::cout;
using std::cin;


std::string GetUserInput(std::string Additional = "  "){
  std::string Input;
  getline(std::cin, Input);
	
	if (Input[1] == '\0'){
		if (Input >="0" || Input <= "9"){
			char *Output = new char[];
			Output[0] = Input[0];
			return Output;
		}

		else if(Input >= "a" || Input <= "z"){
			char *Output = new char[];
			Output[0] = Input [0];
			return Output;
		}
	}
	
	return Input;
}

#endif