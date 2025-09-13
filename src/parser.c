#include "parser.h"
#include "utils.h"
#include <string.h>

instrNode newNumberNode(instrValue number) {
	return (instrNode) {
		.type = NODE_NUMBER,
		.data = { .number = number }
	};
}

instrNode newOperationNode(instrNodeType code) {
	return (instrNode) {
		.type = code,
		.data = { .operation = {
			.left = NULL,
			.right = NULL
		}}
	};
}

instrNode *allocNode(instrNode node) {
	instrNode *temp = salloc(sizeof(instrNode*));
	memcpy(temp, &node, sizeof(instrNode));
	
	return temp;
}

void insertNodeLeft(instrNode *node, instrNode left) {
	node->data.next.left = allocNode(left);
}

void insertNodeRight(instrNode *node, instrNode right) {
	node->data.next.right = allocNode(right);
}

/* 4 + 2 * 10 + 3 * (5 + 1)
+ 4
  + 
    * 2 10
    * 3
      + 5 1
*/
instrNode *treeFromStr(const char *str) {
	// TODO
}
void deleteTree(instrNode *root) {
	// TODO
}

