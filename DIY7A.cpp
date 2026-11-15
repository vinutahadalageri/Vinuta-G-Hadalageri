#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id;

public:
    Employee(string n, int i) {
        name = n;
        id = i;
    }

    void display() {
        cout << "Employee Name: " << name << endl;
        cout << "Employee ID: " << id << endl;
    }
};

class Manager : public Employee {
private:
    int teamSize;

public:
    Manager(string n, int i, int t)
        : Employee(n, i) {
        teamSize = t;
    }

    void displayDetails() {
        cout << "\n--- Manager Details ---" << endl;
        display();
        cout << "Team Size: " << teamSize << endl;
    }
};

class Engineer : public Employee {
private:
    string skill;

public:
    Engineer(string n, int i, string s)
        : Employee(n, i) {
        skill = s;
    }

    void displayDetails() {
        cout << "\n--- Engineer Details ---" << endl;
        display();
        cout << "Skill: " << skill << endl;
    }
};

int main() {
    Manager m("Arun", 101, 8);
    Engineer e("Priya", 102, "Verilog");

    m.displayDetails();
    e.displayDetails();

    return 0;
}