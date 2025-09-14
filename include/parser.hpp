#ifndef CABRALCALC_PARSER
#define CABRALCALC_PARSER

#include <string>
#include <cstddef> // size_t
#include <iostream>
#include <vector>
#include <regex>
#include <unordered_set>

enum class TokenType {
	UNKNOWN = 0,
	NUMBER,
	OPERATOR,
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
	
	static std::regex validTokens();

};

namespace TokenIdentifiers {
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

