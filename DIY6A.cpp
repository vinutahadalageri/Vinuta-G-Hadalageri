#include <iostream>
using namespace std;

class Money {
    int rupees, paise;

public:
    Money(int r = 0, int p = 0) {
        int total = r * 100 + p;
        rupees = total / 100;
        paise = total % 100;
    }

    Money operator+(const Money& m) {
        return Money(rupees + m.rupees, paise + m.paise);
    }

    Money operator-(const Money& m) {
        return Money(rupees - m.rupees, paise - m.paise);
    }

    void display() {
        cout << "Rs. " << rupees << ".";
        if (paise < 10) cout << "0";
        cout << paise << endl;
    }
};

int main() {
    Money m1(10, 75), m2(5, 50);

    Money sum = m1 + m2;
    Money diff = m1 - m2;

    cout << "First amount: ";
    m1.display();

    cout << "Second amount: ";
    m2.display();

    cout << "Addition: ";
    sum.display();

    cout << "Subtraction: ";
    diff.display();

    return 0;
}
