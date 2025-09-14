#ifndef CABRALCALC_PARSER
#define CABRALCALC_PARSER

#include <string>
#include <cstddef> // size_t
#include <iostream>
#include <vector>
#include <regex>
#include <unordered_set>
#include <utility> // std::pair

enum class TokenType {
	UNKNOWN = 0,
	NUMBER,
	OPERATOR,
	IDENTIFIER, // variables and initial func and const
	FUNCTION,
	CONSTANT,
	L_PAREN,
	R_PAREN,
	COMMA // separate func args
};

struct Token {
	TokenType type;
	std::string value;
	size_t originalPosition; // For error printing

	Token(TokenType type, std::string value, size_t originalPosition);
	Token(std::string value, size_t originalPosition);

	std::string toString();
	friend std::ostream& operator<<(std::ostream& os, const Token& token);

};

namespace ValidTokens {
	const std::regex regexIntDivision(R"(//)|");
	const std::regex regexNumber(R"(([0-9]*\.?[0-9]+(?:[eE][-+]?[0-9]+)?)|");
	const std::regex regexIdentifier(R"([a-zA-Z][a-zA-Z0-9]*)|");
	const std::regex regexOperator(R"([+\\-*/^])|");
	const std::regex regexLParen(R"([(])|");
	const std::regex regexRParen(R"([)])|");
	const std::regex regexComma(R"(,))");
	const std::regex regexALL(
		'(' +
		regexIntDivision.str() + ")|("+
		regexNumber.str() + ")|("+
		regexIdentifier.str() + ")|("+
		regexOperator.str() + ")|("+
		regexLParen.str() + ")|("+
		regexRParen.str() + ")|("+
		regexComma.str() +
		')'
	);

	const std::pair<const std::regex*, TokenType> patterns[] = {
		{&regexIntDivision, TokenType::OPERATOR},
		{&regexNumber, TokenType::NUMBER},
		{&regexIdentifier, TokenType::IDENTIFIER},
		{&regexOperator, TokenType::OPERATOR},
		{&regexLParen, TokenType::L_PAREN},
		{&regexRParen, TokenType::R_PAREN},
		{&regexComma, TokenType::COMMA},
	}
	
	const std::unordered_set<std::string> functions = {
		"sin", "cos", "tan", "sqrt", "log",
		"ln", "exp", "abs", "root", "max",
		"min"
	};
	const std::unordered_set<std::string> constants = {
		"pi", "euler", "goldenratio"
	};
};

namespace Parser {
	using MathExpression = std::vector<Token>;

	MathExpression tokenize(std::string str);
	MathExpression toPostfix(const MathExpression& infix);
	double evaluate(const MathExpression& postfix);

	std::string toString(const MathExpression& exp);
	friend std::ostream& operator<<(std::ostream& os, const MathExpression& exp);
};

#endif

