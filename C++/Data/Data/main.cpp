#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"

int main()
{
	Date d1;
	Date d2(2001, 11, 9);
	Date d3 = d2;
	d1.print();
	d2.print();
	d2 += 365;
	d2.print();
	d2 -= 90;
	d2.print();
}