#include <iostream>
#include <exception>
using namespace std;

class Overflow : public exception {
public:
    const char* what() const noexcept override {
        return "Stack Overflow!";
    }
};

class Underflow : public exception {
public:
    const char* what() const noexcept override {
        return "Stack Underflow!";
    }
};

class Stack {
private:
    int arr[3];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top == 2) {
            throw Overflow();
        }

        arr[++top] = value;
        cout << value << " pushed into stack." << endl;
    }

    int pop() {
        if (top == -1) {
            throw Underflow();
        }

        return arr[top--];
    }
};

int main() {
    Stack s;

    try {
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
    }
    catch (const Overflow& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        cout << "Popped: " << s.pop() << endl;
        cout << "Popped: " << s.pop() << endl;
        cout << "Popped: " << s.pop() << endl;
        cout << "Popped: " << s.pop() << endl;
    }
    catch (const Underflow& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}