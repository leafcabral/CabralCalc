#include "parser/tokenizer.hpp"
#include "parser/math.hpp"
#include "parser.hpp"

#include <string>
#include <vector>

namespace parser {
	class MathExpression {
	public:
		MathExpression(const std::string& str);
		
	private:
		std::string str;
		std::vector<tokenizer::Tokens> tokens;
		double result;
	}
}
