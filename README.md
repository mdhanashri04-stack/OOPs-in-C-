# Object-Oriented Programming with C++

## Student Information

- **Student Name:** Dhanashri More
- **PRN:** 125UAD1045
- **Class/Division:** S.Y. B.Tech. AI & DS – Division D
- **Course Name:** Object-Oriented Programming with C++
- **Course Code:** ADPC303
- **Programme:** S.Y. B.Tech. Artificial Intelligence and Data Science
- **Language Standard:** C++17 or later

---

## Repository Structure

This repository contains practical programs for Object-Oriented Programming with C++.

- **Unit I** – Basic C++ and Object-Oriented Programming Programs
- **Unit II** – Inheritance

### Folders

- [Unit I – OOP Programs](./chandan%20sir%20code%20book%20unit%201/)
- [Unit II – Inheritance](./chandan%20sir%20code%20book%20unit%202/)

---

# Unit I – OOP Programs

The Unit I folder contains the basic C++ and Object-Oriented Programming practical programs.

### Programs

1. **Basic Data Types**  
   Demonstrates basic C++ data types such as integer, character, and floating-point values.

2. **Class and Object**  
   Demonstrates the declaration of a class, creation of an object, data members, and member functions.

3. **Constructor and Destructor**  
   Demonstrates constructors and destructors and their execution during object creation and destruction.

4. **Function Overloading**  
   Demonstrates the use of multiple functions with the same name but different parameters.

5. **If-Else**  
   Demonstrates conditional statements using `if` and `else`.

6. **Loop and Array**  
   Demonstrates arrays and iteration using loops.

7. **Static Data Member**  
   Demonstrates the use of a static data member shared among class objects.

8. **Scientific Calculator**  
   Demonstrates a C++ based calculator program with multiple mathematical operations.

---

# Unit II – Inheritance

Unit II focuses on inheritance and related Object-Oriented Programming concepts. The practical code book covers inheritance, access control, constructors and destructors, function overriding, abstract classes, virtual inheritance, friend classes, nested classes, and inheritance-based mini-projects. :contentReference[oaicite:2]{index=2}

## List of Programs

### 1. Basic Single Inheritance

Demonstrates single inheritance using a `Person` base class and a `Student` derived class.

### 2. Protected Member Access

Demonstrates how a derived class can access a protected member of its base class.

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

Demonstrates the use of the scope-resolution operator to resolve ambiguity when two base classes contain functions with the same name.

### 8. Constructor and Destructor Order

Demonstrates the order in which constructors and destructors execute in inheritance.

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

Demonstrates an inheritance-based vehicle rental application using vehicles such as cars and bikes, including rental calculation and function overriding.

### 16. Mini-Project – Employee Payroll System

Demonstrates an employee payroll system using an abstract base class, derived classes, function overriding, and polymorphism.

The 16 concepts above correspond to the sequence given in the Unit II practical code book. :contentReference[oaicite:3]{index=3}

---

# Concepts Covered

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

# Compilation and Execution

The programs use **C++17 or later**. :contentReference[oaicite:4]{index=4}

## Windows – MinGW

```bash
g++ -std=c++17 filename.cpp -o program.exe
program.exe
