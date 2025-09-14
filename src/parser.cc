#include "parser.hpp"

Token::Token(TokenType type, std::string_view value, size_t originalPosition) {
	this.type = type;
	this.value = value;
	this.originalPosition = originalPosition;
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
