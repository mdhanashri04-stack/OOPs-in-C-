# Object-Oriented Programming with C++

## Student Information

- Student Name: Dhanashri More
- PRN: 125Uad1045
- Class/Division: S.Y. B.Tech. AI & DS – Division D
- Course Name: Object-Oriented Programming with C++
- Course Code:ADPC303
- Unit: Unit II – Inheritance
- Language Standard: C++17 or later

---

## Unit II – Inheritance

This repository contains the practical programs for **Unit II: Inheritance** in Object-Oriented Programming with C++. The programs demonstrate different inheritance concepts, accessibility, constructors and destructors, polymorphism, abstract classes, virtual inheritance, friend classes, nested classes, and inheritance-based mini-projects.

---

## List of Programs

### 1. Basic Single Inheritance
Demonstrates basic inheritance using a `Person` base class and a `Student` derived class.

### 2. Protected Member Access
Demonstrates how a derived class can access a protected member of the base class.

### 3. Public vs Private Inheritance
Demonstrates the effect of public and private inheritance on member accessibility.

### 4. Multilevel Inheritance
Demonstrates a three-level inheritance hierarchy:
`Person → Employee → Manager`

### 5. Hierarchical Inheritance
Demonstrates multiple derived classes, `Car` and `Bike`, inheriting from a common `Vehicle` base class.

### 6. Multiple Inheritance
Demonstrates multiple inheritance using two base classes:
`Academic` and `Sports`

### 7. Multiple-Inheritance Ambiguity
Demonstrates how the scope-resolution operator is used to resolve ambiguity when two base classes have functions with the same name.

### 8. Constructor and Destructor Order
Demonstrates the order of execution of constructors and destructors in inheritance.

### 9. Parameterized Base Constructor
Demonstrates how a derived-class constructor initializes a parameterized base class.

### 10. Function Overriding
Demonstrates function overriding using `virtual` and `override` with `Vehicle`, `Car`, and `Boat`.

### 11. Abstract Class
Demonstrates an abstract base class using a pure virtual function with `Shape`, `Rectangle`, and `Circle`.

### 12. Virtual Base Class and Diamond Inheritance
Demonstrates virtual inheritance to solve duplicate-base ambiguity in diamond inheritance.

### 13. Friend Class
Demonstrates how a friend class can access private data of another class.

### 14. Nested Class
Demonstrates the declaration and use of a class inside another class.

### 15. Mini-Project – Vehicle Rental System
Demonstrates an inheritance-based vehicle rental system using vehicles such as cars and bikes, including rental calculation and function overriding.

### 16. Mini-Project – Employee Payroll System
Demonstrates an employee payroll system using an abstract base class, derived classes, function overriding, and polymorphism.

---

## Concepts Covered

- Single Inheritance
- Protected Members
- Public and Private Inheritance
- Multilevel Inheritance
- Hierarchical Inheritance
- Multiple Inheritance
- Multiple-Inheritance Ambiguity
- Constructor and Destructor Order
- Parameterized Base Constructors
- Function Overriding
- Abstract Classes
- Virtual Base Classes
- Diamond Inheritance
- Friend Classes
- Nested Classes
- Polymorphism
- Constructors and Destructors

---

## Compilation

The programs are written using **C++17 or later**.

### Windows (MinGW)

```bash
g++ -std=c++17 filename.cpp -o program.exe
program.exe
