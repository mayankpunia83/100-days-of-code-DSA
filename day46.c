#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *queue[100];
int front = 0, rear = 0;

void enqueue(struct Node *node)
{
    queue[rear++] = node;
}

struct Node *dequeue()
{
    return queue[front++];
}

void levelOrder(struct Node *root)
{
    if (root == NULL)
        return;

    enqueue(root);

    while (front < rear)
    {
        struct Node *temp = dequeue();
        printf("%d ", temp->data);

        if (temp->left)
            enqueue(temp->left);
        if (temp->right)
            enqueue(temp->right);
    }
}

int main()
{
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n == 0)
        return 0;

    int arr[n];
    printf("Enter node values: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    struct Node *nodes[n];
    for (i = 0; i < n; i++)
    {
        nodes[i] = createNode(arr[i]);
    }

    for (i = 0; i < n; i++)
    {
        if (2 * i + 1 < n)
            nodes[i]->left = nodes[2 * i + 1];
        if (2 * i + 2 < n)
            nodes[i]->right = nodes[2 * i + 2];
    }

    struct Node *root = nodes[0];

    printf("Level Order Traversal: ");
    levelOrder(root);

    return 0;
}