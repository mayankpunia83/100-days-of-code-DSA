#include <stdio.h>

#define MAX 100

int queue[MAX], front = 0, rear = 0;

void bfs(int n, int adj[MAX][MAX], int s) {
    int visited[MAX] = {0};

    queue[rear++] = s;
    visited[s] = 1;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, s;
    int adj[MAX][MAX];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    scanf("%d", &s);

    bfs(n, adj, s);

    return 0;
}