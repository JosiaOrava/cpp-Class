#include <algorithm>
#include <string>
#include <vector>
#include <iostream>


class indexPrint {
public:
	void operator()(int i) {
		std::cout << "#" << ++index << ": "<< i << std::endl;
	}
private:
	int index = 0;
};

class RandGen {
public:
	
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
	std::srand(time(NULL));
	do {
		num = std::rand() % ( max - min + 1) + min;
	} while (find(numbers.begin(), numbers.end(), num) != numbers.end());
	numbers.push_back(num);
	return num;
}

int main() {
	std::vector<int> lottoNum(7), vikingNum(6), eurojackpotNum(5), v, v2;
	std::vector<int>::iterator it;
	RandGen lotto(1, 40), viking(1, 48), euro(1, 50);
	int awnser;
	while (1) {
		v.clear();
		v2.clear();
		// Generating numbers for each gamble
		std::generate(lottoNum.begin(), lottoNum.end(), lotto);
		std::generate(vikingNum.begin(), vikingNum.end(), viking);
		std::generate(eurojackpotNum.begin(), eurojackpotNum.end(), euro);

		std::cout << "Lotto numbers: ";
		std::copy(lottoNum.begin(), lottoNum.end(), std::ostream_iterator<int>(std::cout, " "));

		std::cout << "\nViking numbers: ";
		std::copy(vikingNum.begin(), vikingNum.end(), std::ostream_iterator<int>(std::cout, " "));

		// Getting the first matching numbers from lotto and viking
		std::sort(vikingNum.begin(), vikingNum.end());
		std::sort(lottoNum.begin(), lottoNum.end());
		std::set_intersection(lottoNum.begin(), lottoNum.end(), vikingNum.begin(), vikingNum.end(), std::back_inserter(v));
		std::cout << "\nMatching numbers:" << std::endl;
		std::for_each(v.begin(), v.end(), indexPrint());

		// Euro numbers and matching numbers from all numbers
		std::cout << "Eurojackpot: ";
		std::copy(eurojackpotNum.begin(), eurojackpotNum.end(), std::ostream_iterator<int>(std::cout, " "));
		std::sort(eurojackpotNum.begin(), eurojackpotNum.end());
		std::set_intersection(v.begin(), v.end(), eurojackpotNum.begin(), eurojackpotNum.end(), std::back_inserter(v2));
		std::cout << "\nMatching numbers in three sets:" << std::endl;
		std::for_each(v2.begin(), v2.end(), indexPrint());

		std::cout << "\nAgain? (1 = yes, 0 = no)" << std::endl;
		std::cin >> awnser;
		if (awnser == 0) {
			break;
		}
	}
	

	return 0;
}