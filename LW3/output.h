#pragma once
#ifndef FUNCTION_TABLE_H
#define FUNCTION_TABLE_H

typedef double (*MathFunction)(double, int);
double squareRoot(double x, int n); 
void PrintFunctionTable(double start, double end, double step, int n, MathFunction func);

#endif
