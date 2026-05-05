#include "ScalarConverter.hpp"
#include <climits>
#include <cerrno>
#include <cctype>
#include <iomanip>
#include <cmath>
#include <cstdlib>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal) {
	const std::string s = literal;

	if (s.empty()) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	if (s == "nan" || s == "nanf" || s == "+inf" || s == "+inff" || s == "-inf" || s == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (s == "nan" || s == "nanf")
			std::cout << "float: nanf" << std::endl;
		else if (s == "+inf" || s == "+inff")
			std::cout << "float: +inff" << std::endl;
		else
			std::cout << "float: -inff" << std::endl;

		if (s == "nan" || s == "nanf")
			std::cout << "double: nan" << std::endl;
		else if (s == "+inf" || s == "+inff")
			std::cout << "double: +inf" << std::endl;
		else
			std::cout << "double: -inf" << std::endl;
		return;
	}

	if (s.size() == 1 && !std::isdigit(static_cast<unsigned char>(s[0]))) {
		char c = s[0];
		if (std::isprint(static_cast<unsigned char>(c)))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;

		std::cout << "int: " << static_cast<int>(c) << std::endl;

		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
		std::cout.unsetf(std::ios::fixed);
		return;
	}

	bool isInt = true;
	size_t idx = 0;
	if (s[0] == '+' || s[0] == '-') idx = 1;
	for (; idx < s.size(); ++idx) {
		if (!std::isdigit(static_cast<unsigned char>(s[idx]))) { isInt = false; break; }
	}
	if (isInt && s.size() > 0) {
		errno = 0;
		char *end = NULL;
		long val = std::strtol(s.c_str(), &end, 10);
		if (errno == 0 && *end == '\0') {
			if (val < INT_MIN || val > INT_MAX) {
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
				return;
			}
			int iv = static_cast<int>(val);
			if (iv >= 0 && iv <= 127 && std::isprint(static_cast<unsigned char>(iv)))
				std::cout << "char: '" << static_cast<char>(iv) << "'" << std::endl;
			else if (iv >= 0 && iv <= 127)
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: impossible" << std::endl;

			std::cout << "int: " << iv << std::endl;
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << static_cast<float>(iv) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(iv) << std::endl;
			std::cout.unsetf(std::ios::fixed);
			return;
		}
	}

	if (s.size() > 1 && s[s.size() - 1] == 'f') {
		std::string core = s.substr(0, s.size() - 1);
		errno = 0;
		char *end = NULL;
		double d = std::strtod(core.c_str(), &end);
		if (errno == 0 && *end == '\0') {
			float f = static_cast<float>(d);

			if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
				std::cout << "char: impossible" << std::endl;
			else if (!std::isprint(static_cast<unsigned char>(static_cast<int>(d))))
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: '" << static_cast<char>(static_cast<int>(d)) << "'" << std::endl;

			if (std::isnan(d) || std::isinf(d) || d < INT_MIN || d > INT_MAX)
				std::cout << "int: impossible" << std::endl;
			else
				std::cout << "int: " << static_cast<int>(d) << std::endl;

			std::cout << std::fixed << std::setprecision(1);
			if (std::isnan(f))
				std::cout << "float: nanf" << std::endl;
			else if (std::isinf(f))
				std::cout << "float: " << (f > 0 ? "+inff" : "-inff") << std::endl;
			else
				std::cout << "float: " << f << "f" << std::endl;

			if (std::isnan(d))
				std::cout << "double: nan" << std::endl;
			else if (std::isinf(d))
				std::cout << "double: " << (d > 0 ? "+inf" : "-inf") << std::endl;
			else
				std::cout << "double: " << d << std::endl;

			std::cout.unsetf(std::ios::fixed);
			return;
		}
	}

	errno = 0;
	char *end = NULL;
	double d = std::strtod(s.c_str(), &end);
	if (errno == 0 && *end == '\0') {
		if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
			std::cout << "char: impossible" << std::endl;
		else if (!std::isprint(static_cast<unsigned char>(static_cast<int>(d))))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(static_cast<int>(d)) << "'" << std::endl;

		if (std::isnan(d) || std::isinf(d) || d < INT_MIN || d > INT_MAX)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(d) << std::endl;

		std::cout << std::fixed << std::setprecision(1);
		if (std::isnan(d))
			std::cout << "float: nanf" << std::endl;
		else if (std::isinf(d))
			std::cout << "float: " << (d > 0 ? "+inff" : "-inff") << std::endl;
		else
			std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;

		if (std::isnan(d))
			std::cout << "double: nan" << std::endl;
		else if (std::isinf(d))
			std::cout << "double: " << (d > 0 ? "+inf" : "-inf") << std::endl;
		else
			std::cout << "double: " << d << std::endl;

		std::cout.unsetf(std::ios::fixed);
		return;
	}

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}


