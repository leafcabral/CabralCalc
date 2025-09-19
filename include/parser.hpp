#ifndef CABRALCALC_PARSER
#define CABRALCALC_PARSER

#include "parser/semitoken.hpp"
#include "parser/token.hpp"
#include "parser/math.hpp"
#include <string>
#include <vector>

namespace parser {
	class MathExpression {
	public:
		MathExpression(const std::string& s);

		std::vector<Tokens> _generateTokens();
		double _generateResult();
		
		double evaluate();
		
	private:
		std::string str;
		std::vector<Tokens> tokens;
		double result;
	}
}

#endif