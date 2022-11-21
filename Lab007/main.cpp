#include <algorithm>
#include <string>
#include <vector>
#include <iostream>


int ran() {
	return std::rand() % 100;
}
class RandGen {
public:
	RandGen() : numbers() { srand(time(NULL)); }
	RandGen(int min, int max) {
		this->min = min;
		this->max = max;
	}
	int operator()();
private:
	int min = 0, max = 0;
	std::vector<int> numbers;
};

int RandGen::operator()() {
	int num;
	do {
		num = std::rand() % max + min;
	} while (find(numbers.begin(), numbers.end(), num) != numbers.end());
	numbers.push_back(num);
	return num;
}

int main() {
	std::vector<int> lottoNum(7), vikingNum(6), eurojackpotNum(5), v, v2;
	std::vector<int>::iterator it;

	RandGen lotto(1, 40), viking(1, 48), euro(1, 50);

	// Generating numbers for each gamble
	std::generate(lottoNum.begin(), lottoNum.end(), lotto);
	std::generate(vikingNum.begin(), vikingNum.end(), viking);
	std::generate(eurojackpotNum.begin(), eurojackpotNum.end(), euro);

	std::cout << "Lotto numbers: ";
	std::for_each(lottoNum.begin(), lottoNum.end(), [](const auto& n) {
		std::cout << n << " ";
		});

	std::cout << "\nViking numbers: ";
	std::for_each(vikingNum.begin(), vikingNum.end(), [](const auto& n) {
		std::cout << n << " ";
		});

	// Getting the first matching numbers from lotto and viking
	std::sort(vikingNum.begin(), vikingNum.end());
	std::sort(lottoNum.begin(), lottoNum.end());
	std::set_intersection(lottoNum.begin(), lottoNum.end(), vikingNum.begin(), vikingNum.end(), std::back_inserter(v));
	std::cout << "\nMatching numbers:" << std::endl;
	std::for_each(v.begin(), v.end(), [](const auto& n, int i = 1) {std::cout << "#" << i << ": " << n << std::endl; i++; });

	// Euro numbers and matching numbers from all numbers
	std::cout << "Eurojackpot: ";
	std::for_each(eurojackpotNum.begin(), eurojackpotNum.end(), [](const auto& n) {std::cout << n << " "; });
	std::sort(eurojackpotNum.begin(), eurojackpotNum.end());
	std::set_intersection(v.begin(), v.end(), eurojackpotNum.begin(), eurojackpotNum.end(), std::back_inserter(v2));
	std::cout << "\nMatching numbers in three sets:" << std::endl;
	std::for_each(v2.begin(), v2.end(), [](const auto& n, int i = 1) {std::cout << "#" << i << ": " << n << std::endl; i++; });


	return 0;
}