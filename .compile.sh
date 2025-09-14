#!/bin/bash

if [ $# -eq 0 ]; then
	echo "Usage: $0 <module_name>"
	exit 1
fi

MODULE="$1"
SRC_FILE="src/${MODULE}.cc"
TEST_FILE="tests/${MODULE}-test.cc"
OUT_FILE="build/${MODULE}"

if [ ! -f "${SRC_FILE}" ]; then
	echo "Error: Source file ${SRC_FILE} does not exist."
	exit 1
fi
if [ ! -f "${TEST_FILE}" ]; then
	echo "Error: Test file ${TEST_FILE} does not exist."
	exit 1
fi

mkdir -p build

echo "Starting compilation process..."
g++ "${SRC_FILE}" "${TEST_FILE}" -o "${OUT_FILE}" \
    -std=c++23 -Iinclude \
    -Wall -Wextra -Werror \
    -Wconversion -Wformat \
    -Wunreachable-code -Wfloat-equal -Wshadow \
    -Wpointer-arith -Winit-self \
    -g -fsanitize=address,undefined \

if [ $? -eq 0 ]; then
	echo "Program compiled successfuly!"
else
	echo "Program did not compiled dawg :("
	exit 1
fi

