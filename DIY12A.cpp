#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    vector<pair<string, int>> v = {
        {"Apple", 30},
        {"Mango", 10},
        {"Orange", 20},
        {"Banana", 15}
    };

    sort(v.begin(), v.end(),
         [](const pair<string, int>& a,
            const pair<string, int>& b) {
             return a.second < b.second;
         });

    for (const auto& p : v) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
