#include <iostream>

using namespace std;

// Area of square
int calculateArea(int side) {
    return side * side;
}

// Area of rectangle
int calculateArea(int length, int width) {
    return length * width;
}

// Area of circle
double calculateArea(double radius) {
    const double PI = 3.141592653589793;
    return PI * radius * radius;
}

// Modified feature: Area of triangle
double calculateArea(double base, double height) {
    return 0.5 * base * height;
}

int main() {

    cout << "Square Area: " << calculateArea(5) << endl;

    cout << "Rectangle Area: " << calculateArea(6, 4) << endl;

    cout << "Circle Area: " << calculateArea(2.0) << endl;

    cout << "Triangle Area: " << calculateArea(8.0, 5.0) << endl;

    return 0;
}