
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

bool readData(double& start, double& end, double& step, int& n) {
    /* cout << "Input start, end of interval, step and value of n: ";
  cin >> start >> end >> step >> n;
  if (start >= end || step <= 0 || n == 0) {
      cerr << "Wrong data" << endl;
      return false;  }*/
    start = -10;
    end = 10;
    step = 1;
    n = 2;
    return true;
}

double y(double x, int n) {
    if (x <= 0) {
        double sum = 0;
        for (int i = 0; i <= n; i++) {
            sum += pow(x - i, 2);
        }
        return sum;
    }
    if (x > 0) {
        double product = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < n; j++) {
                product *= (x - i - 2 * j);
            }
        }
        return fabs(product);
    }
}

void outputData(double start, double end, double step, int n)
{
    cout << "x\ty" << endl;
    for (double x = start; x <= end; x += step)
    {
        cout << x << "\t" << y(x, n) << endl;
    }
    int rows = (end - start) / step + 1;
    int cols = 2;
    double** secondArr = new double* [rows];
    for (int i = 0; i < rows; i++) {
        secondArr[i] = new double[cols];
    }
    double x = start;
    for (int i = 0; i < rows; i++) {
        secondArr[i][0] = x;
        secondArr[i][1] = y(x, n);
        x += step;
    }
    ofstream outputFile("first_out.txt");
    if (!outputFile) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }
    outputFile << "x\ty(x, n)" << endl;
    for (int i = 0; i < rows; i++) {
        outputFile << secondArr[i][0] << "\t" << secondArr[i][1] << endl;
    }
    outputFile.close();
    cout << "Data has been written to first_out.txt" << endl;
    for (int i = 0; i < rows; i++) {
        delete[] secondArr[i];
    }
    delete[] secondArr;
}

int firstarrayfunc() {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return -1;
    }
    int rows, cols;
    inputFile >> rows >> cols;
    cout << "Size of array: " << rows << " x " << cols << endl;

    int** FirstArr = new int* [rows];

    int** rowPtr = FirstArr;
    for (int i = 0; i < rows; i++, rowPtr++) {
        *rowPtr = new int[cols];
    }

    rowPtr = FirstArr;
    for (int i = 0; i < rows; i++, rowPtr++) {
        int* colPtr = *rowPtr;
        for (int j = 0; j < cols; j++, colPtr++) {
            inputFile >> *colPtr;
        }
    }
    inputFile.close();

    cout << "Read arr:" << endl;
    rowPtr = FirstArr;
    for (int i = 0; i < rows; i++, rowPtr++) {
        int* colPtr = *rowPtr;
        for (int j = 0; j < cols; j++, colPtr++) {
            cout << *colPtr << " ";
        }
        cout << endl;
    }

    rowPtr = FirstArr;
    for (int i = 0; i < rows; i++, rowPtr++) {
        delete[] * rowPtr;
    }
    delete[] FirstArr;

    return 0;
}

int main() {
    double start, end, step;
    int n;
    firstarrayfunc();
    if (readData(start, end, step, n)) {
        outputData(start, end, step, n);
        return 0;
    }
    return -1;
}