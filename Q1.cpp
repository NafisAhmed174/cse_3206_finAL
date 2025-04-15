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


class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return M_PI * radius * radius;
    }
};

class Square : public Shape {
    double side;
public:
    Square(double s) : side(s) {}
    double area() const override {
        return side * side;
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
};


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


//   git config --global user.email "you@example.com"
//   git config --global user.name "Your Name"