#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"

int main()
{
	Date d1;
	Date d2(2001, 2, 9);
	Date d3 = d2;
	d1.print();
	d2.print();
	d2 += 365;
	d2.print();
	d2 -= 90;
	d2.print();
	++d2;
	d2.print();
	d2++;
	d2.print();
	--d1;
	d1.print();
	d1--;
	d1.print();
	
	printf("%d", d2 > d1);
	printf("%d", d2 >= d1);
	printf("%d", d2 < d1);
	printf("%d", d2 <= d1);

	Date d4(2020, 1, 1);
	Date d5(2021, 2, 3);
	printf("%d", d5 - d4);

}