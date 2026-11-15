#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int marks;
};

int main() {
    ifstream file("students.txt");

    if (!file) {
        cout << "file not found!";
        return 1;
    }

    Student s[100];
    int count = 0;

    while (count < 100 &&
           file >> s[count].name >> s[count].marks) {
        count++;
    }

    file.close();

    if (count == 0) {
        cout << "No student records found.";
        return 0;
    }

    int topper = 0;

    for (int i = 1; i < count; i++) {
        if (s[i].marks > s[topper].marks) {
            topper = i;
        }
    }

    cout << "Topper Details" << endl;
    cout << "Name: " << s[topper].name << endl;
    cout << "Marks: " << s[topper].marks << endl;

    return 0;
}
