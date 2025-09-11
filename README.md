# CabralCalc

CabralCalc is a CLI-based calculator that's intended to have support for basic and advanced calculations

 This program will take a string input from the user and interpret it as a
mathematical expression, where the following operators are used:
  - "\+" for addition
  - "\-" for subtraction
  - "\*" for multiplication
  - "/" for division
  - "%" for module (remainder of division)
  - "^" for exponenciation
  - Parenthesis can also be used
  - Values can be stored for future use by using "$STO var [operation]":
if operation is present, store the value of operation in var, else, store the
value of the last operation
  - If the user input starts with an operator, its first operand will be the
    last expression result
  - The operators will have effect with the following priority: ^, %, \* and /,
\+ and \-
  - The expression will be evaluated from left to right, when the operators
are of the same priority
  - Writing "$QUIT" will close the program
