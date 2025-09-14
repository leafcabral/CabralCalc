#ifndef CABRALCALC_PARSER
#define CABRALCALC_PARSER

// Heavy includes went to source files
#include <string>
#include <vector>
#include <unordered_set>
#include <iosfwd> // Forward declaration for iostream

enum class TokenType {
	UNKNOWN = 0,
	NUMBER,
	OPERATOR,
	IDENTIFIER, // Variables and initial func and const
	FUNCTION,
	CONSTANT,
	L_PAREN,
	R_PAREN,
	COMMA // Separate func args
};

struct Token {
	TokenType type;
	std::string value;
	size_t position; // For error printing

	Token(TokenType tt, std::string str, size_t pos);
	Token(std::string str, size_t pos);

	std::string toString() const;
};
// Operator overload outside to avoid friend keyword
std::ostream& operator<<(std::ostream& os, const Token& token);

namespace Parser {
	using MathExpression = std::vector<Token>;

	MathExpression tokenize(std::string str);
	MathExpression toPostfix(const MathExpression& infix);
	double evaluate(const MathExpression& postfix);

	std::string toString(const MathExpression& exp);
	std::ostream& operator<<(std::ostream& os, const MathExpression& exp);
};

#endif

