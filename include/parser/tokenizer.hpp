#ifndef CABRALCALC_TOKENIZER
#define CABRALCALC_TOKENIZER

#include <string>
#include <vector>
#include <iosfwd> // Forward declaration of iostream

namespace tokenizer {
	enum class SemiTokenType {
		UNKNOWN,
		WHITESPACE,
		NUMBER,
		OPERATOR,
		IDENTIFIER,
		L_PAREN,
		R_PAREN,
		COMMA
	};
	
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

	struct SemiToken {
		SemiTokenType type;
		std::string value;
		size_t position;

		SemiToken(const SemiTokenType stt, const std::string& str, const size_t pos);

		std::string toString() const;
		SemiToken operator+(const SemiToken& other) const;

		static std::vector<SemiToken> convert(const std::string& str);
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
	};
	std::ostream& operator<<(std::ostream& os, const Token& tk);

	std::vector<Token> toTokenList(const std::string& str);
}

#endif
