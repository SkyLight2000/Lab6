#pragma once

#define _USE_MATH_DEFINES
#define FILE(path, file)\
FILE* file;\
file = fopen (path, "w");\
	if (!file) {\
		printf("Error");\
		return -1;\
	}
#define cot 1/tan

typedef double(*func_t)(double);
typedef int(*handler_t)(void*, FILE*);

void process_func(
	double a
	, double b
	, double h
	, double(*pf)(double)
);

int tabulate_func1(func_t, FILE*);
int tabulate_func2(func_t, FILE*);
double trapez(double a, double b, double eps, func_t f);
double f1(double);
double f2(double);
