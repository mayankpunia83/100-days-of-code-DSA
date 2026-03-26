#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* queue[1000];
int front = 0, rear = 0;
void enqueue(struct Node* node) {
    queue[rear++] = node;
}
struct Node* dequeue() {
    return queue[front++];
}
int isEmpty() {
    return front == rear;
}
void zigzagTraversal(struct Node* root) {
    if (root == NULL) return;
    enqueue(root);
    int leftToRight = 1;
    while (!isEmpty()) {
        int size = rear - front;
        int level[size];
        for (int i = 0; i < size; i++) {
            struct Node* temp = dequeue();
            int index = leftToRight ? i : (size - 1 - i);
            level[index] = temp->data;
            if (temp->left) enqueue(temp->left);
            if (temp->right) enqueue(temp->right);
        }
        for (int i = 0; i < size; i++) {
            printf("%d ", level[i]);
        }
        leftToRight = !leftToRight;
    }
}
int main() {
    int n, val;
    scanf("%d", &n);
    if (n == 0) return 0;
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* root = createNode(arr[0]);
    front = rear = 0;
    enqueue(root);
    int i = 1;
    while (i < n) {
        struct Node* curr = dequeue();
        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(curr->left);
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }
    zigzagTraversal(root);

    return 0;
}