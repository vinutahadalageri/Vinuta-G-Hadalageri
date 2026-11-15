#include <iostream>
#include <fstream>
#include <memory>
#include <string>
using namespace std;

class Logger {
public:
    virtual void write(string message) = 0;

    virtual ~Logger() {}
};

class ConsoleLogger : public Logger {
public:
    void write(string message) override {
        cout << "Console: " << message << endl;
    }
};

class FileLogger : public Logger {
public:
    void write(string message) override {
        ofstream file("log.txt", ios::app);

        if (file.is_open()) {
            file << message << endl;
            file.close();
            cout << "Message written to log.txt" << endl;
        } else {
            cout << "Unable to open file!" << endl;
        }
    }
};

int main() {
    int choice;

    cout << "Choose Logger:\n";
    cout << "1. Console Logger\n";
    cout << "2. File Logger\n";
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore();

    unique_ptr<Logger> logger;

    if (choice == 1) {
        logger = make_unique<ConsoleLogger>();
    } else if (choice == 2) {
        logger = make_unique<FileLogger>();
    } else {
        cout << "Invalid choice!" << endl;
        return 0;
    }

    string message;
    cout << "Enter message: ";
    getline(cin, message);

    logger->write(message);

    return 0;
}