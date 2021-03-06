// Lab6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "header.h"

int main()
{
	double a = 0, b = 1, eps = 1e-5, S1, S2;
	S1 = trapez(a, b, eps, f1);
	S2 = trapez(a, b, eps, f2);
	char txt[] = "D:\\source\\repos\\Lab6\\Lab6.txt";
	FILE(txt, fp);
	fprintf(fp, "Function №1\n");
	tabulate_func1(f1, fp);
	printf("\n");
	fprintf(fp, "Function №2\n");
	tabulate_func2(f2, fp);
	fprintf(fp, "Integral F1 - %d\n", S1);
	fprintf(fp, "Integral F2 - %d\n", S2);
	fclose(fp);
	system("pause");
	return 0;
}

int tabulate_func1(func_t f, FILE* pf)
{
	double a = 0, b = 2, h = 0.2;
	double x = a;
	process_func(a, b, h, f1);
	for (; x <= b; x += h) {
		double y = f(x);
		FILE* fp = pf ? pf : stdout;
		fprintf(pf, "%f %f\n", x, y);
	}
	return 0;
}

int tabulate_func2(func_t f, FILE* pf)
{
	double a = 1, b = 4, h = 0.2;
	double x = a;
	for (; x <= b; x += h) {
		double y = f(x);
		FILE* fp = pf ? pf : stdout;
		fprintf(pf, "%f %f\n", x, y);
	}
	process_func(a, b, h, f2);
	printf("\n");
	return 0;
}

double trapez(double a, double b, double eps, func_t f){
	double S = 0, x, h = 0.01;
	x = a;
	while (x < b)
	{
		S = S + (f(x + h) + f(x))*h / 2;
		if (0.5*(f(x + h) + f(x))*h >= eps)
			x = x + h;
		else
			break;

	}
	return S;
}