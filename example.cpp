#include <iostream>
#include "./src/crc32.hpp"

int main() {
	std::string target{"abc"};
	switch (crc32(target)) {
		case crc32("abc"):
			std::cout << "It is abc!" << std::endl;
			break;
		case crc32("123"):
			std::cout << "It is 123!" << std::endl;
			break;
		default:
			std::cout << "None of the above" << std::endl;
	}
}
