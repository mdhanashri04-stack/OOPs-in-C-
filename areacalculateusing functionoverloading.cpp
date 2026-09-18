#include <iostream>
using namespace std;

// Function to calculate area of a square
int calculateArea(int side) {
    return side * side;
}

// Function to calculate area of a rectangle
int calculateArea(int length, int width) {
    return length * width;
}

// Function to calculate area of a circle
double calculateArea(double radius) {
    constexpr double PI = 3.141592653589793;
    return PI * radius * radius;
}

// Modified function: area of triangle
double calculateArea(double base, double height) {
    return 0.5 * base * height;
}

int main() {
    cout << "Square Area: " << calculateArea(5) << '\n';

    cout << "Rectangle Area: " << calculateArea(6, 4) << '\n';

    cout << "Circle Area: " << calculateArea(2.0) << '\n';

    cout << "Triangle Area: " << calculateArea(10.0, 5.0) << '\n';

    return 0;
}