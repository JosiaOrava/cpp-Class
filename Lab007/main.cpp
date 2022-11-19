#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

//Ordinary function
int randGen_1() {
	return rand() % 10 + 1;
}
//Function object
class RandGen_2 {
public:
	RandGen_2() : numbers() { srand(time(NULL)); }
	int operator()();
private:
	std::vector<int> numbers;
};

void main(void) {
	std::vector<int> numbers(10);
	//this is how to use "ordinary"function
	/* srand(time(NULL)); // it is necessary to remember to call this
	generate(numbers.begin(), numbers.end(), randGen_1); */
	//this is how to use function object
	RandGen_2 randGen_2;
	generate(numbers.begin(), numbers.end(), randGen_2);
	for (auto n : numbers)
		std::cout << n << std::endl;
}
int RandGen_2::operator()() {
	int number;
	do {
		number = rand() % 10 + 1;
	} while (find(numbers.begin(), numbers.end(), number) != numbers.end());
	numbers.push_back(number);
	return number;
}