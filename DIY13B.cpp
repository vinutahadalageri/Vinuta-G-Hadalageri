#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

class Shape {
public:
    virtual void display() = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    void display() override {
        cout << "Circle created." << endl;
    }
};

class Rectangle : public Shape {
public:
    void display() override {
        cout << "Rectangle created." << endl;
    }
};

class Triangle : public Shape {
public:
    void display() override {
        cout << "Triangle created." << endl;
    }
};

int main() {
    vector<unique_ptr<Shape>> shapes;
    string name;
    int n;

    cout << "How many shapes do you want to create? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter shape name (Circle, Rectangle, Triangle): ";
        cin >> name;

        if (name == "Circle" || name == "circle") {
            shapes.push_back(make_unique<Circle>());
        }
        else if (name == "Rectangle" || name == "rectangle") {
            shapes.push_back(make_unique<Rectangle>());
        }
        else if (name == "Triangle" || name == "triangle") {
            shapes.push_back(make_unique<Triangle>());
        }
        else {
            cout << "Invalid shape name!" << endl;
            continue;
        }

        shapes.back()->display();
    }

    cout << "Total shapes created: " << shapes.size() << endl;

    return 0;
}
