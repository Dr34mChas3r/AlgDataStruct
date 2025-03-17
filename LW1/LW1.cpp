#include <iostream>
#include <cmath>
using namespace std;

bool readData(double& start, double& end, double& step, int& n) {
	cout << "Input start, end of interval, step and value of n: ";
	cin >> start >> end >> step >> n;
	if (start >= end || step <= 0 || n == 0) {
		cerr << "Wrong data" << endl;
		return false;
	}
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
}
int main() {
    double start, end, step;
    int n;
    if (readData(start, end, step, n)) {
        outputData(start, end, step, n);
        return 0;
    }
    return -1;
}
