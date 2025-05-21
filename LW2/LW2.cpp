#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double y(double x, int n) {
    if (x <= 0) {
        double sum = 0;
        for (int i = 0; i <= n; i++) {
            sum += pow(x - i, 2);
        }
        return sum;
    }
    else {
        double product = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < n; j++) {
                double term = (x - i - 2 * j);
                if (term == 0.0) {
                    return 0.0;
                }
                product *= term;
            }
        }
        return product;
    }
}

int main() {
    ifstream inFile("input.txt");
    if (!inFile.is_open()) {
        cerr << "Error opening input.txt" << endl;
        return 1;
    }

    int rows, cols;
    inFile >> rows >> cols;

    int** array1 = new int* [rows];
    for (int i = 0; i < rows; i++) {
        array1[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            inFile >> array1[i][j];
        }
    }
    inFile.close();

    int n;
    cout << "Input your n: ";
    cin >> n;

    double** array2 = new double* [rows];
    for (int i = 0; i < rows; i++) {
        array2[i] = new double[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array2[i][j] = y(array1[i][j], n);
        }
    }

    ofstream outFile("output.txt");
    if (!outFile.is_open()) {
        cerr << "Error opening output.txt" << endl;
        return 1;
    }

    cout << "\nResult (y(x, n)):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << array2[i][j] << "\t";
            outFile << array2[i][j] << " ";
        }
        cout << endl;
        outFile << endl;
    }

    outFile.close();

    for (int i = 0; i < rows; i++) {
        delete[] array1[i];
        delete[] array2[i];
    }
    delete[] array1;
    delete[] array2;

    return 0;
}
