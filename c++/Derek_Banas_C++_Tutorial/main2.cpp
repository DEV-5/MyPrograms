#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <sstream>
#include <numeric>
#include <ctime>
#include <cmath>

//#include "classes_shapes.hpp"
//#include "classes_circle.hpp"
class Shape {
public:
    virtual double Area()=0;
};

class Circle: public Shape{
protected:
    double width;
public:
    Circle(double w){
        width = w;
    }
    double Area() override{
        return 3.14159 * pow((width/2),2);
    }
};

using namespace std;

void ShowArea(Shape& shape); 

int main(int argc, char** argv) {
    // Shape square(10, 5); /* cannot decalre variable 'square' to be of abstract type 'Shape'
    Circle circle(10);

    ShowArea(circle);

    return 0;
}

void ShowArea(Shape& shape) {
    cout<< "Area : " << shape.Area() << endl;
}
