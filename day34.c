#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

int pop()
{
    struct node *temp;
    int value;

    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    temp = top;
    value = temp->data;
    top = top->next;
    free(temp);

    return value;
}

int main()
{
    char exp[100];
    int i = 0, a, b, result;

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    while (exp[i] != '\0')
    {

        if (exp[i] >= '0' && exp[i] <= '9')
        {
            push(exp[i] - '0');
        }

        else
        {
            b = pop();
            a = pop();

            switch (exp[i])
            {
            case '+':
                result = a + b;
                break;

            case '-':
                result = a - b;
                break;

            case '*':
                result = a * b;
                break;

            case '/':
                result = a / b;
                break;
            }

            push(result);
        }

        i++;
    }

    printf("Result = %d", pop());

    return 0;
}