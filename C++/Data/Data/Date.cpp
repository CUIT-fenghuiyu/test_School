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

Date::Date(int year, int month, int day)
{
	if (year > 0 && month > 0 && month < 13 && day >= 0 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "非法日期" << endl;
	}
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
	while (n <= 0)
	{
		(this->_month)--;
		if (this->_month == 0)
		{
			(this->_year)--;
			this->_month = 12;
		}
		n += GetMonthDay(this->_year, this->_month);
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

Date& Date::operator++()
{
	*this += 1;

	return *this;
}

Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;

	return tmp;
}

Date& Date::operator--()
{
	--_day;
	if (_day == 0)
	{
		--_month;
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}
		_day = GetMonthDay(_year,_month);
	}

	return *this;
}

Date Date::operator--(int)
{
	Date tmp(*this);
	--tmp;
	return tmp;
}

bool Date::operator>(const Date& d)
{
	if (_year > d._year)
		return true;
	else if (_year == d._year && _month > d._month)
		return true;
	else if (_year == d._year && _month == d._month && _day > d._day)
		return true;
	else
		return false;
}

bool Date::operator==(const Date& d)
{
	if (_year == d._year && _month == d._month && _day == d._day)
		return true;
	else
		return false;
}

inline bool Date::operator>=(const Date& d)
{
	if (*this > d || *this == d)
		return true;
	else
		return false;
}

bool Date::operator<(const Date& d)
{
	if (*this >= d)
		return false;
	else
		return true;
}

bool Date::operator<=(const Date& d)
{
	if (*this > d)
		return false;
	else
		return true;
}

bool Date::operator!=(const Date& d)
{
	if (*this == d)
		return false;
	else
		return true;
}

int Date::operator-(const Date& d)
{
	Date Max = *this, Min = d;
	int n = 0;
	int flag = 1;

	if (*this < d)
	{
		Max = d;
		Min = *this;
		flag = -1;
	}

	while (Max != Min)
	{
		Min++;
		n++;
	}

	return n * flag;
}