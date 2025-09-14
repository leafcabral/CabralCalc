#ifndef CABRALCALC_PARSER
#define CABRALCALC_PARSER

#include <string>
#include <cstddef> // size_t
#include <iostream>
#include <vector>

enum class TokenType {
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
	
	friend std::ostream& operator<<(std::ostream& os, const Token& token);

};

namespace Parser {
	using MathExpression = std::vector<Token>;

	MathExpression tokenize(std::string str);
	MathExpression toPostfix(const MathExpression& infix);
	double evaluate(const MathExpression& postfix);

	friend std::ostream& operator<<(std::ostream& os, const MathExpression& exp);
};

#endif

