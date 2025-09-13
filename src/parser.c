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

instrNode *treeFromStr(const char *str) {
        // TODO
}
void deleteTree(instrNode *root) {
        // TODO
}

