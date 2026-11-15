#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
    string color;

public:
    Shape(string c) : color(c) {
        cout << "Shape constructor called" << endl;
    }
};

class Polygon : public Shape {
protected:
    int sides;

public:
    Polygon(string c, int s) : Shape(c), sides(s) {
        cout << "Polygon constructor called" << endl;
    }
};

class Rectangle : public Polygon {
private:
    double length;
    double breadth;

public:
    Rectangle(string c, int s, double l, double b)
        : Polygon(c, s), length(l), breadth(b) {
        cout << "Rectangle constructor called" << endl;
    }

    void display() {
        cout << "\n--- Rectangle Details ---" << endl;
        cout << "Color: " << color << endl;
        cout << "Number of sides: " << sides << endl;
        cout << "Length: " << length << endl;
        cout << "Breadth: " << breadth << endl;
        cout << "Area: " << length * breadth << endl;
    }
};

int main() {
    Rectangle r("Blue", 4, 10, 5);
    r.display();

    return 0;
}