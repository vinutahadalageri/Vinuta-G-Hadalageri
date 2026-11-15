#include <iostream>
using namespace std;

template <class T>
void swapVals(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
T findMax(T arr[], int n)
{
    T maxVal = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    return maxVal;
}

int main()
{
    int a = 10, b = 20;
    swapVals(a, b);
    cout << "Swapped integers: " << a << " " << b << endl;

    double x = 2.5, y = 5.5;
    swapVals(x, y);
    cout << "Swapped doubles: " << x << " " << y << endl;

    int arr1[] = {10, 30, 20, 40};
    double arr2[] = {2.5, 7.8, 4.3, 6.1};

    cout << "Maximum integer: " << findMax(arr1, 4) << endl;
    cout << "Maximum double: " << findMax(arr2, 4) << endl;

    return 0;
}
