#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>


using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::unordered_set;


// Checks whether the question is a duplicate
bool IsDuplicateQuestion(const Question &CurrentQuestion, const unordered_set<string> &QuestionPoolSet){
	auto QuestionIterator = QuestionPoolSet.find(CurrentQuestion.Title);
	
  if(QuestionIterator != QuestionPoolSet.end()) return true;
  return false;
}


//Checks if question pool has enough questions >= QUIZ_QUESTIONS_COUNT
bool CheckCurrentQuestionPoolSize(int ExpectedSize, int POOL_QUESTIONS_COUNT) {
	if (POOL_QUESTIONS_COUNT >= ExpectedSize) return true;
	return false;
}


// Shuffles question pool
void ShuffleQuestionPool() {
	vector<Question> NewPool;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(QuestionPoolIndices.begin(), QuestionPoolIndices.end(), std::default_random_engine(seed));

	for (int i = 0; i < POOL_QUESTIONS_COUNT; i++) NewPool.push_back(QuestionPool[QuestionPoolIndices[i]]); // Copies pool away randomly
	for (int i = 0; i < POOL_QUESTIONS_COUNT; i++) QuestionPool[i] = NewPool[i]; // Copies randomised questions over again
}