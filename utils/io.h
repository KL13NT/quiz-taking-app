#ifndef IO_H
#define IO_H


string GetUserInput(string Additional = "  "){
  string Input;

  if (Additional != "  ") cout << Additional << ": ";

  std::getline(cin, Input);

	return Input;
}

#endif
