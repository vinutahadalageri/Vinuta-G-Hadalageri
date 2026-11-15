#include <iostream>
#include <numeric>
using namespace std;

class Fraction {
    int num, den;

    void simplify() {
        if (den < 0) {
            num = -num;
            den = -den;
        }

        int g = gcd(num, den);
        if (g != 0) {
            num /= g;
            den /= g;
        }
    }

public:
    Fraction(int n = 0, int d = 1) {
        num = n;
        den = (d == 0) ? 1 : d;
        simplify();
    }

    friend istream& operator>>(istream& in, Fraction& f) {
        in >> f.num >> f.den;
        if (f.den == 0) {
            cout << "Invalid denominator!" << endl;
            f.num = 0;
            f.den = 1;
        }
        f.simplify();
        return in;
    }

    friend ostream& operator<<(ostream& out,
                               const Fraction& f) {
        out << f.num << "/" << f.den;
        return out;
    }
};

int main() {
    Fraction f;

    cout << "Enter numerator and denominator: ";
    cin >> f;

    cout << "Simplified fraction: " << f << endl;

    return 0;
}