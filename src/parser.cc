#include "parser.hpp"

#include <cctype>
#include <string>

Token::Token(TokenType type, std::string_view value, size_t originalPosition) {
	this.type = type;
	this.value = value;
	this.originalPosition = originalPosition;
}

std::string Token::toString() {
	return this.value;
}

std::ostream& operator<<(std::ostream& os, const Token& token) {
	os << token.toString();
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

std::string Parser::toString(const MathExpression& exp) {
	std::string result;
	
	for (auto token : exp) {
		result += token.toString();

		using enum TokenType;
		switch (token.type) {
			case L_PAREN:
			case FUNCTION:
			case CONSTANT:
				break;
			default:
				result += ' ';
				break;
	}

	return result;
}

std::ostream& operator<<(std::ostream& os, const MathExpression& exp) {
	os << Parser::toString(exp);
	return os;
}
