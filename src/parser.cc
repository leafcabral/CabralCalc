#include "parser/tokenizer.hpp"
#include "parser/math.hpp"
#include "parser.hpp"

#include <stdexception>

namespace parser {
	MathExpression::MathExpression(const std::string& s) : str{s}, tokens{}, result{0} {}

	std::vector<Tokens> MathExpression::_generateTokens() {

	}

	double MathExpression::_generateResult() {

	}

	double MathExpression::evaluate() {
		try {
			this->_generateTokens();
			return this->_generateResult();
		} catch (const std::runtime_error& e) {
			throw e;
		}
	}
}