#include <stdio.h>

#define MAX_VERTICES 10

void dfs(int graph[10][10], int n, int start, int visited[])
{
    visited[start] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[start][i] && !visited[i])
        {
            dfs(graph, n, i, visited);
        }
    }
}

int is_connected(int graph[10][10], int n)
{
    int visited[10] = {0};


    dfs(graph, n, 0, visited);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int n;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }


    if (is_connected(graph, n))
    {
        printf("The graph is connected.\n");
    }
    else
    {
        printf("The graph is not connected.\n");
    }

    return 0;
}
