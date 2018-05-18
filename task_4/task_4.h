#pragma once

typedef int(*handler_t)(void*);

typedef struct Vector3D {
	double a, b, c;
} VECTOR, PVECTOR;

int menu(const char* menu_items[]);
int tab_handler1(void*);
int tab_handler2(void*);
int tab_handler3(void*);
int tab_handler4(void*);
int tab_handler5(void*);
int tab_handler6(void*);
int vec_sum();
int vec_sub();
int multiplier();
int scal_mult();
int vec_mult();
int exit();

VECTOR operator+(const VECTOR& v1, const VECTOR& v2);
VECTOR operator-(const VECTOR& v1, const VECTOR& v2);
VECTOR operator*(const VECTOR& v1, int n);
VECTOR operator*(const VECTOR& v1, const VECTOR& v2);
VECTOR operator/(const VECTOR& v1, const VECTOR& v2);
ostream& operator<<(ostream& os, const VECTOR&);
