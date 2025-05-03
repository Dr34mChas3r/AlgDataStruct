#include <iostream>
#include "output_table.h"

using namespace std;

void outputTable(double start, double end, double step, int n, MathFunc func) {
    cout << "x \ty(x)" << endl;

    for (double x = start; x <= end; x += step) {
        double y = func(x, n);

        cout << x << "\t";
        if (y == -1 && func == FunctionSqrtX) {
            cout << "y is not defined" << endl;
        }
        else {
            cout << y << endl;
        }
    }
}
