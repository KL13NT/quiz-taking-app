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
			string QuestionType = Line;

			getline(File, Line);
			string Title = FormatQuestionTitle(Line);

			if(!IsDuplicateQuestion(Title, QuestionPoolSet)){
				
				if(QuestionType == "MCQ") QuestionPool.push_back(LoadMCQQuestion(File, Line, Title));
				else if(QuestionType == "COMPLETE") QuestionPool.push_back(LoadCompleteQuestion(File, Line, Title));
				else if(QuestionType == "TF") QuestionPool.push_back(LoadTFQuestion(File, Line, Title));

				QuestionPoolIndices.push_back(POOL_QUESTIONS_COUNT);
        LoadedQuestionsCount += 1;
        POOL_QUESTIONS_COUNT += 1;
      }
		}

		File.close();

		cout << "\nLoaded " << LoadedQuestionsCount << " questions successfully.\n\n";
	}

}


void GetFileNameFromUser() {
  std::ifstream File;
  
	string FileName = GetUserInput("\nPlace the file in the same folder as this program exe\nEnter the name of the file you wish to load from");
  File.open(FileName);

  if (File.is_open()) {
    File.close();

    cout << "\nFile found, loading questions\n";
    ReadFromFile(FileName);
  }
  
	cout << "\nFile not found, verify that you placed the file containing the questions in the same folder as this program and try again\n\n";
  return GetFileNameFromUser();
}

#endif