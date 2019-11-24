#include <string>
#include "catch.hpp"

using namespace std;

#include "../utils/string.h"

SCENARIO( "string methods should return appropriate strings") {
  string TestString = "Hello, world!";
  string TestStringUpper = "HELLO, WORLD!";
  string TestStringLower = "hello, world!";
  string TestNumbers = "1239123";
  string TestStringArabic = "أهلاً و سهلاً";

  GIVEN( "A string" ) {
    WHEN("calling StringToUpperCase/StringToLowerCase with English characters"){
      THEN("should return string all in uppercase/lowercase"){
        CHECK(StringToUpperCase(TestString) == TestStringUpper);
        CHECK(StringToLowerCase(TestString) == TestStringLower);
      }
    }

    WHEN("calling StringToUpperCase/StringToLowerCase with Arabic characters"){
      THEN("should return the same string"){
        CHECK(StringToUpperCase(TestStringArabic) == TestStringArabic);
      }
    }

    WHEN("calling StringToUpperCase/StringToLowerCase with numeral characters"){
      THEN("should return the same string"){
        CHECK(StringToUpperCase(TestNumbers) == TestNumbers);
      }
    }

    WHEN("calling StringToUpperCase/StringToLowerCase with special characters"){
      THEN("should return the same string"){
        CHECK(StringToUpperCase("!@#!@#") != "!@#!@#!");
      }
    }

    WHEN("calling StringToUpperCase/StringToLowerCase with special characters"){
      THEN("should return the same string"){
        CHECK(StringToUpperCase("!@#!@#") != "!@#!@#!");
      }
    }
  }
}
