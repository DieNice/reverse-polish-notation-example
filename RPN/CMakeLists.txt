cmake_minimum_required(VERSION 3.14)
project(RPN)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(libs/googletest)

include_directories(libs/googletest/googletest/include)

include_directories(src)

add_executable(RPN main.cpp src/AbstractOperation.cpp src/AbstractOperation.h src/Checker.cpp src/Checker.h src/BuildReversePolishNotation.cpp src/BuildReversePolishNotation.h src/Calculator.cpp src/Calculator.h src/CollectionOperations.cpp src/CollectionOperations.h src/Plus.cpp src/Plus.h src/Minus.cpp src/Minus.h src/Multiplication.cpp src/Multiplication.h src/Division.cpp src/Division.h src/DtoRpn.cpp src/DtoRpn.h)

add_executable(MySTests test.cpp src/AbstractOperation.cpp src/AbstractOperation.h src/Checker.cpp src/Checker.h src/BuildReversePolishNotation.cpp src/BuildReversePolishNotation.h src/Calculator.cpp src/Calculator.h src/CollectionOperations.cpp src/CollectionOperations.h src/Plus.cpp src/Plus.h src/Minus.cpp src/Minus.h src/Multiplication.cpp src/Multiplication.h src/Division.cpp src/Division.h src/DtoRpn.cpp src/DtoRpn.h)

target_link_libraries(MySTests gtest gtest_main)