#ifndef TEST_MAIN_H
#define TEST_MAIN_H

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

SCENARIO( "string methods should return appropriate strings") {
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

#endif