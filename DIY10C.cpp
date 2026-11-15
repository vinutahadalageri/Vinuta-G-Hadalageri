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
    Student s[5];
    int n = 4;

    // Write student records into a file
    ofstream fout("students.txt");

    fout << "Arun 85\n";
    fout << "Priya 95\n";
    fout << "Ravi 78\n";
    fout << "Divya 90\n";

    fout.close();

    // Read records from the file
    ifstream fin("students.txt");

    if (!fin.is_open()) {
        cout << "Error opening file";
        return 1;
    }

    int i = 0;

    while (i < 5 && fin >> s[i].name >> s[i].marks) {
        i++;
    }

    fin.close();
    n = i;

    if (n == 0) {
        cout << "No records found";
        return 0;
    }

    // Find the topper
    int top = 0;

    for (int j = 1; j < n; j++) {
        if (s[j].marks > s[top].marks) {
            top = j;
        }
    }

    cout << "Topper Name: " << s[top].name << endl;
    cout << "Topper Marks: " << s[top].marks << endl;

    return 0;
}