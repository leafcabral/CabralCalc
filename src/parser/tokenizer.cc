#include "parser/tokenizer.hpp"

namespace tokenizer {
	SemiToken::SemiToken() {
		type {UNKNOWN};
		value {""};
		position {0};
	}
	SemiToken(const std::string& str, const size_t pos) {
		;
	}
	SemiToken(const SemiTokenType stt, const std::string& str, const size_t pos) {
		type {stt};
		value {str};
		position {pos};
	}

	std::string SemiToken::toString() const {
		;
	}

	static std::vector<SemiToken> SemiToken::convert(const std::string& str) {
		;
	}
	
	std::ostream& operator<<(std::ostream& os, const SemiToken& stk) {
		;
	}
	

	SemiToken::Token(std::string& str) {
		;
	}
	SemiToken::Token(SemiTokenType stt, std::string& str) {
		;
	}

	int SemiToken::cmpPrecendence(const Token& other) const {
		;
	}

	std::string SemiToken::toString() const {
		;
	}
	
	static std::vector<Token> SemiToken::convert(const SemiToken& stk) {
		;
	}
	
	std::ostream& operator<<(std::ostream& os, const Token& tk) {
		;
	}

	std::vector<Token> toTokenList(const std::string& str) {
		;
	}
}
