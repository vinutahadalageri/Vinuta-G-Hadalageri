#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    double balance;

public:
    Account(double b) : balance(b) {}

    virtual double calculateInterest() = 0;

    virtual ~Account() {}

    void displayInterest() {
        cout << "Balance: " << balance << endl;
        cout << "Interest: " << calculateInterest() << endl;
    }
};

class Savings : public Account {
public:
    Savings(double b) : Account(b) {}

    double calculateInterest() override {
        return balance * 0.05;  // 5% interest
    }
};

class Current : public Account {
public:
    Current(double b) : Account(b) {}

    double calculateInterest() override {
        return balance * 0.02;  // 2% interest
    }
};

int main() {
    Savings s(10000);
    Current c(20000);

    Account* accounts[2] = {&s, &c};

    for (int i = 0; i < 2; i++) {
        accounts[i]->displayInterest();
        cout << "----------------\n";
    }

    return 0;
}