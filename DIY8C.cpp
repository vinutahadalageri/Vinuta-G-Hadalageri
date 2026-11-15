#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {
        cout << "Base destructor called\n";
    }
};

class Derived : public Base {
private:
    int* data;

public:
    Derived() {
        data = new int[100];
        cout << "Memory allocated in Derived\n";
    }

    ~Derived() override {
        delete[] data;
        cout << "Derived destructor called\n";
    }
};

int main() {
    cout << "Virtual Destructor Demonstration\n\n";

    cout << "Creating Derived object using Base pointer:\n";

    Base* ptr = new Derived();

    cout << "\nDeleting object:\n";
    delete ptr;

    cout << "\nMemory released successfully!\n";

    return 0;
}