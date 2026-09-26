#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Employee {
protected:
    int employeeId;
    string name;

public:
    Employee(int id, string employeeName)
        : employeeId(id), name(move(employeeName)) {}

    virtual double calculateSalary() const = 0;

    void displayBasicDetails() const {
        cout << "Employee ID: " << employeeId << '\n';
        cout << "Name: " << name << '\n';
    }

    virtual ~Employee() = default;
};

class PermanentEmployee : public Employee {
private:
    double basicSalary;
    double allowance;
    double bonus;                 // Modified feature

public:
    PermanentEmployee(int id, string employeeName, double basic,
                      double extra, double employeeBonus)
        : Employee(id, move(employeeName)),
          basicSalary(basic),
          allowance(extra),
          bonus(employeeBonus) {}

    double calculateSalary() const override {
        return basicSalary + allowance + bonus;   // Bonus added
    }
};

class ContractEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    ContractEmployee(int id, string employeeName, double rate, int hours)
        : Employee(id, move(employeeName)),
          hourlyRate(rate),
          hoursWorked(hours) {}

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }
};

void displayPaySlip(const Employee& employee) {
    employee.displayBasicDetails();
    cout << "Salary: " << employee.calculateSalary() << "\n\n";
}

int main() {
    PermanentEmployee permanentEmployee(
        101, "Neha", 40000.0, 8000.0, 5000.0
    );

    ContractEmployee contractEmployee(
        102, "Bhavik", 500.0, 80
    );

    displayPaySlip(permanentEmployee);
    displayPaySlip(contractEmployee);

    return 0;
}