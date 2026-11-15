//DIY10
//Dynamic Matrix

#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int **data;

public:
    Matrix(int r, int c) {
        rows = r;
        cols = c;

        data = new int*[rows];

        for (int i = 0; i < rows; i++)
            data[i] = new int[cols];
    }

    // Deep copy constructor
    Matrix(const Matrix &m) {
        rows = m.rows;
        cols = m.cols;

        data = new int*[rows];

        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];

            for (int j = 0; j < cols; j++)
                data[i][j] = m.data[i][j];
        }
    }

    void setData() {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> data[i][j];
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++)
            delete[] data[i];

        delete[] data;
    }
};

int main() {
    Matrix m1(2, 2);

    cout << "Enter matrix elements: ";
    m1.setData();

    Matrix m2 = m1;

    cout << "Original Matrix:" << endl;
    m1.display();

    cout << "Copied Matrix:" << endl;
    m2.display();

    return 0;
}