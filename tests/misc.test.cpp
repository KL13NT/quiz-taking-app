#include <string>
#include <iostream>

#include "catch.hpp"

using namespace std;


SCENARIO("StringToUpper/LowerCase"){
  string TestString = "Hello, world!";
  string TestStringUpper = "HELLO, WORLD!";
  string TestStringLower = "hello, world!";
  string TestNumbers = "1239123";
  string TestStringArabic = "أهلاً و سهلاً";
  
  GIVEN( "A string" ) {
    WHEN("calling StringToUpperCase/StringToLowerCase with English characters"){
      THEN("should return string all in uppercase/lowercase"){
        REQUIRE(StringToUpperCase(TestString) == TestStringUpper);
        REQUIRE(StringToLowerCase(TestString) == TestStringLower);
      }
    }

    WHEN("calling StringToUpperCase/StringToLowerCase with Arabic characters"){
      THEN("should return the same string"){
        REQUIRE(StringToUpperCase(TestStringArabic) == TestStringArabic);
      }
    }

    WHEN("calling StringToUpperCase/StringToLowerCase with numeral characters"){
      THEN("should return the same string"){
        REQUIRE(StringToUpperCase(TestNumbers) == TestNumbers);
      }
    }

    WHEN("calling StringToUpperCase/StringToLowerCase with special characters"){
      THEN("should return the same string"){
        REQUIRE(StringToUpperCase("!@#!@#") != "!@#!@#!");
      }
    }
  }
}

SCENARIO( "FormatQuestionTitle") {
  WHEN("calling FormatQuestionTitle with numbers, should return as is"){
    REQUIRE(FormatQuestionTitle("123") == "123");
  }

  WHEN("calling FormatQuestionTitle with question ending in any combination of ?! should return question only one ?"){
    REQUIRE(FormatQuestionTitle("Example question!!??") == "Example question");
  }
  
  WHEN("calling FormatQuestionTitle with special characters, should return without them"){
    REQUIRE(FormatQuestionTitle("Test ? Question?") == "Test Question");
  }
}

SCENARIO( "StringToNumbers") {
  WHEN("calling StringToNumbers"){
    REQUIRE(StringToNumbers("123") == "123");
  }

  WHEN("calling StringToNumbers should return a string containing numbers only no matter what input is."){
    REQUIRE(StringToNumbers("Example question123123") == "123123");
    REQUIRE(StringToNumbers("Example 123 okasdok 123") == "123123");
    REQUIRE(StringToNumbers("!1@2#3$4%5") == "12345");
  }
}

SCENARIO( "IsDuplicateQuestion") {
  QuestionPoolSet.insert(MCQQuestion("Test question title", "1", "1", "1", "1", 0).Title);

  GIVEN("An unordered_set of questions QuestionPool"){
    WHEN("Calling IsDuplicateQuestion should return true if question already exists"){
      REQUIRE(IsDuplicateQuestion("Test question title") == true);
    }

    WHEN("Calling IsDuplicateQuestion should return false if question doesn't exist"){
      REQUIRE(IsDuplicateQuestion("Test doesn't exist question") == false);
    }
  }
  
  QuestionPoolSet.clear();
}

SCENARIO( "CheckQuestionPoolSize" ){
  WHEN("Calling CheckCurrentQuestionPoolSize with an integer or character"){
    REQUIRE(CheckCurrentQuestionPoolSize(0) == true);
    REQUIRE(CheckCurrentQuestionPoolSize(1) == false);
    REQUIRE(CheckCurrentQuestionPoolSize(1.0) == false);
    REQUIRE(CheckCurrentQuestionPoolSize(1.5) == false);
    REQUIRE(CheckCurrentQuestionPoolSize('a') == false);
  }
}

SCENARIO( "CheckAnswerValidity" ){
  MCQQuestion TestMCQ("Test question", "Correct answer", "ans2", "ans3", "ans4", 0);
  string CorrectAnswer = "Correct answer";
  string WrongAnswer = "Wrong";

  GIVEN("A question and an answer"){
    WHEN("passing a correct answer"){
      THEN("should return true"){
        REQUIRE(CheckAnswerValidity(TestMCQ, CorrectAnswer) == true);
      }
    }
    WHEN("Passing a wrong answer should return false"){
      THEN("should return false"){
        REQUIRE(CheckAnswerValidity(TestMCQ, WrongAnswer) == false);
      }
    }
  }
}

SCENARIO( "ParseTFAnswer" ){
  GIVEN("An input of [f | t | false | true]"){
    WHEN("passing that input should"){
      THEN("should return their respective uppercase strings"){
        REQUIRE(ParseTFAnswer("f") == "FALSE");
        REQUIRE(ParseTFAnswer("t") == "TRUE");
        REQUIRE(ParseTFAnswer("true") == "TRUE");
        REQUIRE(ParseTFAnswer("false") == "FALSE");
      }
    }
  }
}

SCENARIO( "ctoi" ){
  WHEN("passing character ranging from '0' to '9'"){
    THEN("should return the integer contained"){
      REQUIRE(ctoi("1") == 1);
      REQUIRE(ctoi("5") == 5);
      REQUIRE(ctoi("1.555566") == 1);
      REQUIRE(ctoi("0") == 0);
    }
  }
  WHEN("passing anything else"){
    THEN("should return -1 integer"){
      REQUIRE(ctoi("a") == -1);
      REQUIRE(ctoi("\n") == -1);
      REQUIRE(ctoi("\n\0") == -1);
      REQUIRE(ctoi("z") == -1);
      REQUIRE(ctoi("random string") == -1);
    }
  }
}

SCENARIO( "ShuffleQuestionPoolIndices/ShuffleAnswerIndices" ){
  for(int i = 0; i < 10; i ++){ //preparing indices for test
    QuestionPoolIndices.push_back(i);
  }

  vector<int> TestPoolIndices = QuestionPoolIndices;
  vector<int> TestAnswerIndices = AnswerIndices;
  

  GIVEN("QuestionPool vector"){
    WHEN("calling ShuffleQuestionPoolIndices"){
      THEN("should make comparison to original pool false"){
        ShuffleQuestionPoolIndices();
        
        bool Identical = true;

        for(int i = 0; i < (int) QuestionPoolIndices.size(); i++){
          if(TestPoolIndices[i] != QuestionPoolIndices[i]) Identical = false;
          if(Identical == false) break;
        }

        REQUIRE(Identical == false);
      }
    }
  }

  GIVEN("Answers array"){
    WHEN("calling ShuffleAnswerIndices"){
      THEN("should return shuffled array"){
        ShuffleAnswerIndices();
        bool Identical = true;

        for(int i = 0; i < (int) QuestionPoolIndices.size(); i++){
          if(TestAnswerIndices[i] != AnswerIndices[i]) Identical = false;
          if(Identical == false) break;
        }

        REQUIRE(Identical == false);
      }
    }
  }
}

SCENARIO( "MakeHeader" ){
  string With0 = "\n" + string(20, '-') + "\nExample header\n" + string(20, '-') + "\n";
  string WithFloat = "\n" + string(20, '-') + "\nExample header\n" + string(20, '-') + "\n";

  WHEN("calling MakeHeader with 0 as multiplier"){
    THEN("should use defaul multiplier of 20"){
      REQUIRE(MakeHeader("Example header", 0) == With0);
    }
  }
  WHEN("callling MakeHeader with a float"){
    THEN("should cast it into an integer and use it"){
      REQUIRE(MakeHeader("Example header", 20.5) == WithFloat);
    }
  }
}

SCENARIO( "StringIsEqual/IgnoreCase" ){
  string TestUpper = "TEST1";
  string TestLower = "test1";
  string TestDiff = "different";

  WHEN("passing two identical strings but different in case to StringIsEqualIgnoreCase"){
    THEN("should return true"){
      REQUIRE(StringIsEqualIgnoreCase(TestUpper, TestLower) == true);
    }
  }
  WHEN("passing two identical strings but different in case to StringIsEqual"){
    THEN("should return false"){
      REQUIRE(StringIsEqual(TestUpper, TestLower) == false);
    }
  }
  WHEN("passing two identical strings with identical case to StringIsEqual"){
    THEN("should return false"){
      REQUIRE(StringIsEqual(TestUpper, TestLower) == false);
    }
  }
  WHEN("passing two different strings to StringIsEqualIgnoreCase"){
    THEN("should return false"){
      REQUIRE(StringIsEqualIgnoreCase(TestUpper, TestDiff) == false);
    }
  }
  WHEN("passing two different strings to StringIsEqual"){
    THEN("should return false"){
      REQUIRE(StringIsEqual(TestUpper, TestDiff) == false);
    }
  }
}

SCENARIO( "VerifyAnswer" ){

}