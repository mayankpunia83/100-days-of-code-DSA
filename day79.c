#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

struct Node
{
    int vertex;
    int weight;
    struct Node *next;
};

struct Node *adj[MAX];

struct HeapNode
{
    int vertex;
    int dist;
};

struct Node *newNode(int v, int w)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->vertex = v;
    temp->weight = w;
    temp->next = NULL;
    return temp;
}

void addEdge(int u, int v, int w)
{
    struct Node *temp = newNode(v, w);
    temp->next = adj[u];
    adj[u] = temp;
}

void dijkstra(int n, int src)
{
    int dist[MAX];
    int visited[MAX] = {0};

    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (int i = 1; i <= n; i++)
    {
        int u = -1;

        for (int j = 1; j <= n; j++)
        {
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }

        visited[u] = 1;

        struct Node *temp = adj[u];
        while (temp)
        {
            int v = temp->vertex;
            int w = temp->weight;

            if (dist[u] + w < dist[v])
                dist[v] = dist[u] + w;

            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", dist[i]);
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    int source;
    scanf("%d", &source);

    dijkstra(n, source);

    return 0;
}