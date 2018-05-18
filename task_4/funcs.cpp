#include "stdafx.h"
#include "task_4.h"

int menu(const char* menu_items[])
{
	int n;
	for (n = 0; menu_items[n]; ++n)
	{
		printf("\t[%d]. %s\n", n, menu_items[n]);
	}
	int i = -1;
	printf("\tChoice: ");
	if (scanf("%d", &i) == 1)
	{
		if (i >= 0 && i < n)
		{
			return i;
		}
	}
	return i;
}

int tab_handler1(void* p) {
	return vec_sum();
}

int tab_handler2(void* p) {
	return vec_sub();
}

int tab_handler3(void* p) {
	return multiplier();
}

int tab_handler4(void* p) {
	return scal_mult();
}

int tab_handler5(void* p) {
	return vec_mult();
}

int tab_handler6(void* p) {
	return exit();
}


VECTOR operator+(const VECTOR& v1, const VECTOR& v2) {
	return VECTOR{ v1.a + v2.a, v1.b + v2.b, v1.c + v2.c };
}

VECTOR operator-(const VECTOR& v1, const VECTOR& v2) {
	return VECTOR{ v1.a - v2.a, v1.b - v2.b, v1.c - v2.c };
}

VECTOR operator*(const VECTOR& v1, int n) {
	return VECTOR{ v1.a * n, v1.b * n, v1.c * n };
}

VECTOR operator*(const VECTOR& v1, const VECTOR& v2) {
	return VECTOR{ v1.a * v2.a, v1.b * v2.b, v1.c * v2.c };
}

VECTOR operator/(const VECTOR& v1, const VECTOR& v2) {
	return VECTOR{ v1.b * v2.c - v1.c * v2.b , -(v1.a * v2.c - v1.c * v2.a), v1.a * v2.b - v1.b * v2.a };
}

ostream& operator<<(ostream& os, const VECTOR& v)
{
	os << "{" << v.a << ";" << v.b << ";" << v.c << "}";
	return os;
}