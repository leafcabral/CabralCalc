// g++ src/parser.cc tests/parser-test.cc -o build/parser-test -std=c++23 -Iinclude -Wall -Wextra -Werror -Wconversion -Wformat -Wunreachable-code -Wfloat-equal -Wshadow -Wpointer-arith -Winit-self -g -fsanitize=address,undefined

#include "parser.hpp"

#include <string>
#include <iostream>
#include <vector>
#include <cassert>

/*
struct TestCase {
	std::string input;
	std::string output;

	TestCase(std::string input, std::string output) {
		this.input = input;
		this.output = output;
	}

	std::string comparisonString(std::string realOutput) {
		return '\'' + this.output, + "\' == \'" + realOutput + '\'';
	}
}
*/

int main(void) {
	/*std::vector<TestCase> t_tokenize = {
		TestCase("1 * 2 + 3", "1 * 2 + 3"),
		TestCase("1 + 2 * 3", "1 + 2 * 3"),
		TestCase("1 * (2 + 3)", "1 * (2 + 3)"),
		TestCase("1 - 2 + 3", "1 - 2 + 3"),
		TestCase("1 * 2 ^ 3 + 4", "1 * 2 ^ 3 + 4"),
		TestCase("1 * (2 + 3 * 4) + 5", "1 * (2 + 3 * 4) + 5")
	};

	for (auto test : t_tokenize) {
		std::string realOutput = Parser::toString(Parser::tokenize(test.input));

		std::cout << test.comparisonString(realOutput);
		assert(test.output == realOutput)
		std::cout << "Pass.\n";
	}
	*/

	std::string input;
	do {
		std::cout << ">> ";
		std::getline(std::cin, input);
		
		Parser::MathExpression exp = Parser::tokenize(input);
		std::cout << Parser::toString(exp) << std::endl;
	} while (input != "quit");
	
	return 0;
}
