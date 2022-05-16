#pragma once
#include<iostream>
#include "Constants.h"

class Date
{
	unsigned day;
	unsigned month;
	unsigned year;

	bool isLeapYear(unsigned year) const;
public:
	Date();
	Date(unsigned day, unsigned month, unsigned year);

	unsigned getDay()const;
	unsigned getMonth()const;
	unsigned getYear()const;

	bool operator==(const Date& other)const;
	bool operator<(const Date& other)const;

	friend std::ostream& operator << (std::ostream& out, const Date& date);
	friend std::istream& operator>>(std::istream& in, Date& date);
};
