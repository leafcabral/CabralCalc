#include "parser.hpp"

#include <iterator> // std::distance
#include <cctype>
#include <stdexcept>
#include <format>

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
	using enum TokenType;
	
	std::string strType;
	switch (this.type) {
		case UNKNOWN:
			strType = "UNKNOWN";
			break;
		case NUMBER:
			strType = "NUMBER";
			break;
		case OPERATOR:
			strType = "OPERATOR";
			break;
		case IDENTIFIER:
			strType = "IDENTIFIER";
			break;
		case FUNCTION:
			strType = "FUNCTION";
			break;
		case CONSTANT:
			strType = "CONSTANT";
			break;
		case L_PAREN:
			strType = "L_PAREN";
			break;
		case R_PAREN:
			strType = "R_PAREN";
			break;
		case COMMA:
			strType = "COMMA";
			break;
		default: break;
	}
	
	return std::format("{}:{}", strType, this.value);
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
	std::string result = "[";
	for (auto token : exp) {
		result += token.toString() + ", ";
	}
	result += "]";

	return result;
}

std::ostream& operator<<(std::ostream& os, const MathExpression& exp) {
	os << Parser::toString(exp);
	return os;
}
