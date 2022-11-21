#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include "Time.h"
#include <iomanip>

class Day {
public:
	Day();
	bool from_str(const std::string& s);
	std::string to_str();
	void dst(int offset);
private:
	int day;
	std::string month;
	std::vector<Time> list;
};

Day::Day()
{
	day = 1;
}


bool Day::from_str(const std::string& s) {
	this->day = NULL;
	this->month = "";
	this->list.erase(list.begin(), list.end());
	Time time;
	std::string word;
	std::vector<std::string> words;
	if (s.find("Broken") != std::string::npos || s.length()==0) {
		return false;
	}
	for (auto x : s) {
		if (x == ' ') {
			words.push_back(word);
			word = "";
		}
		else {
			word = word + x;
		}
	}
	this->day = stoi(words[0]);
	this->month = words[1];
	words.erase(words.begin());
	words.erase(words.begin());
	for (auto& x : words) {
		for (auto j : x) {
			if (j == ':') {
				time.hour = stoi(word);
				word = "";
			}
			else {
				word = word + j;
			}
		}
		time.min = stoi(word);
		word = "";
		
		this->list.push_back(time);
	}
	std::sort(this->list.begin(), this->list.end());
	return true;
}

std::string Day::to_str()
{
	std::string word;
	std::vector<Time> tmp = this->list;
	std::stringstream hour, min;
	int i = 0;
	for (auto& x : tmp) {
		hour << std::setfill('0') << std::setw(2) << x.hour;
		min <<  std::setfill('0') << std::setw(2) << x.min;
		word = word + hour.str() + ":" + min.str() + " ";
		hour.str("");
		min.str("");
	}
	std::string string = std::to_string(this->day) + " " + this->month + " " + word;
	return string;
}

void Day::dst(int offset)
{
	
	for (auto& x : this->list) {
		x.hour = x.hour + offset;
		if (x.hour >= 24)
		{
			x.hour = x.hour - 24;
		}
	}
}

int main()
{


	std::ifstream inputFile("calendar.txt");

	if (!inputFile.is_open()) {
		std::cout << "Unable to open file" << std::endl;
		return 1;
	}

	std::string line;
	std::vector<Day> cal;
	Day day;

	while (getline(inputFile, line)) {
		if (day.from_str(line)) {
			cal.push_back(day);
		}
		
	}
	std::cout << "Calendar" << std::endl;

	for (auto& e : cal) {
		std::cout << e.to_str() << std::endl;
	}

	// DST shift
	for (auto& e : cal) {
		e.dst(1);
	}
	std::cout << "DST" << std::endl;

	for (auto& e : cal) {
		std::cout << e.to_str() << std::endl;
	}
	
	std::cout << "End" << std::endl;
	
	return 0;
}



