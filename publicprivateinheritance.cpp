// Include the input-output stream library
#include <iostream>

// Use the standard namespace
// This allows us to use cout directly instead of std::cout
using namespace std;

// Base class
class Base {
public:
    // Public function of the Base class
    void show() const {
        // Display a message
        cout << "Base public function\n";
    }
};

// Derived class using public inheritance
class PublicDerived : public Base {
    // The public members of Base remain public in PublicDerived
};

// Derived class using private inheritance
class PrivateDerived : private Base {
public:
    // Public function of PrivateDerived
    void callBaseShow() const {
        // Call the show() function inherited from Base
        show();
    }
};

// Main function
int main() {

    // Create an object of PublicDerived
    PublicDerived publicObject;

    // Access the public show() function directly
    publicObject.show();

    // Create an object of PrivateDerived
    PrivateDerived privateObject;

    // Access the Base class function through a public function
    privateObject.callBaseShow();

    // This line would give an error because
    // show() becomes private due to private inheritance
    // privateObject.show();

    // End the program successfully
    return 0;
}