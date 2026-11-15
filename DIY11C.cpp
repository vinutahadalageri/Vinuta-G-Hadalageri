#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    unordered_map<string, int> freq;
    string word;

    cout << "Enter words (type end to stop): ";

    while (cin >> word)
    {
        if (word == "end")
            break;

        freq[word]++;
    }

    if (freq.empty())
    {
        cout << "No words entered." << endl;
        return 0;
    }

    cout << "\nWord frequencies:\n";

    string mostFrequent = "";
    int maxCount = 0;

    for (const auto &item : freq)
    {
        cout << item.first << " : " << item.second << endl;

        if (item.second > maxCount)
        {
            maxCount = item.second;
            mostFrequent = item.first;
        }
    }

    cout << "\nMost frequent word: " << mostFrequent << endl;
    cout << "Count: " << maxCount << endl;

    return 0;
}