#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    top++;
    stack[top] = x;
}

char pop()
{
    char x = stack[top];
    top--;
    return x;
}

int priority(char x)
{
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char infix[100], postfix[100];
    int i = 0, j = 0;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0')
    {
        if (isalnum(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
        }

        else
        {
            while (top != -1 && priority(stack[top]) >= priority(infix[i]))
            {
                postfix[j] = pop();
                j++;
            }
            push(infix[i]);
        }

        i++;
    }

    while (top != -1)
    {
        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s", postfix);

    return 0;
}