#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;

public:
    Person(string n) : name(n) {
        cout << "Person constructor called" << endl;
    }

    void displayPerson() {
        cout << "Name: " << name << endl;
    }
};

class Student : virtual public Person {
protected:
    int rollNo;

public:
    Student(string n, int r)
        : Person(n), rollNo(r) {
        cout << "Student constructor called" << endl;
    }
};

class Employee : virtual public Person {
protected:
    int employeeId;

public:
    Employee(string n, int id)
        : Person(n), employeeId(id) {
        cout << "Employee constructor called" << endl;
    }
};

class TA : public Student, public Employee {
private:
    string subject;

public:
    TA(string n, int r, int id, string s)
        : Person(n), Student(n, r),
          Employee(n, id), subject(s) {
        cout << "TA constructor called" << endl;
    }

    void displayDetails() {
        cout << "\n--- Teaching Assistant Details ---" << endl;
        displayPerson();
        cout << "Roll Number: " << rollNo << endl;
        cout << "Employee ID: " << employeeId << endl;
        cout << "Subject: " << subject << endl;
    }
};

int main() {
    TA ta("Iniya", 25, 501, "Digital Electronics");

    ta.displayDetails();

    return 0;
}