#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>


class Time
{
	friend std::ostream& operator<<(std::ostream &out, const Time &t);
private:
	int hour, min;
public:
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
	
	
};

Time::Time(int hour, int min) :hour(hour), min(min){}

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
	if (hour < t.hour || (hour == t.hour && min < t.hour)) {
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



int main() {
	Time time1, time2, duration, duration2;

	time1.read("Enter time 1");
	time2.read("Enter time 2");
	
	if (time1 < time2) {
		duration = time2 - time1;
		std::cout << "Starting time was " << time1 << std::endl;
		duration2 = time1 - time2;
	}
	else {
		duration = time1 - time2;
		std::cout << "Starting time was " << time2 << std::endl;
		duration2 = time2 - time1;

	}
	std::cout << "Duration was " << duration << std::endl;

	// check that we don't get negative times
	std::cout << "Duration2 was " << duration2 << std::endl;


	std::vector<Time> tv(5);
	for (auto& t : tv) {
		t.read("Enter time:");
	}

	std::cout << "Times: " << std::endl;
	print(tv);

	Time sum;
	for (auto t : tv) {
		sum = sum + t;
	}

	std::cout << "Sum of times: " << sum << std::endl;

	std::cout << "Post-increment: " << std::endl;
	print(tv);
	for (auto& t : tv) {
		std::cout << t++ << std::endl;
	}

	print(tv);

	std::cout << "Pre-increment: " << std::endl;
	for (auto& t : tv) {
		std::cout << ++t << std::endl;
	}

	std::sort(tv.begin(), tv.end());

	std::cout << "Sorted times: " << std::endl;
	print(tv);

	return 0;
}