//DIY11

//Stack with destructor

#include <iostream>
using namespace std;

class Stack {
private:
    int *arr;
    int size;
    int top;

public:
    Stack(int s) {
        size = s;
        top = -1;
        arr = new int[size];
    }

    void push(int value) {
        if (top == size - 1) {
            cout << "Stack Overflow" << endl;
        } else {
            arr[++top] = value;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
        } else {
            cout << "Popped: " << arr[top--] << endl;
        }
    }

    ~Stack() {
        delete[] arr;
        cout << "Memory released" << endl;
    }
};

int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    s.pop();
    s.pop();

    return 0;
}