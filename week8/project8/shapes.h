#pragma once

#include <string>
#include <cmath>
#include <numbers>

class Shape {

    public:
        virtual float area() = 0;
        virtual float circumference() = 0;
        virtual std::string name() = 0;
        virtual ~Shape() = default;
};

class Circle : public Shape {

    float r;

    public:
        
        Circle(float r) : r(r) {};

        float area() override {return std::numbers::pi * r * r;}
        float circumference() override {return 2 * (std::numbers::pi * r);}
        std::string name() override {return "Circle";}

};

class Rectangle : public Shape {

    float w;
    float h;

    public:
        
        Rectangle(float w, float h) : w(w), h(h){};

        float area() override {return w * h;}
        float circumference() override {return 2 * (w + h);}
        std::string name() override {return "Rectangle";}

};

class RegPolygon : public Shape {

    int sides;
    float l;

    public:
        
        RegPolygon(int sides, float l) : sides(sides), l(l){};

        float area() override {return (sides * std::pow(l, 2)) / (4 * std::tan(std::numbers::pi / sides));}
        float circumference() override {return sides * l;}
        std::string name() override {return "Regular Polygon";}

};

class RightTriangle : public Shape {

    float base;
    float height;

    public:
        
        RightTriangle(float base, float height) : base(base), height(height){};

        float area() override {return (base * height) / 2;}
        float circumference() override {return base + height + (std::sqrt((base * base) + (height * height)));}
        std::string name() override {return "Right Triangle";}

};

class Square : public Shape {

    float l;

    public:
        
        Square(float l) : l(l) {};

        float area() override {return (l * l);}
        float circumference() override {return l * 4;}
        std::string name() override {return "Square";}

};
