#ifndef CABRAL_MATHEXPR_H
#define CABRAL_MATHEXPR_H

#include "parser.h"

typedef instrNode *MathExpression;

MathExpression MathExprNew();
void MathExprClear(MathExpression mathExpr);

MathExpression MathExprParse(const char *exp);
float MathExprResult(MathExpression mathExpr);

#endif

