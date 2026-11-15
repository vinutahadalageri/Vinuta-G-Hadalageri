#include <iostream>
#include <exception>
using namespace std;

class InsufficientFunds : public exception {
public:
    const char* what() const noexcept override {
        return "Insufficient balance for withdrawal!";
    }
};

class BankAccount {
private:
    double balance;

public:
    BankAccount(double amount) {
        balance = amount;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientFunds();
        }

        balance -= amount;
        cout << "Withdrawal successful!" << endl;
        cout << "Remaining balance: " << balance << endl;
    }
};

int main() {
    BankAccount account(5000);

    try {
        account.withdraw(6000);
    }
    catch (const InsufficientFunds& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}