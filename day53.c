#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct QNode {
    struct Node* node;
    int hd;
};

struct Queue {
    int front, rear;
    struct QNode arr[100];
};

void enqueue(struct Queue* q, struct Node* node, int hd) {
    q->arr[++q->rear].node = node;
    q->arr[q->rear].hd = hd;
}

struct QNode dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front > q->rear;
}

void verticalOrder(struct Node* root) {
    if (!root) return;

    struct Queue q;
    q.front = 0;
    q.rear = -1;

    int map[100][100];
    int size[100] = {0};

    enqueue(&q, root, 0);

    while (!isEmpty(&q)) {
        struct QNode temp = dequeue(&q);
        struct Node* node = temp.node;
        int hd = temp.hd + 50;

        map[hd][size[hd]++] = node->data;

        if (node->left)
            enqueue(&q, node->left, temp.hd - 1);

        if (node->right)
            enqueue(&q, node->right, temp.hd + 1);
    }

    for (int i = 0; i < 100; i++) {
        if (size[i] != 0) {
            for (int j = 0; j < size[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            nodes[i] = newNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int left = 2*i + 1;
            int right = 2*i + 2;

            if (left < n)
                nodes[i]->left = nodes[left];

            if (right < n)
                nodes[i]->right = nodes[right];
        }
    }

    return nodes[0];
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}