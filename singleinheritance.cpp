// Include the input-output stream library
#include <iostream>

// Include the string library for using string data type
#include <string>

// Use the standard namespace so we don't need to write std::
using namespace std;

// Base class
class Person {
protected:
    // Store the name of the person
    string name;

public:
    // Constructor of Person class
    Person(string n) {
        // Assign the given name to the name variable
        name = n;
    }

    // Function to display the name
    void displayName() {
        // Print the name on the screen
        cout << "Name: " << name << endl;
    }
};

// Derived class inheriting from Person
class Student : public Person {
private:
    // Store the student's roll number
    int rollNumber;

public:
    // Constructor of Student class
    Student(string n, int r) : Person(n) {
        // Assign the given roll number
        rollNumber = r;
    }

    // Function to display student details
    void displayStudent() {
        // Call the displayName() function of the base class
        displayName();

        // Display the student's roll number
        cout << "Roll Number: " << rollNumber << endl;
    }
};

// Main function
int main() {

    // Create an object of Student class
    Student student("Amit", 101);

    // Display the student's details
    student.displayStudent();

    // End the program successfully
    return 0;
}