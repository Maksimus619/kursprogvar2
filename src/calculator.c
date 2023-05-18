#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "calculator.h"

// Функция для обработки команды и вызова соответствующих операций
void processCommand(Stack *stack, const char *command)
{
    if (isNumeric(command))
    {
        // Если введенная команда является числом, помещаем его в стек
        double number = atof(command);
        push(stack, number);
    }
    else if (isOperator(command))
    {
        // Если введенная команда является оператором, извлекаем операнды из стека,
        // выполняем операцию и помещаем результат обратно в стек
        if (stack->size < 2)
        {
            printf("Ошибка: Недостаточно операндов в стеке для операции\n");
            return;
        }

        double operand2 = pop(stack);
        double operand1 = pop(stack);
        double result;

        if (strcmp(command, "+") == 0)
        {
            result = operand1 + operand2;
        }
        else if (strcmp(command, "-") == 0)
        {
            result = operand1 - operand2;
        }
        else if (strcmp(command, "*") == 0)
        {
            result = operand1 * operand2;
        }
        else if (strcmp(command, "/") == 0)
        {
            if (operand2 == 0)
            {
                printf("Ошибка: Деление на ноль\n");
                return;
            }
            result = operand1 / operand2;
        }
        else
        {
            printf("Ошибка: Неверный оператор\n");
            return;
        }

        push(stack, result);
    }
    else
    {
        printf("Ошибка: Некорректная команда\n");
    }
}

// Функция для проверки, является ли введенная команда числом
int isNumeric(const char *command)
{
    int i = 0;
    int dotCount = 0;
    char ch;

    if (command[i] == '-')
    {
        i++;
    }

    while ((ch = command[i]) != '\0')
    {
        if (isdigit(ch))
        {
            i++;
        }
        else if (ch == '.')
        {
            if (dotCount > 0)
            {
                return 0; // Больше одной десятичной точки
            }
            dotCount++;
            i++;
        }
        else
        {
            return 0; // Не цифра и не десятичная точка
        }
    }

    return 1;
}

// Функция для проверки, является ли введенная команда оператором
int isOperator(const char *command)
{
    return (strcmp(command, "+") == 0 || strcmp(command, "-") == 0 ||
            strcmp(command, "*") == 0 || strcmp(command, "/") == 0);
}
