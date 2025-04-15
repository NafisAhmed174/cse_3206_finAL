#include<bits/stdc++.h>
using namespace std;
// #include <gtest/gtest.h>

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

class ShapeFactory {
    public:
        static unique_ptr<Shape> createShape(const std::string& shapeType, double a, double b = 0) {
            if (shapeType == "circle") {
                return std::make_unique<Circle>(a);
            } else if (shapeType == "square") {
                return std::make_unique<Square>(a);
            } else if (shapeType == "rectangle") {
                return std::make_unique<Rectangle>(a, b);
            } else {
                throw std::invalid_argument("Unknown shape type");
            }
        }
};


int main(int argc, char **argv){
    auto c = ShapeFactory::createShape("circle", 3);
    auto s = ShapeFactory::createShape("square", 4);
    auto r = ShapeFactory::createShape("rectangle", 3, 5);

    std::cout << "Circle Area: " << c->area() << "\n";
    std::cout << "Square Area: " << s->area() << "\n";
    std::cout << "Rectangle Area: " << r->area() << "\n";
    return 0;
}