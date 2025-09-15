#ifndef CABRALCALC_MATH
#define CABRALCALC_MATH

#include "parser/tokenizer.hpp"
#include <vector>
#include <string>

namespace mathexp {
	using Expression = std::vector<tokenizer::Token>;

	void toPostfix(Expression& infix);
	double evaluate(const Expression& postfix);

	std::string toString(const Expression& exp);
	std::ostream& operator<<(std::ostream& os, const Expression& exp);
}

#ifndef
