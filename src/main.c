#include <stdio.h>
#include "stack.h"
#include "calculator.h"

int main()
{
    Stack stack;
    initializeStack(&stack);

    char command[100];

    printf("Введите команду (q для выхода):\n");

    while (1)
    {
        printf("> ");
        fgets(command, sizeof(command), stdin);

        // Удаление символа новой строки из введенной команды
        int len = strlen(command);
        if (command[len - 1] == '\n')
            command[len - 1] = '\0';

        if (strcmp(command, "q") == 0)
        {
            break;
        }
        else
        {
            processCommand(&stack, command);
        }
    }

    freeStack(&stack);

    return 0;
}
