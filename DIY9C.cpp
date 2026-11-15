#include <iostream>
#include <exception>
using namespace std;

class MathError : public exception {
public:
    const char* what() const noexcept override {
        return "Math Error!";
    }
};

class DivideByZero : public MathError {
public:
    const char* what() const noexcept override {
        return "Division by zero!";
    }
};

int main() {
    cout << "Incorrect catch order:" << endl;

    try {
        throw DivideByZero();
    }
    catch (const MathError& e) {
        cout << e.what() << endl;
    }
    catch (const DivideByZero& e) {
        cout << e.what() << endl;
    }

    cout << "\nCorrect catch order:" << endl;

    try {
        throw DivideByZero();
    }
    catch (const DivideByZero& e) {
        cout << e.what() << endl;
    }
    catch (const MathError& e) {
        cout << e.what() << endl;
    }

    return 0;
}