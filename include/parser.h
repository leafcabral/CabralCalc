#ifndef CABRAL_PARSER_H
#define CABRAL_PARSER_H

typedef float instrValue;
typedef enum {
	OPCODE_NONE = 0,
	OPCODE_ADD,
	OPCODE_SUB,
	OPCODE_MUL,
	OPCODE_DIV,
	OPCODE_MOD,
	OPCODE_EXP
} instrOpcode;
typedef enum {
	TYPE_OPERATION = 0
	TYPE_NUMBER,
} instrNodeType;

typedef struct instrNode {
	instrNodeType type;

	union {
		instrValue number;
		
		struct {
			instrOpcode code;
			struct instrNode *left;
			struct instrNode *right;
		} operation;
	} data;
} instrNode;

instrNode newNumberNode(instrValue number);
instrNode newOperationNode(instrOpcode code);

instrNode *treeFromStr(const char *str);
void deleteTree(instrNode *root);
typedef instrNode *MathExpression;

MathExpression MathExprNew();
void MathExprClear(MathExpression mathExpr);
MathExpression MathExprParse(const char *exp);
float MathExprResult(MathExpression mathExpr);

#endif
