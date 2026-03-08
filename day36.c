#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;

    scanf("%d", &n);

    int q[n];
    int front = -1, rear = -1;

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);

        if (front == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % n;
        }
        q[rear] = x;
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        if (front == -1)
            break;

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % n;
        }
    }

    if (front != -1)
    {
        int i = front;
        while (1)
        {
            printf("%d ", q[i]);
            if (i == rear)
                break;
            i = (i + 1) % n;
        }
    }

    return 0;
}