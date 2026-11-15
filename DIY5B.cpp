//DIY14
//Friend comparison

#include <iostream>
using namespace std;

class Time {
private:
    int hh, mm;

public:
    Time(int h, int m) {
        hh = h;
        mm = m;
    }

    void display() {
        cout << hh << ":" << mm << endl;
    }

    friend Time laterOf(Time t1, Time t2);
};

Time laterOf(Time t1, Time t2) {

    if (t1.hh > t2.hh)
        return t1;

    if (t1.hh < t2.hh)
        return t2;

    if (t1.mm > t2.mm)
        return t1;

    return t2;
}

int main() {

    Time t1(10, 30);
    Time t2(12, 15);

    Time later = laterOf(t1, t2);

    cout << "Later time = ";
    later.display();

    return 0;
}