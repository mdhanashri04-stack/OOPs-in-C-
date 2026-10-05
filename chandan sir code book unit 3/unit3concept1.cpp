#include <iostream>
#include <string>

using namespace std;

// Function with two integer parameters
int add(int first, int second) {
    return first + second;
}

// Function with two double parameters
double add(double first, double second) {
    return first + second;
}

// Function with three integer parameters
int add(int first, int second, int third) {
    return first + second + third;
}

// Modified feature: Function to join two strings
string add(string first, string second) {
    return first + " " + second;
}

int main() {

    cout << "Sum of two integers: " << add(10, 20) << endl;

    cout << "Sum of two doubles: " << add(2.5, 3.7) << endl;

    cout << "Sum of three integers: " << add(10, 20, 30) << endl;

    cout << "Joined string: " << add("Dhanashri", "More") << endl;

    return 0;
}