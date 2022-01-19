#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"

void Date::print()
{
	std::cout << _year << "/" << _month << "/" << _day << std::endl;
}


int Date::GetMonthDay(int year, int month)
{
	static int monthDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	//判断年份是不是闰年
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
	{
		monthDay[2] = 29;
	}

	if (year > 0 && month >= 1 && month <= 12)
		return monthDay[month];
	else
		return -1;
}



Date::Date(const Date& d)
{
		_year = d._year;
		_month = d._month;
		_day = d._day;
}

Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;

	return *this;
}

Date::~Date()
{

}

Date& Date::operator+=(int day)
{
	if (day >= 0)
	{
		int n = this->_day + day;

		while (n > GetMonthDay(this->_year, this->_month))
		{
			n -= GetMonthDay(this->_year, this->_month);
			(this->_month)++;

			if (this->_month == 13)
			{
				(this->_year)++;
				this->_month = 1;
			}
		}
		this->_day = n;
	}

	return *this;
}

Date Date::operator+(int day)
{
	Date tmp = (*this);
	tmp += day;

	return tmp;
}

Date& Date::operator-=(int day)
{
	int n = this->_day - day;
	while (n < 0)
	{
		(this->_month)--;
		n += GetMonthDay(this->_year, this->_month);
		if (this->_month == 0)
		{
			(this->_year)--;
			this->_month = 12;
		}
	}
	this->_day = n;

	return *this;
}

Date Date::operator-(int day)
{
	Date tmp = (*this);
	tmp -= day;
	return tmp;
}

/*int Date::operator-(const Date& d)
{
	int years =0,months=0,days = 0;
	
	if (this->_year >= d._year)
	{
		years = this->_year - d._year;
	}
}*/