#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int total = 0;
mutex mtx;

void increment() {
    for (int i = 0; i < 100000; i++) {
        lock_guard<mutex> lock(mtx);
        total++;
    }
}

int main() {
    thread t1(increment);
    thread t2(increment);

    t1.join();
    t2.join();

    cout << "Final total: " << total << endl;

    return 0;
}
