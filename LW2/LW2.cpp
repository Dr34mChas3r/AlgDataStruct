#include <iostream>
#include <fstream>
#include <cmath>    // для pow

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
                product *= term;
            }
        }
        return product;
    }
}

int main() {
    int n;
    cout << "Input n: ";
    cin >> n;

    ifstream inFile("input.txt");
    if (!inFile.is_open()) {
        cerr << "Error opening input.txt" << endl;
        return 1;
    }

    ofstream outFile("output.txt");
    if (!outFile.is_open()) {
        cerr << "Error opening output.txt" << endl;
        return 1;
    }

    double x;
    while (inFile >> x) {
        double result = y(x, n);
        cout << "x = " << x << " -> y = " << result << endl;
        outFile << "x = " << x << " -> y = " << result << endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}
