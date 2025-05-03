#include <iostream>
#include "output.h"

using namespace std;

void outputTable(double start, double end, double step, int n, MathFunc fun) {
    cout << "x \ty(x)" << endl;

    for (double x = start; x <= end; x += step) {
        double y = fun(x, n);

        cout << x << "\t";
        if (y == -1 && fun == FunctionSqrtX) {
            cout << "y is not defined" << endl;
        }
        else {
            cout << y << endl;
        }
    }
}
