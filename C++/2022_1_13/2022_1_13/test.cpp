#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Date{
public:	Date(int year = 0, int month = 1, int day = 1)	{		_year = year;		_month = month;		_day = day;	}	bool operator>(const Date& x)	{		if (_year > x._year)			return true;		else if (_year == x._year && _month > x._month)			return true;		else if (_year == x._year && _month == x._month && _day > x._day)			return true;		else return false;	}private:	int _year;	int _month;	int _day;};int main(){
	Date d1(2022, 1,30);	Date d2(2022, 2, 22);	cout<< (d1>d2) <<endl;}