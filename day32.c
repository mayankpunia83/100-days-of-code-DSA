#include <stdio.h>

int top = -1;

void push(int stack[], int x) {
    top++;
    stack[top] = x;
}

void pop() {
    top--;
}

int main() {
    int n, m, i, x;

    scanf("%d", &n);
    int stack[n];  

    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        push(stack, x);
    }

    scanf("%d", &m);

    for(i = 0; i < m; i++) {
        pop();
    }

    for(i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}