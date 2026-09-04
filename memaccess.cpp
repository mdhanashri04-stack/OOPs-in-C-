// Include the input-output stream library
#include <iostream>

// Include the string library for using string data type
#include <string>

// Use the standard namespace so we don't need to write std::
using namespace std;

// Base class
class Employee {
protected:
    // Store the employee's name
    string name;

public:
    // Constructor of Employee class
    Employee(string n) {
        // Assign the given name to the name variable
        name = n;
    }
};

// Derived class inheriting from Employee
class Developer : public Employee {
private:
    // Store the programming language
    string language;

public:
    // Constructor of Developer class
    Developer(string n, string lang) : Employee(n) {
        // Assign the programming language
        language = lang;
    }

    // Function to display developer details
    void display() {
        // Display the developer's name
        cout << "Developer: " << name << endl;

        // Display the programming language
        cout << "Language: " << language << endl;
    }
};

// Main function
int main() {

    // Create an object of Developer class
    Developer d("Neha", "C++");

    // Call the display function
    d.display();

    // End the program successfully
    return 0;
}