#include <iostream>
#include <string>

using namespace std;

// Base class
class Person {
protected:
    string name;

public:
    Person(string personName) {
        name = personName;
    }

    void showPerson() {
        cout << "Name: " << name << endl;
    }
};

// Derived class
class Employee : public Person {
protected:
    int employeeId;

public:
    Employee(string employeeName, int id) : Person(employeeName) {
        employeeId = id;
    }

    void showEmployee() {
        cout << "Employee ID: " << employeeId << endl;
    }
};

// Derived class from Employee
class Manager : public Employee {
private:
    int teamSize;

public:
    Manager(string managerName, int id, int size)
        : Employee(managerName, id) {
        teamSize = size;
    }

    void showManager() {
        showPerson();
        showEmployee();
        cout << "Team Size: " << teamSize << endl;
    }
};

int main() {
    Manager manager("Ravi", 501, 8);

    manager.showManager();

    return 0;
}