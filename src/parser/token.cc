#include "parser/semitoken.hpp"
#include "parser/token.hpp"
#include <cctype>
#include <stdexcept>
#include <algorithm>

namespace parser {
	Token::Token(const TokenType tt, const std::string& str, const size_t pos) {
		type {tt};
		value {str};
		position {pos};
	}
	
	Token::Token(const std::string& str, const size_t pos) {
		;
	}

	Token(const SemiToken& st) {
		value {str};
		position {pos};
		switch (st.type) {
			case SemiTokenType::NUMBER:
				type {TokenType::NUMBER};
				break;
			case SemiTokenType::L_PAREN:
				type {TokenType::L_PAREN};
				break;
			case SemiTokenType::R_PAREN:
				type {TokenType::R_PAREN};
				break;
			case SemiTokenType::COMMA:
				type {TokenType::COMMA};
				break;
			case SemiTokenType::OPERATOR:
				type {TokenType::};
				break;
			case SemiTokenType::IDENTIFIER:
				type {TokenType::};
				break;
			default:
				throw std::runtime_error("Type mismatch when converting semi token to token");
		}
	}
	
	int Token::cmpPrecendence(const Token& other) const {
		;
	}

	std::string Token::toString() const {
		;
	}
	
	
	static std::vector<Token> Token::convert(const std::vector<SemiToken>& semiTokens) {
		std::vector<Token> tokens;

		for (auto st& : semiTokens) {
			
		}

		return tokens;
	}

	std::ostream& operator<<(std::ostream& os, const Token& tk) {
		;
	}
}