#include <iostream>
#include <string>

void stringInput(std::string strings[]) {
	for (int i = 0; i < 10; i++) {
		std::cout << "Enter string " << i+1 << ": ";
		std::cin >> strings[i];
	}
}

void printOut(std::string (&strings)[10]) {
	for (auto string: strings) {
		std::cout << string << ": " << string.size() << std::endl;
	}
}

int main() {
	std::string strings[10];

	stringInput(strings);
	printOut(strings);

	return 0;
}