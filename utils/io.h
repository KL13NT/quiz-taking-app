#ifndef IO_H
#define IO_H


std::string GetUserInput(std::string Additional = "  "){
  std::string Input;
  getline(std::cin, Input);
	
	if (Input[1] == '\0'){
		if (Input[0] >= '0' || Input[0] <= '9'){
			char  *Output = new char[1];
			Output[0] = Input[0];
			return Output;
		}

		else if(Input[0] >= 'a' || Input[0] <= 'z'){
			char *Output = new char[1];
			Output[0] = Input [0];
			return Output;
		}
	}
	
	return Input;
}

#endif