#include "parser.h"

instrNode newNumberNode(instrValue number) {
        return (instrNode) {
                .type = TYPE_NUMBER,
                .data = { .number = 0.0f }
        };
}

instrNode newOperationNode(instrOpcode code) {
        return (instrNode) {
                .type = TYPE_OPERATION,
                .data = { .operation = {
                        .code = OPCODE_NONE,
                        .left = NULL,
                        .right = NULL
                }}
        };
}

int insertNodeLeft(instrNode *node, instrNode left) {
        // TODO
}

int insertNodeRight(instrNode *node, instrNode right) {
        // TODO
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

