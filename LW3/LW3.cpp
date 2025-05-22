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
	else {
		double product = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < n; j++) {
				product *= (x - i - 2 * j);
			}
			  if (product == 0.0) {
                return 0.0;
            }
		}
		return product;
	}
}

int main() {
	double start, end, step;
	int n;

	cout << "Input start, end of interval, step and value of n: ";
	cin >> start >> end >> step >> n;

	cout << "\nTable for calculated function y:" << endl;
	PrintFunctionTable(start, end, step, n, FunctionY);

	cout << "\nTable for calculated square root of x:" << endl;
	PrintFunctionTable(start, end, step, n, squareRoot);

	return 0;
}
