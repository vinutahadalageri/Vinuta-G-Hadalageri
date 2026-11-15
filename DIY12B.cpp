#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, x;
    priority_queue<int> pq;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        pq.push(x);
    }

    cout << "Largest numbers: ";
    for (int i = 0; i < 3 && !pq.empty(); i++) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
