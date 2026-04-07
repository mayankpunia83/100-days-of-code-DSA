#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int recStack[MAX];
int V;

bool dfs(int node)
{
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < V; i++)
    {
        if (graph[node][i])
        {
            if (!visited[i])
            {
                if (dfs(i))
                    return true;
            }
            else if (recStack[i])
            {
                return true;
            }
        }
    }

    recStack[node] = 0;
    return false;
}

bool hasCycle()
{
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(i))
                return true;
        }
    }
    return false;
}

int main()
{
    int E;
    printf("Enter vertices and edges: ");
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}