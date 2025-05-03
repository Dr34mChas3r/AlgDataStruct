#pragma once
#ifndef FUNCTION_TABLE_H
#define FUNCTION_TABLE_H

typedef double (*MathFunction)(double, int);
double squareRoot(double x, int n); // Dlya porivnyannya v file output.cpp ( if x<0, y=not defined )
void PrintFunctionTable(double start, double end, double step, int n, MathFunction func);

#endif
