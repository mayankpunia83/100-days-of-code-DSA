#include <stdio.h>
#include <limits.h>

#define MAX 100

int n, m;
int graph[MAX][MAX];
int visited[MAX];
int minEdge[MAX];

int minKey()
{
    int min = INT_MAX, min_index;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && minEdge[i] < min)
        {
            min = minEdge[i];
            min_index = i;
        }
    }
    return min_index;
}

int primMST()
{
    for (int i = 1; i <= n; i++)
    {
        minEdge[i] = INT_MAX;
        visited[i] = 0;
    }

    minEdge[1] = 0;
    int totalWeight = 0;

    for (int i = 1; i <= n; i++)
    {
        int u = minKey();
        visited[u] = 1;
        totalWeight += minEdge[u];

        for (int v = 1; v <= n; v++)
        {
            if (graph[u][v] && !visited[v] && graph[u][v] < minEdge[v])
            {
                minEdge[v] = graph[u][v];
            }
        }
    }

    return totalWeight;
}

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = 0;

    // Input edges
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // Undirected
    }

    printf("%d\n", primMST());

    return 0;
}