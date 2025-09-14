#include "parser.hpp"

#include <cctype>
#include <string>

Token::Token(TokenType type, std::string_view value, size_t originalPosition) {
	this.type = type;
	this.value = value;
	this.originalPosition = originalPosition;
}

std::ostream& operator<<(std::ostream& os, const Token& token) {
	os << token.value;
	return os;
}

MathExpression Parser::tokenize(std::string str) {
	;
}

MathExpression Parser::toPostfix(const MathExpression& infix) {
	;
}

double Parser::evaluate(const MathExpression& postfix) {
	;
}

std::ostream& operator<<(std::ostream& os, const MathExpression& exp) {
	for (auto token : exp) {
		os << token.value;

		using enum TokenType;
		switch (token.type) {
			case L_PAREN:
			case FUNCTION:
			case CONSTANT:
				break;
			default:
				os << ' ';
				break;
		}
	}
}
