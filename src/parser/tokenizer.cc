#include "parser/tokenizer.hpp"
#include <cctype>

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
		std::vector<SemiToken> semiTokens;

		using enum SemiTokenType;
		for (int i = 0; i < str.length(); i++) {
			SemiToken currentST;
			char currentCHAR = str[i];

			if (std::isdigit(currentCHAR)) { current {NUMBER, currentCHAR, i}; }
			else if (std::isspace(currentCHAR)) { current {WHITESPACE, currentCHAR, i}; }
			else if (std::isalpha(currentCHAR)) { current {IDENTIFIER, currentCHAR, i}; }
			else {
				switch (currentCHAR) {
					case '(':
						current {L_PAREN, currentCHAR, i};
						break;
					case ')':
						current {R_PAREN, currentCHAR, i};
						break;
					case ',':
						current {COMMA, currentCHAR, i};
						break;
					case '+':
					case '-':
					case '*':
					case '/':
					case '^':
					case '|':
					case '%':
						current {OPERATOR, currentCHAR, i};
						break;
				}
			}
		}
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
