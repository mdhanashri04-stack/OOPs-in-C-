#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    string name;
    int age;

    void show() {
        cout << name << " " << age << endl;
    }
};

int main() {
    Student s1;

    s1.name = "Glow";
    s1.age = 20;

    s1.show();

    return 0;
}