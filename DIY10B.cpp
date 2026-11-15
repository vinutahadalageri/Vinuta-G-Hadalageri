#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFile("in.txt");
    ofstream outFile("out.txt");

    if (!inFile || !outFile) {
        cout << "Error opening file!";
        return 1;
    }

    string line;
    int lineNumber = 1;

    while (getline(inFile, line)) {
        outFile << lineNumber << ": " << line << endl;
        lineNumber++;
    }

    inFile.close();
    outFile.close();

    cout << "File copied successfully.";
    return 0;
}
