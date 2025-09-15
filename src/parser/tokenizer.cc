#include "parser/tokenizer.hpp"

namespace tokenizer {
	SemiToken::SemiToken() {
		;
	}
	SemiToken::SemiToken(SemiTokenType stt, std::string& str, size_t pos) {
		;
	}
	SemiToken::SemiToken(std::string& str, size_t pos) const {
		;
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
	

	SemiToken::Token(SemiTokenType stt, std::string& str) {
		;
	}
	SemiToken::Token(std::string& str) {
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
