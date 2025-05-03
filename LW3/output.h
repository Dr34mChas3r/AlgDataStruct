#pragma once
#ifndef FUNCTION_TABLE_H
#define FUNCTION_TABLE_H

typedef double (*MathFunc)(double, int);
double FunctionSqrtX(double x, int n); // porivnyanna v output.cpp
void outputTable(double start, double end, double step, int n, MathFunc fun);

#endif
