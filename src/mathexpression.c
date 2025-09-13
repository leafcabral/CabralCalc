#include "mathexpression.h"

MathExpression MathExprNew() {
        return (MathExpression) NULL;
}
void MathExprClear(MathExpression mathExpr) {
        deleteTree(mathExpr);
}
MathExpression MathExprParse(const char *exp) {
        return treeFromStr(exp);
}
float MathExprResult(MathExpression mathExpr) {
        // TODO
}
