/* command: 
clang++ -std=c++17 -I /opt/homebrew/Cellar/googletest/1.16.0/include \
    -L /opt/homebrew/Cellar/googletest/1.16.0/lib \
    -lgtest -lgtest_main -pthread test.cpp -o test
*/

/*
g++ -std=c++17 test.cpp \
-I/opt/homebrew/opt/googletest/include \
-L/opt/homebrew/opt/googletest/lib \
-lgtest -lgtest_main -pthread \
-o test && ./test
*/


#include<iostream>
using namespace std;
#include <gtest/gtest.h>

// Function Definitions
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

// testing

// addition test
TEST(AdditionTest, HandlesPositiveNumbers) {
    EXPECT_EQ(add(30, 50), 80);
}
TEST(AdditionTest, HandlesPositiveAndNegative) {
    EXPECT_EQ(add(50, -20), 30);
}
TEST(AdditionTest, HandlesPositiveAndZero) {
    EXPECT_EQ(add(70, 0), 70);
}

// subtraction test
TEST(SubtractionTest, HandlesPositiveNumbers) {
    EXPECT_EQ(subtract(100, 40), 60);
}
TEST(SubtractionTest, HandlesPositiveAndNegative) {
    EXPECT_EQ(subtract(60, -30), 90);
}
TEST(SubtractionTest, HandlesPositiveAndZero) {
    EXPECT_EQ(subtract(90, 0), 90);
}

// multiplication test
TEST(MultiplicationTest, HandlesPositiveNumbers) {
    EXPECT_EQ(multiply(5, 3), 15);
}
TEST(MultiplicationTest, HandlesPositiveAndNegative) {
    EXPECT_EQ(multiply(9, -2), -18);
}
TEST(MultiplicationTest, HandlesPositiveAndZero) {
    EXPECT_EQ(multiply(10, 0), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}