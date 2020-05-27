#include <iostream>
#include <bitset>
#include "../src/crc32.hpp"

int main() {
	static_assert(crc32("123") == 0x884863d2, "Invalid CRC32 Hash for \"123\"");
	static_assert(crc32("foobar") == 0x9ef61f95, "Invalid CRC32 Hash for \"foobar\"");
	static_assert(crc32("Lorem Ipsum") == 0x358ad45d, "Invalid CRC32 Hash for \"foobar\"");
	std::cout << "All tests successful." << std::endl;
}
