#include<iostream>
using namespace std;
#include <gtest/gtest.h>

/*
clang++ -std=c++17 -I /opt/homebrew/Cellar/googletest/1.16.0/include \
    -L /opt/homebrew/Cellar/googletest/1.16.0/lib \
    -lgtest -lgtest_main -pthread banking.cpp -o banking
*/

/*
g++ -std=c++17 test.cpp \
-I/opt/homebrew/opt/googletest/include \
-L/opt/homebrew/opt/googletest/lib \
-lgtest -lgtest_main -pthread \
-o test && ./test
*/

class shape{
    double area() = 0;
};


class shapeFactory(){
    
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


