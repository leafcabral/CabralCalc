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

typedef struct instrNode {
	enum { TYPE_NODE, TYPE_VALUE } type;
	union {
		struct Instruction *node;
		instrValue value;	
	} data;
} instrNode;

typedef struct Instruction {
	instrOpcode operation;

	instrNode left;
	instrNode right;
} Instruction;
 
enum {
	PARSE_SUCCES,
	PARSE_FAIL
} parseResult;

enum parseResult instrFromStr(Instruction *root, const char *str);

#endif
