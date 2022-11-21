#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "Time.h"

Time::Time(int hour, int min) :hour(hour), min(min) {}

std::istream& operator>>(std::istream& in, Time& t) {
	in >> t.hour >> t.min;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Time& t) {
	out << std::setiosflags(std::ios::right); std::cout << std::setfill('0') << std::setw(2) << t.hour << ":" << std::setfill('0') << std::setw(2) << t.min << std::endl;
	return out;
}

Time Time::operator+(const Time& t) const
{
	Time tmp;
	tmp.hour = this->hour + t.hour;
	tmp.min = this->min + t.min;
	if (tmp.min >= 60)
	{
		tmp.min = tmp.min - 60;
		++tmp.hour;
	}
	if (tmp.hour >= 24)
	{
		tmp.hour = tmp.hour - 24;
	}

	return tmp;
}

Time Time::operator-(const Time& t) const {
	Time tmp;
	tmp.hour = this->hour - t.hour;
	tmp.min = this->min - t.min;
	if (tmp.min < 0) {
		tmp.min = tmp.min + 60;
		--tmp.hour;
	}
	if (tmp.hour < 0) {
		tmp.hour = tmp.hour + 24;
	}
	return tmp;
}

Time& Time::operator++() {
	++min;
	if (min >= 60) {
		min = min - 60;
		++hour;
	}
	if (hour >= 24) {
		hour = hour - 24;
	}
	return *this;
}

Time Time::operator++(int) {
	Time old = *this;
	++min;
	if (min >= 60) {
		min = min - 60;
		++hour;
	}
	if (hour >= 24) {
		hour = hour - 24;
	}
	return old;
}

bool Time::operator<(const Time& t) const {
	if (hour < t.hour || (hour == t.hour && min < t.min)) {
		return true;
	}
	return false;
}

bool Time::operator>(const Time& t) const {
	if (hour > t.hour || (hour == t.hour && min > t.min)) {
		return true;
	}
	return false;
}

bool Time::operator==(const Time& t) const {
	if (hour == t.hour && min == t.min) {
		return true;
	}
	return false;
}

void Time::read(std::string s)
{
	std::cout << s << std::endl;
	std::cout << "Give hours (0-24)" << std::endl;
	while (true) {
		std::cin >> hour;
		if (hour <= 24) {
			break;
		}
		else {
			std::cout << "Give proper hours" << std::endl;
		}
	}

	std::cout << "Give minutes (0-59)" << std::endl;
	while (true) {
		std::cin >> min;
		if (min <= 60) {
			break;
		}
		else {
			std::cout << "Give proper minutes" << std::endl;
		}
	}

}

bool Time::lessThan(Time t)
{
	int t1Hour = hour;
	int t1Min = min;
	int t2Hour = t.hour;
	int t2Min = t.min;
	if (t1Hour < t2Hour || (t1Hour == t2Hour && t1Min < t2Min))
	{
		return true;
	}
	return false;
}

void Time::display()
{
	std::cout << std::setiosflags(std::ios::right); std::cout << std::setfill('0') << std::setw(2) << hour;
	std::cout << ":" << std::setfill('0') << std::setw(2) << min << std::endl;
}

Time Time::subtract(Time t)
{
	Time diff;
	int diffMin, t1Min, t2Min;

	t1Min = hour * 60 + min;
	t2Min = t.hour * 60 + t.min;
	diffMin = t1Min - t2Min;
	diff.hour = diffMin / 60;
	diff.min = diffMin % 60;
	return diff;
}

void print(const std::vector<Time>& v)
{
	for (auto& t : v) {
		std::cout << t << std::endl;
	}
}