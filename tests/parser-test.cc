#include "parser.h"

#include <string>
#include <vector>
#include <cassert>

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

int main(void) {
	std::vector<TestCase> t_tokenize = {
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
	
	return 0;
}
