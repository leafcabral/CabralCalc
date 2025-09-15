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
		const size_t position;

		SemiToken();
		SemiToken(SemiTokenType stt, std::string& str, size_t pos);
		SemiToken(std::string& str, size_t pos) const;

		std::string toString() const;

		static std::vector<SemiToken> convert(const std::string& str);
	};
	std::ostream& operator<<(std::ostream& os, const SemiToken& stk);
	
	struct Token {
		const TokenType type;
		const std::string value;

		Token(SemiTokenType stt, std::string& str);
		Token(std::string& str);

		int cmpPrecendence(const Token& other) const;

		std::string toString() const;
		
		static std::vector<Token> convert(const SemiToken& stk);
	};
	std::ostream& operator<<(std::ostream& os, const Token& tk);

	std::vector<Token> toTokenList(const std::string& str);
}

#endif
