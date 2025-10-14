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
		
		Parser::MathExpression infix;
		Parser::MathExpression postfix;
		// double result;
		
		try {
			infix = Parser::tokenize(input);
		} catch (const std::runtime_error& e) {
			std::cerr << e.what() << std::endl;
			continue;
		}
		postfix = Parser::toPostfix(infix);
		
		std::cout << Parser::toString(infix) << std::endl;
		std::cout << Parser::toString(postfix) << std::endl;
	} while (input != "quit");
	
	return 0;
}
