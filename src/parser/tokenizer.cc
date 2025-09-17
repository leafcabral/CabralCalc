#include "parser/tokenizer.hpp"
#include <cctype>
#include <stdexcept>
#include <algorithm>

namespace tokenizer {
	SemiToken(const SemiTokenType stt, const std::string& str, const size_t pos) {
		type {stt};
		value {str};
		position {pos};
	}
	
	SemiToken operator+(const SemiToken& other) const {
		return SemiToken(
			this->type,
			this->value + other.value,
			std::min(this->position, other.position)
		);
	}
	
	std::string toString() const {
		return this->value;
	}
	
	static std::vector<SemiToken> SemiToken::convert(const std::string& str) {
		std::vector<SemiToken> semiTokens;
		
		std::string validOperators = "+-*/^|%";
		int checkParen = 0;

		using enum SemiTokenType;
		for (int i = 0; i < str.length(); i++) {
			SemiTokenType currentType = UNKNOWN;
			char currentCHAR = str[i];
			
			if (std::isdigit(currentCHAR)) {
				currentType = NUMBER;
				
				if (!semiTokens.empty()) {
					if (semiTokens.back().type == IDENTIFIER) {
						currentType = IDENTIFIER;
					}
				}
			}
			else if (std::isspace(currentCHAR)) { currentType = WHITESPACE; }
			else if (validOperators.contains(currentCHAR)) { currentType = OPERATOR; }
			else if (std::isalpha(currentCHAR)) {
				currentType = IDENTIFIER;
				
				if (!semiTokens.empty()) {
					SemiToken last = semiTokens.back();
					
					if (last.type == NUMBER) {
						semiTokens.push_back(SemiToken(OPERATOR, "*", i));
					}
				}
			}
			else if (currentCHAR == '(') {
				currentType = L_PAREN;
				checkParen++;
			}
			else if (currentCHAR == ')') {
				currentType = R_PAREN;
				checkParen--;
			}
			else if (currentCHAR == ',') { currentType = COMMA; } 
			else if (currentCHAR == '.') {
				if (!semiTokens.empty()) {
					if (semiTokens.back().type == NUMBER) {
						currentType = NUMBER;
					}
				}
			} else if (currentCHAR = '_') {
				if (!semiTokens.empty()) {
					SemiToken last = semiTokens.back();
					
					if (last.type == NUMBER) {
						continue;
					} else if (last.type == IDENTIFIER) {
						currentType = IDENTIFIER;
					}
				}
			}
			if (currentType == UNKNOWN) {
				throw std::runtime_error("Invalid character at column " + std::tostring(i));
			}
			
			if (checkParen < 0) {
				throw std::runtime_error("Incorrect parentheses at column " + std::tostring(i));
			}

			SemiToken currentST(currentType, currentCHAR, i);
			
			if (!semiTokens.empty()) {
				SemiToken& last = semiTokens.back();

				if (last.type == currentST.type && (
				    last.type == NUMBER ||
				    last.type == IDENTIFIER ||
				    last.type == OPERATOR)
				) {
					last += currentST;
					continue;
				}
			}
			
			semiTokens.push_back(currentST); }
		}
		
		if (!checkParen) {
			throw std::runtime_error("One or more parentheses weren't properly closed");
		}

		return semiTokens;
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
