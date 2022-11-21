#pragma once
#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <iostream>

class Time
{
	friend std::istream& operator>>(std::istream& in, Time& t);
	friend std::ostream& operator<<(std::ostream& out, const Time& t);
private:
	
public:
	int hour, min;
	Time(int hour = 0, int min = 0);
	void read(std::string s);
	bool lessThan(Time t);
	Time subtract(Time t);
	void display();

	Time operator+(const Time& t) const;
	Time operator-(const Time& t) const;
	Time& operator++();
	Time operator++(int);
	bool operator<(const Time& t) const;
	bool operator>(const Time& t) const;
	bool operator==(const Time& t) const;
};

#endif