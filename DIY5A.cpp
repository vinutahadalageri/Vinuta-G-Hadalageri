//DIY13
//Object counter

#include <iostream>
using namespace std;

class Counter {
private:
    static int totalCreated;
    static int alive;

public:
    Counter() {
        totalCreated++;
        alive++;
    }

    ~Counter() {
        alive--;
    }

    static void showCount() {
        cout << "Total created = " << totalCreated << endl;
        cout << "Currently alive = " << alive << endl;
    }
};

int Counter::totalCreated = 0;
int Counter::alive = 0;

int main() {

    Counter::showCount();

    Counter c1;
    Counter c2;

    Counter::showCount();

    {
        Counter c3;
        Counter c4;

        Counter::showCount();
    }

    Counter::showCount();

    return 0;
}