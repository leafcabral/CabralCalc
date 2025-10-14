#ifndef CABRALCALC_TOKENIZER
#define CABRALCALC_TOKENIZER

#include <string>
#include <vector>
#include <iosfwd> // Forward declaration of iostream

namespace parser {
	enum class TokenType {
		NUMBER,
		UNARY_OPERATOR,
		BINARY_OPERATOR,
		VARIABLE,
		FUNCTION,
		CONSTANT,
		L_PAREN,
		R_PAREN,
		COMMA
	};

	struct Token {
		const TokenType type;
		const std::string value;
		const size_t position;

		Token(const SemiTokenType tt, const std::string& str, const size_t pos);
		Token(const std::string& str, const size_t pos);
		Token(const SemiToken& st);

		int cmpPrecendence(const Token& other) const;

		std::string toString() const;
		
		static std::vector<Token> convert(const std::vector<SemiToken>& semiTokens);
		friend std::ostream& operator<<(std::ostream& os, const Token& tk);
	};
}

#endif