#include "Dates.h"
#include <iostream>
#include <cassert>

bool Date::isLeapYear(unsigned year) const
{
	return (year % 4 == 0) && ((year % 400 == 0) || (year % 100 != 0));
}
Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}
Date::Date(unsigned day, unsigned month, unsigned year)
{
	assert(month > 0 && month <= 12);
	assert(day > 0 && day <= MONTH_DAYS[month - 1] + (month == 2 && isLeapYear(year)));

	this->day = day;
	this->month = month;
	this->year = year;
}

unsigned Date::getDay() const
{
	return day;
}

unsigned Date::getMonth() const
{
	return month;
}

unsigned Date::getYear() const
{
	return year;
}

bool Date::operator==(const Date& other) const
{
	return day == other.day && month == other.month && year == other.year;
}

bool Date::operator<(const Date& other) const
{
	return year < other.year || month < other.month || day < other.day;
}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	if (date.getDay() <= 9 && date.getMonth() <= 9)
		return out << "0" << date.getDay() << ".0" << date.getMonth() << "." << date.getYear();
	if (date.getDay() <= 9 && date.getMonth() >= 9)
		return out << "0" << date.getDay() << "." << date.getMonth() << "." << date.getYear();
	if (date.getDay() >= 9 && date.getMonth() <= 9)
		return out << "" << date.getDay() << ".0" << date.getMonth() << "." << date.getYear()  ;
	else
		return out << date.getDay() << "." << date.getMonth() << "." << date.getYear() ;
}

std::istream& operator>>(std::istream& in, Date& date)
{
	return in >> date.day >> date.month >> date.year;
}
