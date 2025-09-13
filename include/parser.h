#ifndef CABRAL_PARSER_H
#define CABRAL_PARSER_H

// Implementation

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
	TYPE_NODE = 0
	TYPE_VALUE,
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

int instrFromStr(Instruction *root, const char *str);

// Abstraction

typedef struct MathExpression {
	
} MathExpression;

int MathExpressionInit(MathExpression *exp);
int MathExpressionFree(MathExpression *exp);


#endif
