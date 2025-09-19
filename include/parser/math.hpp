#ifndef CABRALCALC_MATH
#define CABRALCALC_MATH

#include "parser/semitoken.hpp"
#include "parser/token.hpp"
#include <vector>
#include <string>

namespace parser {
	void toPostfix(std::vector<Token>& infix);
	double evaluate(const std::vector<Token>& postfix);

	std::string toString(const std::vector<Token>& exp);
	std::ostream& operator<<(std::ostream& os, const std::vector<Token>& exp);
}

#ifndef
