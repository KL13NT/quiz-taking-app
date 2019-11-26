#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <string>


// Reads questions from files and adds them to the question pool
void ReadFromFile(string FileName) {
	std::ifstream File;
	string Line;
	File.open(FileName);

	if (File.is_open()) {
		int LoadedQuestionsCount = 0;
		
		while (getline(File, Line)) {
      if(Line == "MCQ" || Line == "TF" || Line == "COMPLETE") {
        string QuestionType = Line;

        getline(File, Line);
        string Title = FormatQuestionTitle(Line);

        if(!IsDuplicateQuestion(Title)){

          if(QuestionType == "MCQ") QuestionPool.push_back(LoadMCQQuestion(File, Line, Title));
          else if(QuestionType == "COMPLETE") QuestionPool.push_back(LoadCompleteQuestion(File, Line, Title));
          else if(QuestionType == "TF") QuestionPool.push_back(LoadTFQuestion(File, Line, Title));


          QuestionPoolSet.insert(Title);
          QuestionPoolIndices.push_back(POOL_QUESTIONS_COUNT);
          LoadedQuestionsCount += 1;
          POOL_QUESTIONS_COUNT += 1;
        }
      }
    }

		File.close();

		cout << "\nLoaded " << LoadedQuestionsCount << " questions successfully.\n\n";
	}

}


void GetFileNameFromUser() {
  std::ifstream File;
  
	string FileName = GetUserInput("\nPlace the file in the same folder as this program exe\nFilename");
  File.open(FileName);

  if (File.is_open()) {
    File.close();

    cout << "\nFile found, loading questions\n";
    return ReadFromFile(FileName);
  }
  
	cout << "\nFile not found, verify that you placed the file containing the questions in the same folder as this program and try again\n\n";
  return GetFileNameFromUser();
}

#endif