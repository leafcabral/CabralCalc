#include "parser.hpp"

#include <iterator> // std::distance
#include <cctype>
#include <stdexcept>
#include <format>

Token::Token(TokenType tt, std::string str, size_t pos) {
	this->type = tt;
	this->value = str;
	this->position = pos;
}

Token::Token(std::string str, size_t pos) {
	this->type = TokenType::UNKNOWN;
	for (const auto& pattern : ValidTokens::patterns) {
		if (std::regex_match(value, pattern.first)) {
			this->type = pattern.second;
		}
	}
	if (this->type == TokenType::IDENTIFIER) {
		if (ValidTokens::functions.contains(value)) {
			this->type = TokenType::FUNCTION;
		} else if (ValidTokens::constants.contains(value)) {
			this->type = TokenType::CONSTANT;
		}
	}
	
	this->value = str;
	this->position = pos;
}

std::string Token::toString() const {
	using enum TokenType;
	
	std::string strType;
	switch (this->type) {
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
	
	return std::format("{}:{}", strType, this->value);
}

std::ostream& operator<<(std::ostream& os, const Token& token) {
	os << token.toString();
	return os;
}
	
Parser::MathExpression Parser::tokenize(std::string str) {
	Parser::MathExpression result;
	
	std::sregex_iterator begin(str.begin(), str.end(), ValidTokens::regexALL);
	std::sregex_iterator end;

	for (std::sregex_iterator i = begin; i != end; i++) {
		auto match = *i;
		Token current(match.str(), match.position());

		if (current.type == TokenType::UNKNOWN) {
			throw current.position;
		}
		
		result.push_back(current);
	}

	return result;
}

/*
Parser::MathExpression Parser::toPostfix(const Parser::MathExpression& infix) {
	;
}

double Parser::evaluate(const Parser::MathExpression& postfix) {
	;
}
*/

std::string Parser::toString(const Parser::MathExpression& exp) {
	std::string result = "[";
	for (auto token : exp) {
		result += token.toString() + ", ";
	}
	result += "]";

	return result;
}

namespace Parser {
	std::ostream& operator<<(std::ostream& os, const Parser::MathExpression& exp) {
		os << Parser::toString(exp);
		return os;
	}
}
