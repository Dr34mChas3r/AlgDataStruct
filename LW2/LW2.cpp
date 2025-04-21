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
                product *= (x - i - 2 * j);
            }
        }
        return fabs(product);
    }
}

int main() {
    const double start = -10;
    const double end = 10;
    const double step = 1;
    const int n = 2;

    ifstream inFile("input.txt");
    if (!inFile) {
        cerr << "Error opening input.txt" << endl;
        return 1;
    }

    int rows, cols;
    inFile >> rows >> cols;

    int** array = new int* [rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            inFile >> array[i][j];
        }
    }
    inFile.close();

    double** resultArray = new double* [rows];
    for (int i = 0; i < rows; i++) {
        resultArray[i] = new double[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int* ptr = &array[i][j];
            *(resultArray[i] + j) = y(*ptr, n); 
        }
    }

    ofstream outFile("output.txt");
    if (!outFile) {
        cerr << "Error opening output.txt" << endl;
        return 2;
    }

    cout << "Result array (y(x, n)):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << resultArray[i][j] << "\t";
            outFile << resultArray[i][j] << "\t";
        }
        cout << endl;
        outFile << endl;
    }

    outFile.close();

    for (int i = 0; i < rows; i++) {
        delete[] array[i];
        delete[] resultArray[i];
    }
    delete[] array;
    delete[] resultArray;

    return 0;
}
