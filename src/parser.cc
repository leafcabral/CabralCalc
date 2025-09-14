#include "parser.hpp"

#include <iterator> // std::distance
#include <cctype>
#include <stdexcept>

Token::Token(TokenType type, std::string_view value, size_t originalPosition) {
	this.type = type;
	this.value = value;
	this.originalPosition = originalPosition;
}

Token::Token(std::string value, size_t originalPosition) {
	this.type = TokenType::UNKNOWN;
	for (const auto& pattern : ValidTokens::patterns) {
		if (std::regex_match(value, pattern.first) {
			this.type = pattern.second;
		}
	}
	if (this.type == TokenType::IDENTIFIER) {
		if (ValidTokens::functions.contains(value)) {
			this.type = TokenType::FUNCTION;
		} else if (ValidTokens::constants.contains(value)) {
			this.type = TokenType::CONSTANT;
		}
	}
	
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
	MathExpression result;
	
	std::sregex_iterator begin(str.begin(), str.end(), ValidTokens::regexALL);
	std::sregex_iterator end;

	for (std::sregex_iterator i = begin; i != end; i++) {
		auto match = *i;
		Token current(match.str(), std::distance(str.begin(), match.first));

		if (current.type == TokenType::UNKNOWN) {
			throw current.originalPosition;
		}
		
		result.push_back(current);
	}

	return result;
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
