#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *create(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

struct Node *queue[100];
int front = -1, rear = -1;

void enqueue(struct Node *n)
{
    if (front == -1)
        front = 0;
    queue[++rear] = n;
}

struct Node *dequeue()
{
    return queue[front++];
}

struct Node *buildTree(int arr[], int n)
{
    if (arr[0] == -1)
        return NULL;

    struct Node *root = create(arr[0]);
    enqueue(root);

    int i = 1;
    while (i < n)
    {
        struct Node *current = dequeue();

        if (arr[i] != -1)
        {
            current->left = create(arr[i]);
            enqueue(current->left);
        }
        i++;

        if (i < n && arr[i] != -1)
        {
            current->right = create(arr[i]);
            enqueue(current->right);
        }
        i++;
    }
    return root;
}

void mirror(struct Node *root)
{
    if (root == NULL)
        return;

    struct Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node *root = buildTree(arr, n);

    mirror(root);

    inorder(root);

    return 0;
}