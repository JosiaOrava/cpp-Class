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




class Observer {
public:
	virtual void handleLimitReached() = 0;
};

class OverflowCounter : public Counter {
public:
	OverflowCounter(int ini, int max);
	Observer* obs;
	void setObserver(Observer*);
	void increment(int i);
	void inc();
	void decrement(int i);
	void dec();
	operator int();
private:
	void notify();
	int val, max;
};
 
void OverflowCounter::setObserver(Observer*) {
	this->obs = new Observer;
}

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
			inc();
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
			dec();
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

class CounterUser {
public:
	OverflowCounter* obj;
	CounterUser(int limit);
	void IncrementBy(int i);
	void HandleLimitReached();
private:
	int limit;
};

CounterUser::CounterUser(int limit) {
	this->limit = limit;
	obj = new OverflowCounter();
}

void CounterUser::IncrementBy(int i) {

}

int main(int argc, char** argv) {
	CounterUser cu(5);
	cu.IncrementBy(12); //OUTPUT: two times "Limit has been reached"
	CounterUser cu2(9);
	cu2.IncrementBy(9);
	std::cout << "Just passing time" << std::endl;
	cu2.IncrementBy(1); //OUTPUT: "Limit has been reached"

	return 0;
}