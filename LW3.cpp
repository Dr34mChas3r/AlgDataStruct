#include <iostream>
#include <cmath>
#include "output.h"

using namespace std;

double FunctionY(double x, int n) {
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
double FunctionSqrtX(double x, int n) {
	return (x < 0) ? -1 : sqrt(x);
}


int main() {
	double start, end, step;
	int n;

	cout << "Input start, end of interval, step and value of n: ";
	cin >> start >> end >> step >> n;

	cout << "\nTable for function y:" << endl;
	outputTable(start, end, step, n, FunctionY);

	cout << "\nTable for square root x:" << endl;
		outputTable(start, end, step, n, FunctionSqrtX);	

	return 0;
}