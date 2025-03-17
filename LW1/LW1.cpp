#include <iostream>
#include <cmath>

using namespace std;
void readInput(double& x_start, double& x_end, double& step, int& n) {
    cout << "Enter the start of the interval: ";
    cin >> x_start;
    cout << "Enter the end of the interval: ";
    cin >> x_end;
    cout << "Enter the step size: ";
    cin >> step;
    cout << "Enter the value of n: ";
    cin >> n;
}

double compute(double x, int n) {
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
void output(double& x_start, double& x_end, double& step, int& n) {
    cout << "x:  y(x,n):" << endl;
    for (double x = x_start; x <= x_end; x += step) { 
        cout << x << "  " << compute(x, n) << endl;
    }
}
int main() {
    double x_start, x_end, step;
    int n;
    readInput(x_start, x_end, step, n);
    output(x_start, x_end, step, n);
    return 0;
}
