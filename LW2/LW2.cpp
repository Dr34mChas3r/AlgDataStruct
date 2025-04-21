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
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    if (!inFile || !outFile) {
        cerr << "Error in opening file(s)!" << endl;
        return 1;
    }

    int rows, cols;
    inFile >> rows >> cols;

    double** inputParams = new double* [rows];
    for (int i = 0; i < rows; i++) {
        *(inputParams + i) = new double[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            inFile >> *(*(inputParams + i) + j);
        }
    }

    for (int i = 0; i < rows; i++) {
        double start = *(*(inputParams + i) + 0);
        double end = *(*(inputParams + i) + 1);
        double step = *(*(inputParams + i) + 2);
        int n = (int)(*(*(inputParams + i) + 3)); 

        int count = ((end - start) / step) + 1;
        double* results = new double[count];

        double x = start;
        for (int j = 0; j < count; j++, x += step) {
            *(results + j) = y(x, n);
        }

        cout << "Results if: start = " << start
            << ", end = " << end
            << ", step = " << step
            << ", n = " << n << ":\n"
        outFile << "Results if: start = " << start
            << ", end = " << end
            << ", step = " << step
            << ", n = " << n << ":\n";

        x = start;
        for (int j = 0; j < count; j++, x += step) {
            cout << "x = " << x << ", y = " << *(results + j) << endl;
            outFile << "x = " << x << ", y = " << *(results + j) << endl;
        }

        cout << endl;
        outFile << endl;

        delete[] results;
    }

    // Звільнення пам'яті
    for (int i = 0; i < rows; i++) {
        delete[] * (inputParams + i);
    }
    delete[] inputParams;

    inFile.close();
    outFile.close();

    return 0;
}
