#include <stdio.h>
#define MAX 100

int main()
{
    int n, i;
    int queue[MAX], stack[MAX];
    int front = 0, rear = -1;
    int top = -1;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &queue[++rear]);
    }

    for (i = front; i <= rear; i++)
    {
        stack[++top] = queue[i];
    }

    front = 0;
    rear = -1;
    while (top != -1)
    {
        queue[++rear] = stack[top--];
    }

    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}