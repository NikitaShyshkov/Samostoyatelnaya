#include "Date.h"

bool Date::isLeapYear() const
{
	if (year % 4 == 0 && year % 100 != 0)
	{
		return true;
	}
	else if (year % 100 == 0 && year % 400 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Date::monthDays() const
{
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		return isLeapYear() ? 29 : 28;
	}
	return -1;
}

void Date::nextDate()
{
	if (day == 31 && month == 12)
	{
		day = 1;
		month = 1;
		year++;
	}
	else if (day == monthDays())
	{
		day = 1;
		month++;
	}
	else
	{
		day++;
	}
}

void Date::prevDate()
{
	if (day == 1 && month == 1)
	{
		day = 31;
		month = 12;
		year--;
	}
	else if (day == 1)
	{
		month--;
		day = monthDays();
	}
	else
	{
		day--;
	}
}

Date::Date()
{
	struct tm* tim = new tm;
	time_t tt = time(NULL);
	localtime_s(tim, &tt);
	this->day = tim->tm_mday;
	this->month = tim->tm_mon + 1;
	this->year = tim->tm_year + 1900;
	delete tim;
}

Date::Date(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}

Date::Date(const Date& obj)
{
	this->day = obj.day;
	this->month = obj.month;
	this->year = obj.year;
}

Date& Date::operator=(const Date& obj)
{
	this->day = obj.day;
	this->month = obj.month;
	this->year = obj.year;
	return *this;
}

Date::~Date()
{

}

void Date::ShowDate() const
{
	cout << day / 10 << day % 10 << "." << month / 10 << month % 10 << "." << year;
}

void Date::setYear(int year)
{
	this->year = year;
}

int Date::getYear() const
{
	return year;
}

void Date::setMonth(int month)
{
	if (month >= 1 && month <= 12)
	{
		this->month = month;
	}
}

int Date::getMonth() const
{
	return month;
}

void Date::setDay(int day)
{
	if (day >= 1 && day <= monthDays())
	{
		this->day = day;
	}
}

int Date::getDay() const
{
	return day;
}

bool Date::valid() const
{
	if ((day >= 1 && day <= monthDays()) && (month >= 1 && month <= 12))
	{
		return true;
	}
	return false;
}

bool Date::operator==(const Date& obj) const&
{
	if (this->day == obj.day && this->month == obj.month && this->year == obj.year)
	{
		return true;
	}
	return false;
}

bool Date::operator!=(const Date& obj) const&
{
	return !(*this == obj);
}

bool Date::operator>(const Date& obj) const&
{
	if (this->year > obj.year)
	{
		return true;
	}
	else if (this->year == obj.year && this->month > obj.month)
	{
		return true;
	}
	else if (this->year == obj.year && this->month == obj.month && this->day > obj.day)
	{
		return true;
	}
	return false;
}

bool Date::operator<(const Date& obj) const&
{
	return !(*this > obj) && *this != obj;
}

bool Date::operator>=(const Date& obj) const&
{
	return (*this > obj) || (*this == obj);
}

bool Date::operator<=(const Date& obj) const&
{
	return (*this < obj) || (*this == obj);
}

Date& Date::operator+=(int days)
{
	for (int i = 0; i < days; i++)
	{
		this->nextDate();
	}
	return *this;
}

Date& Date::operator-=(int days)
{
	for (int i = 0; i < days; i++)
	{
		this->prevDate();
	}
	return *this;
}

Date& Date::operator+=(float months)
{
	this->month += months;
	if (this->month > 12)
	{
		this->year += this->month / 12;
		this->month %= 12;
		if (this->month == 0)
		{
			this->month = 12;
			this->year--;
		}
	}
	if (this->day > monthDays())
	{
		int n = this->day - monthDays();
		this->day = monthDays();
		for (int i = 0; i < n; i++)
		{
			nextDate();
		}
	}
	return *this;
}

Date& Date::operator-=(float months)
{
	this->month -= months;
	if (this->month <= 0)
	{
		this->year -= (12 - this->month) / 12;
		this->month %= 12;
		if (this->month <= 0)
		{
			this->month = 12 + this->month;
			//this->year--;
		}
	}
	if (this->day > monthDays())
	{
		int n = this->day - monthDays();
		this->day = monthDays();
		for (int i = 0; i < n; i++)
		{
			prevDate();
		}
	}
	return *this;
}

Date& Date::operator+=(long years)
{
	year += years;
	return *this;
}

Date& Date::operator-=(long years)
{
	year -= years;
	return *this;
}

Date Date::operator+(int days) const&
{
	Date tmp = *this;
	for (int i = 0; i < days; i++)
	{
		tmp.nextDate();
	}
	return tmp;
}

Date Date::operator-(int days) const&
{
	Date tmp = *this;
	for (int i = 0; i < days; i++)
	{
		tmp.prevDate();
	}
	return tmp;
}

Date Date::operator+(float months) const&
{
	Date tmp = *this;
	tmp += months;
	return tmp;
}

Date Date::operator-(float months) const&
{
	Date tmp = *this;
	tmp -= months;
	return tmp;
}

Date Date::operator+(long years) const&
{
	Date tmp = *this;
	tmp += years;
	return tmp;
}

Date Date::operator-(long years) const&
{
	Date tmp = *this;
	tmp -= years;
	return tmp;
}

int Date::operator-(const Date& obj) const&
{
	int days = 0;
	if (obj > *this)
	{
		Date tmp = *this;
		do
		{
			tmp.nextDate();
			days++;
		} while (tmp != obj);
	}
	else if (obj == *this)
	{
		return 0;
	}
	else
	{
		Date tmp = obj;
		do
		{
			tmp.nextDate();
			days++;
		} while (tmp != *this);
	}
	return days;
}

Date& Date::operator--()
{
	this->prevDate();
	return *this;
}

Date Date::operator--(int)
{
	Date tmp = *this;
	this->prevDate();
	return tmp;
}

Date& Date::operator++()
{
	this->nextDate();
	return *this;
}

Date Date::operator++(int)
{
	Date tmp = *this;
	this->nextDate();
	return tmp;
}

ostream& operator<<(ostream& os, const Date& t)
{
	os << t.day / 10 << t.day % 10 << "." << t.month / 10 << t.month % 10 << "." << t.year;
	return os;
}

istream& operator>>(istream& is, Date& t)
{
	do
	{
		cout << "dd:mm:yyyy\n";
		is >> t.day >> t.month >> t.year;
		//system("cls");
	} while (!t.valid());
	return is;
}

Date operator+(int n, const Date& a)
{
	Date tmp = a + n;
	return tmp;
}

Date operator-(int n, const Date& a)
{
	Date tmp = a - n;
	return tmp;
}
