#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "stack.h"

void processCommand(Stack *stack, const char *command);
int isNumeric(const char *command);
int isOperator(const char *command);

#endif // CALCULATOR_H
