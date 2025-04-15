#include<iostream>
#include <gtest/gtest.h>
using namespace std;

/*
g++ -std=c++17 Q1.cpp \
-I/opt/homebrew/opt/googletest/include \
-L/opt/homebrew/opt/googletest/lib \
-lgtest -lgtest_main -pthread \
-o Q1 && ./Q1
*/

class Shape{
public:
    virtual double area() const = 0;
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

class ShapeCreator {
    public:
        virtual Shape* create(double a, double b = 0) = 0;
        virtual ~ShapeCreator() {}
};
    
class CircleCreator : public ShapeCreator {
    public:
        Shape* create(double a, double b = 0) override {
            return new Circle(a);
        }
};
    
class SquareCreator : public ShapeCreator {
    public:
        Shape* create(double a, double b = 0) override {
            return new Square(a);
        }
};
    
class RectangleCreator : public ShapeCreator {
    public:
        Shape* create(double a, double b = 0) override {
            return new Rectangle(a, b);
        }
};

TEST(ShapeTest, CircleArea) {
    CircleCreator creator;
    Shape* circle = creator.create(3);
    EXPECT_NEAR(circle->area(), M_PI * 9, 1e-6);
}

TEST(ShapeTest, SquareArea) {
    SquareCreator creator;
    Shape* square = creator.create(4);
    EXPECT_DOUBLE_EQ(square->area(), 16);
}

TEST(ShapeTest, RectangleArea) {
    RectangleCreator creator;
    Shape* rect = creator.create(3, 5);
    EXPECT_DOUBLE_EQ(rect->area(), 15);
}

int main(int argc, char **argv){
    // auto c = ShapeFactory::createShape("circle", 3);
    // auto s = ShapeFactory::createShape("square", 4);
    // auto r = ShapeFactory::createShape("rectangle", 3, 5);

    // std::cout << "Circle Area: " << c->area() << "\n";
    // std::cout << "Square Area: " << s->area() << "\n";
    // std::cout << "Rectangle Area: " << r->area() << "\n";
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}