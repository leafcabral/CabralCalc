#ifndef CABRALCALC_TOKENIZER
#define CABRALCALC_TOKENIZER

#include <string>
#include <vector>
#include <iosfwd> // Forward declaration of iostream

namespace parser {
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

	struct SemiToken {
		SemiTokenType type;
		std::string value;
		size_t position;

		SemiToken(const SemiTokenType stt, const std::string& str, const size_t pos);

		std::string toString() const;
		SemiToken operator+(const SemiToken& other) const;

		static std::vector<SemiToken> convert(const std::string& str);
	};
}

#endif