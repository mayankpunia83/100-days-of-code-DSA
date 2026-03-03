#include <stdio.h>
#include <stdlib.h>

int *stack;
int top = -1;
int capacity;

void push(int value)
{
    if (top == capacity - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n", stack[top--]);
}

void display()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    int n;

    scanf("%d", &capacity);

    stack = (int *)malloc(capacity * sizeof(int));

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int type;
        scanf("%d", &type);

        if (type == 1)
        {
            int value;
            scanf("%d", &value);
            push(value);
        }
        else if (type == 2)
        {
            pop();
        }
        else if (type == 3)
        {
            display();
        }
    }

    free(stack);
    return 0;
}