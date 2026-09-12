#include <iostream>
using namespace std;

class Student {
public:
    // Declare a static variable shared by all objects
    static int count;

    // Constructor
    Student() {
        // Increase count whenever an object is created
        count++;
    }
};

// Define and initialize the static variable
int Student::count = 0;

int main() {
    // Create three Student objects
    Student s1, s2, s3;

    // Display the total number of objects created
    cout << Student::count;

    return 0;
}