#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <sstream>
#include <numeric>
#include <ctime>
#include <cmath>

#include "classes_shapes.hpp"
#include "classes_circle.hpp"

using namespace std;

void ShowArea(Shape& shape); 

int main(int argc, char** argv) {
    Shape square(10, 5);
    Circle circle(10);

    ShowArea(square);
    ShowArea(circle);

    return 0;
}

void ShowArea(Shape& shape) {
    cout<< "Area : " << shape.Area() << endl;
}
