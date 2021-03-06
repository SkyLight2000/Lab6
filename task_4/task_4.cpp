// task_4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "task_4.h"

VECTOR v1{ -1, 4, 6 }, v2{ 5, -7, 3 };

int main() {
	SetConsoleOutputCP(1251);
	const char* menu_items[] =
	{
		"Сложение векторов"
		, "Вычитание векторов"
		, "Умножение вектора на число"
		, "Скалярное умножение векторов"
		, "Векторное умножение векторов"
		, "Выход из программы"
		, NULL
	};
	handler_t handlers[] = {
		tab_handler1
		, tab_handler2
		, tab_handler3
		, tab_handler4
		, tab_handler5
		, tab_handler6
	};
	int idx;
	do {
		idx = menu(menu_items);
		if (idx < 0)
		{
			perror("Error index handler\n");
			return -1;
		}
		if (handlers[idx](NULL))
		{
			perror("Error handling\n");
		}
	} while (idx >= 0);
	system("pause");
	return 0;
}

int vec_sum()
{
	cout << "Сложение векторов" << endl;
	VECTOR v3 = v1 + v2;
	cout << v1 << "+" << v2 << "=" << v3 << endl;
	return 0;
}

int vec_sub()
{
	cout << "Вычитание векторов" << endl;
	VECTOR v4 = v1 - v2;
	cout << v1 << "-" << v2 << "=" << v4 << endl;
	return 0;
}

int multiplier() {
	cout << "Умножение вектора на число" << endl;
	int n;
	cout << "Введите множитель: " << endl;;
	scanf_s("%d", &n);
	VECTOR v5 = v1 * n;
	VECTOR v6 = v2 * n;
	cout << v1 << "*" << n << "=" << v5 << endl;
	cout << v2 << "*" << n << "=" << v6 << endl;
	return 0;
}

int scal_mult() {
	cout << "Скалярное умножение векторов" << endl;
	VECTOR v7 = v1 * v2;
	cout << v1 << "*" << v2 << "=" << v7 << endl;
	return 0;
}

int vec_mult() {
	cout << "Векторное умножение векторов" << endl;
	VECTOR v8 = v1 / v2;
	cout << v1 << "*" << v2 << "=" << v8 << endl;
	return 0;
}

int exit() {
	exit(EXIT_SUCCESS);
}