#include "parser/semitoken.hpp"
#include "parser/token.hpp"
#include "parser/math.hpp"
#include "parser.hpp"

#include <stdexception>

namespace parser {
	MathExpression::MathExpression(const std::string& s) : str{s}, tokens{}, result{0} {}

	std::vector<Tokens> MathExpression::_generateTokens() {
		try {
			this->tokens = Token::convert(SemiToken::convert(this->str));
		} catch (const std::runtime_error& e) {
			throw e;
		}

		reurn this->tokens;
	}

	double MathExpression::_generateResult() {

	}

	double MathExpression::evaluate() {
		try {
			this->_generateTokens();
			this->_generateResult();
		} catch (const std::runtime_error& e) {
			throw e;
		}

		return this->result;
	}
}