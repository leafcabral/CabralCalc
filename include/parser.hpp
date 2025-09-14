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
	size_t position; // For error printing

	Token(TokenType tt, std::string str, size_t pos);
	Token(std::string str, size_t pos);

	std::string toString() const;
	friend std::ostream& operator<<(std::ostream& os, const Token& token);

};

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

	const std::pair<const std::regex, TokenType> patterns[] = {
		{regexIntDivision, TokenType::OPERATOR},
		{regexNumber, TokenType::NUMBER},
		{regexIdentifier, TokenType::IDENTIFIER},
		{regexOperator, TokenType::OPERATOR},
		{regexLParen, TokenType::L_PAREN},
		{regexRParen, TokenType::R_PAREN},
		{regexComma, TokenType::COMMA},
	};
	
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
	std::ostream& operator<<(std::ostream& os, const MathExpression& exp);
};

#endif

