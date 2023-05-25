#include "score.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int k;
    if ((k = check_brackets(argv[1])) < 0)
    {
        fprintf(stderr,
                RED
                "ERROR SYNTAX1!!!\n"
                "ERROR %d\n" RESET,
                k);
        return -1;
    }
    if ((k = syntax(argv[1])) < 0)
    {
        fprintf(stderr,
                RED
                "ERROR SYNTAX1!!!\n"
                "ERROR %d\n" RESET,
                k);
        return -1;
    }
    else
    {
        double number = score(argv[1]);
        printf("Выражение равно = %f.\n", number);
    }
    return 0;
}
