#ifndef CABRALCALC_PARSER
#define CABRALCALC_PARSER

#include <string_view>
#include <cstddef> // size_t
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
	std::string_view value;
	size_t originalPosition; // For error printing

	Token(TokenType type, std::string_view value, size_t originalPosition);
};

#endif

