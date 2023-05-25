#include "syntax.h"
int check_brackets(char *s)
{
    int check_bracket = 0;
    int i = 0;
    while (s[i] != '\n' && s[i] != '\0')
    {
        if (s[i] == '(' && check_bracket >= 0)
        {
            check_bracket++;
        }
        else if (s[i] == ')')
        {
            check_bracket--;
        }
        i++;
    }
    if (check_bracket != 0)
    {
        return -12;
    }
    return 0;
}
int check_numbers(char *s)
{
    int i = 0;
    int check_dot = 0;
    while (isdigit(s[i]) || s[i] == '.')
    {
        if (s[i] == '.')
            check_dot++;
        if (check_dot > 1)
            return -2;
        i++;
    }
    return 0;
}
int syntax(char *s)
{
    int i = 0;
    int num_ops = 0;
    while (s[i] != '\n' && s[i] != '\0')
    {
        if (isdigit(s[i]))
        {
            if (check_numbers(s + i) < 0)
                return -2;
            while (isdigit(s[i]) || s[i] == '.')
                i++;
            num_ops++;
        }
        else if (
            s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            num_ops--;
            if (num_ops < 0)
                return -3;
            i++;
        }
        else if (s[i] == '(')
        {
            num_ops++;
            if (syntax(s + i + 1) < 0)
                return -4;
            i++;
            int bracket = 1;
            while (bracket != 0)
            {
                if (s[i] == '(')
                    bracket++;
                else if (s[i] == ')')
                    bracket--;
                i++;
            }
        }
        else if (s[i] == ')')
        {
            return 0;
        }
        else
        {
            i++;
        }
    }
    if (num_ops != 1)
        return -5;
    return 0;
}
