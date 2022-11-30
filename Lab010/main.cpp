#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


class Counter {
public:
	virtual void inc() = 0;
	virtual void increment(int i) = 0;
	virtual void dec() = 0;
	virtual void decrement(int i) = 0;
	virtual operator int() = 0;
	virtual ~Counter() {};
};

class LimitedCounter : public Counter {
public:
	LimitedCounter(int ini, int max);
	void increment(int i);
	void inc();
	void decrement(int i);
	void dec();
	operator int();

private:
	int val, max;
};

LimitedCounter::LimitedCounter(int ini, int max) {
	val = ini;
	this->max = max;
}

void LimitedCounter::increment(int i) {
	if ((val + i) <= max) {
		val += i;
	}
	else {
		for (int x = 0; x < i; x++) {
			if (val != max) {
				val++;
			}
		}
	}
}

void LimitedCounter::inc() {
	if (val != max) {
		++val;
	}
	
}

void LimitedCounter::decrement(int i) {
	if (val + i >= 0) {
		val += i;
	}
	else {
		for (int x = 0; x > i; x--) {
			if (val != 0) {
				val--;
			}
		}
	}
}

void LimitedCounter::dec() {
	if (val > 0) {
		--val;
	}
}

LimitedCounter::operator int() {	
	return val;
}

class OverflowCounter : public Counter {
public:
	OverflowCounter(int ini, int max);
	void increment(int i);
	void inc();
	void decrement(int i);
	void dec();
	operator int();
private:
	int val, max;
};

OverflowCounter::OverflowCounter(int ini, int max) {
	val = ini;
	this->max = max;
}

void OverflowCounter::increment(int i) {
	if ((val + i) <= max) {
		val += i;
	}
	else {
		for (int x = 0; x < i; x++) {
			//inc();
			if (val == max) {
				val = 0;
			}
			else {
				val++;
			}
		}
	}
}

void OverflowCounter::inc() {
	if (val != max) {
		++val;
	}
	else {
		val = 0;
		++val;
	}
}

void OverflowCounter::decrement(int i) {
	if ((val + i) >= 0) {
		val += i;
	}
	else {
		for (int x = 0; x > i; x--) {
			if (val == 0) {
				val = max;
			}
			else {
				val--;
			}
		}
	}
}

void OverflowCounter::dec() {
	if (val > 0) {
		--val;
	}
	else {
		val = max;
		--val;
	}
}

OverflowCounter::operator int() {
	return val;
}

void UseCounter(Counter& ctr, int num) {
	if (num > 0) {
		ctr.increment(num);
	}
	else {
		ctr.decrement(num);
	}
}

int main(int argc, char** argv) {
	LimitedCounter lc(0, 5);
	OverflowCounter oc(5, 9);

	std::cout << oc << std::endl;
	UseCounter(oc, 5);
	std::cout << oc << std::endl; // should display zero
	UseCounter(oc, -1);
	std::cout << oc << std::endl; // should display 9
	oc.dec();
	std::cout << oc << std::endl; // should display 8

	std::cout << lc << std::endl;
	lc.inc();
	std::cout << lc << std::endl;
	lc.dec();
	std::cout << lc << std::endl;
	for (int i = 0; i < 10; ++i) lc.inc();
	std::cout << lc << std::endl;
	UseCounter(lc, -9);
	std::cout << lc << std::endl;

	return 0;
}