#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};

    int product = accumulate(
        v.begin(), v.end(), 1,
        [](int a, int b) {
            return a * b;
        }
    );

    int evenSum = accumulate(
        v.begin(), v.end(), 0,
        [](int sum, int x) {
            return sum + (x % 2 == 0 ? x : 0);
        }
    );

    cout << "Product = " << product << endl;
    cout << "Sum of even numbers = " << evenSum << endl;

    return 0;
}
