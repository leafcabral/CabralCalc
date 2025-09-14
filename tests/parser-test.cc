#include "parser.hpp"

#include <string>
#include <iostream>
#include <cassert>

#include <algorithm>
#include <cctype>
bool isEmptyOrWhitespace(const std::string& str) {
	return str.empty() || std::all_of(str.begin(), str.end(), [](unsigned char c) { return std::isspace(c); });
}

int main(void) {
	std::string input;
	do {
		std::cout << ">> ";
		std::getline(std::cin, input);
		if (input == "quit") { break; }
		if (isEmptyOrWhitespace(input)) { continue; }
		
		Parser::MathExpression exp;
		try {
			exp = Parser::tokenize(input);
		} catch (const std::runtime_error& e) {
			std::cerr << e.what() << std::endl;
			continue;
		}
		std::cout << Parser::toString(exp) << std::endl;
	} while (input != "quit");
	
	return 0;
}
