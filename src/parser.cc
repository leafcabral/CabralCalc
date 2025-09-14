#include "parser.hpp"

#include <regex>
#include <iostream>
#include <unordered_set>
#include <array>

namespace ValidTokens {
	const std::regex regexIntDivision("(//)");
	const std::regex regexNumber("([0-9]*\\.?[0-9]+(?:[eE][-+]?[0-9]+)?)");
	const std::regex regexIdentifier("([a-zA-Z][a-zA-Z0-9]*)");
	const std::regex regexOperator("([-+*/^])");
	const std::regex regexLParen("([(])");
	const std::regex regexRParen("([)])");
	const std::regex regexComma("(,)");
	const std::regex regexALL(
		"(//)|"
		"([0-9]*\\.?[0-9]+(?:[eE][-+]?[0-9]+)?)|"
		"([a-zA-Z][a-zA-Z0-9]*)|"
		"([-+*/^])|"
		"([(])|"
		"([)])|"
		"(,)"
	);

	// Double brackest to avoid "too many initializers" error
	const std::array<std::pair<const std::regex, TokenType>, 7> patterns = {{
		{regexIntDivision, TokenType::OPERATOR},
		{regexNumber, TokenType::NUMBER},
		{regexIdentifier, TokenType::IDENTIFIER},
		{regexOperator, TokenType::OPERATOR},
		{regexLParen, TokenType::L_PAREN},
		{regexRParen, TokenType::R_PAREN},
		{regexComma, TokenType::COMMA}
	}};
	
	const std::unordered_set<std::string> functions = {
		"sin", "cos", "tan", "sqrt", "log",
		"ln", "exp", "abs", "root", "max",
		"min"
	};
	const std::unordered_set<std::string> constants = {
		"pi", "euler", "goldenratio"
	};
}

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
			break;
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
	
	return strType + ':' + this->value;
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

std::clog << current << std::endl;
		
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
