#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
    string name;

public:
    Employee(string n) {
        name = n;
    }
};

class Developer : public Employee {
private:
    string language;

public:
    Developer(string n, string lang) : Employee(n) {
        language = lang;
    }

    void display() {
        cout << "Developer: " << name << endl;
        cout << "Language: " << language << endl;
    }
};

int main() {
    Developer d("Neha", "C++");
    d.display();

    return 0;
}