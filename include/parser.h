#ifndef CABRAL_PARSER_H
#define CABRAL_PARSER_H

typedef float instrValue;
typedef enum {
	NODE_NUMBER,
	NODE_ADD,
	NODE_SUB,
	NODE_MUL,
	NODE_DIV,
	NODE_MOD,
	NODE_EXP
} instrNodeType;

typedef struct instrNode {
	instrNodeType type;

	union {
		instrValue number;
		struct {
			struct instrNode *left;
			struct instrNode *right;
		} next;
	} data;
} instrNode;

instrNode newNumberNode(instrValue number);
instrNode newOperationNode(instrNodeType code);

instrNode *allocNode(instrNode node);

void insertNodeLeft(instrNode *node, instrNode left);
void insertNodeRight(instrNode *node, instrNode right);

instrNode *treeFromStr(const char *str);
void deleteTree(instrNode *root);

#endif
