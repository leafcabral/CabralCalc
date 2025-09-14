#include "parser.hpp"

#include <cctype>

Token::Token(TokenType type, std::string_view value, size_t originalPosition) {
	this.type = type;
	this.value = value;
	this.originalPosition = originalPosition;
}

Token::Token(std::string value, size_t originalPosition) {
	/* std::regex validTokens = Token::validTokens();
	this.value = value;
	this.originalPosition = originalPosition;
	*/
}

std::string Token::toString() {
	return this.value;
}

std::ostream& operator<<(std::ostream& os, const Token& token) {
	os << token.toString();
	return os;
}

static std::regex Token::validTokens() {
	std::regex valid(
		R"(([0-9]*\.?[0-9]+(?:[eE][-+]?[0-9]+)?)|" + // numbers
		R"([a-zA-Z][a-zA-Z0-9]*)|" + // identifier
		R"([+\\-*/^()])|" + // operator and parentheses
		R"(//)|" + // integer division (two operators together)
		R"(,))", // comma
		std::regex::optimize // slow compilation, fast runtime
	);
	return 
}
	
MathExpression Parser::tokenize(std::string str) {
	/*
	MathExpression result;
	std::regex validTokens("");

	std::sregex_token_iterator iterator(str.begin(), str.end(), validTokens);
	std::sregex_token_iterator end;

	for (; iterator != end; iterator++) {
		Token
		// va
		result.push_back(*iterator);
	}
	*/
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
