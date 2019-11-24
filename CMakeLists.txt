cmake_minimum_required(VERSION 3.14)
project(quiz_taking_app)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(structures)
include_directories(utils)

add_executable(quiz_taking_app
        structures/index.h
        structures/log.h
        structures/question.h
        structures/quiz.h
        structures/user.h
        utils/file.h
        utils/index.h
        utils/io.h
        utils/misc.h
        utils/question.h
        utils/quiz.h
        utils/string.h
        utils/user.h
        globals.h
        indexer.h
        main.cpp
        menus.h)
