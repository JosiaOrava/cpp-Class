#include <algorithm>
#include <string>
#include <vector>
#include <iostream>


class RandGen {
public:

	RandGen(int min, int max) {
		this->min = min;
		this->max = max;
	}
	void changeCount(int i);
	int operator()();
private:
	int min = 0, max = 0, count = 0, nums = 0;
	std::vector<int> numbers;
};

void RandGen::changeCount(int i) {
	this->count = i;
}

int RandGen::operator()() {
	int num;
	std::srand(time(NULL));
	nums = (max - min) + 1;
	if (numbers.size() == nums && numbers.size() < count) {
		throw std::runtime_error("Unable to produce unique random number");
	}
	do {
		num = std::rand() % (max - min + 1) + min;
	} while (find(numbers.begin(), numbers.end(), num)!= numbers.end());
	
	numbers.push_back(num);

	return num;
}

void test_generator(RandGen rg, int count) {
	std::vector<int> numbers;
	
	rg.changeCount(count);
	try {
		std::cout << "Generating numbers:" << std::endl;
		std::generate_n(std::back_inserter(numbers), count, rg);
		
	}
	catch (std::runtime_error &e) {
			std::cout << "Exception: " << e.what() << std::endl;
			std::cout << "Tried to generate " << count << " random numbers. Got only " << numbers.size() << std::endl;;
	}
	
	std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(std::cout, "\n"));
	std::cout << "End of generator" << std::endl;
}

int main() {

	
	RandGen randGen(5, 13);

	test_generator(randGen, 6);
	test_generator(randGen, 9);
	test_generator(randGen, 13);

	RandGen randGen2(1, 35);

	test_generator(randGen2, 7);
	test_generator(randGen2, 7);
	test_generator(randGen2, 7);
	test_generator(randGen2, 70);


	return 0;
}