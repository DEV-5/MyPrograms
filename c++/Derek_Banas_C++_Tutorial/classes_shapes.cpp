#include "classes_shapes.hpp"

Shape::Shape(double length) {
    this->height = length;
    this->width = length;
}
Shape::Shape(double height, double width) {
    this->height = height;
    this->width = width;
}

Shape::~Shape() = default;

void Shape::SetHeight(double height) {
    //can add aditional height argument checks here
    this->height = height;
}

double Shape::GetWidth() { return width;}

int Shape::GetNumOfShapes() {return numOfShapes;}

double Shape::Area() {
    return height * width; 
}

int Shape::numOfShapes = 0;
