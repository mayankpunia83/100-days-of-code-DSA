#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
bool visited[MAX];
int n;

bool dfs(int node, int parent)
{
    visited[node] = true;

    for (int i = 0; i < n; i++)
    {
        if (graph[node][i])
        {
            if (!visited[i])
            {
                if (dfs(i, node))
                    return true;
            }
            else if (i != parent)
            {
                return true;
            }
        }
    }
    return false;
}

int hasCycle()
{
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1))
                return 1;
        }
    }
    return 0;
}

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}