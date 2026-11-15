#include <iostream>
#include <memory>
using namespace std;

class Student {
public:
    void display() {
        cout << "Student object created successfully!" << endl;
    }
};

int main() {
    unique_ptr<Student> s = make_unique<Student>();

    s->display();

    cout << "Memory is managed automatically." << endl;

    return 0;
}
