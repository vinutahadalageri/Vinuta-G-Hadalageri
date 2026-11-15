#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class SafeArray {
    vector<int> arr;

public:
    SafeArray(int size) : arr(size) {}

    int& operator[](int index) {
        if (index < 0 || index >= (int)arr.size()) {
            throw out_of_range("Array index out of range!");
        }
        return arr[index];
    }

    int size() {
        return arr.size();
    }
};

int main() {
    int n;

    cout << "Enter array size: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size!" << endl;
        return 0;
    }

    SafeArray a(n);

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    try {
        int index;
        cout << "Enter index to access: ";
        cin >> index;

        cout << "Element: " << a[index] << endl;
    }
    catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}