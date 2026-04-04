#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node
{
    int vertex;
    struct Node *next;
};

struct Graph
{
    int numVertices;
    struct Node *adjLists[MAX];
};

struct Node *createNode(int v)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void DFS(struct Graph *graph, int vertex, int visited[])
{
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node *temp = graph->adjLists[vertex];

    while (temp != NULL)
    {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex])
        {
            DFS(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

int main()
{
    int n, edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = n;

    for (int i = 0; i < n; i++)
    {
        graph->adjLists[i] = NULL;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    int visited[MAX] = {0};

    printf("DFS Traversal: ");
    DFS(graph, start, visited);

    return 0;
}