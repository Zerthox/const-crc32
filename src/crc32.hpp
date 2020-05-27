#pragma once

#include <cstddef>
#include <cstdint>

template <std::uint32_t MASK = 0xEDB88320>
constexpr std::uint32_t crc32(const std::string& str) {
	std::uint32_t result = 0xFFFFFFFF;
	for (std::size_t i = 0; i < str.size() * 8; i++) {
		if ((result & 1) != (static_cast<std::uint8_t>(str[i / 8]) >> i % 8 & 1)) {
			result = (result >> 1) ^ MASK;
		}
		else {
			result >>= 1;
		}
	}
	return ~result;
}

template <std::uint32_t MASK = 0xEDB88320, std::size_t N, std::size_t i = 0>
constexpr std::uint32_t crc32(const char (&str)[N], std::uint32_t result = 0xFFFFFFFF) {
	if constexpr (i >= N * 8) {
		return ~result;
	}
	else {
		return str[i / 8] == '\0' ? ~result : crc32<MASK, N, i + 1>(str, (result & 1) != (static_cast<std::uint8_t>(str[i / 8]) >> i % 8 & 1) ? (result >> 1) ^ MASK : result >> 1);
	}
}
