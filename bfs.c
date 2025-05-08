#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int color[MAX], distance[MAX], parent[MAX];
int adj[MAX][MAX], n;

void BFS(int s) {
    int queue[MAX], front = 0, rear = 0;

    for (int u = 0; u < n; u++) {
        if (u != s) {
            color[u] = WHITE;
            distance[u] = -1;
            parent[u] = -1;
        }
    }

    color[s] = GRAY;
    distance[s] = 0;
    parent[s] = -1;

    queue[rear++] = s;

    while (front < rear) {
        int u = queue[front++];  

        for (int v = 0; v < n; v++) {
            if (adj[u][v] && color[v] == WHITE) {
                color[v] = GRAY;
                distance[v] = distance[u] + 1;
                parent[v] = u;
                queue[rear++] = v; 
            }
        }

        color[u] = BLACK;
    }
}

int main() {
    int edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;  
    }

    printf("Enter start vertex for BFS: ");
    scanf("%d", &start);

    BFS(start);

    printf("Vertex\tDistance\tParent\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", i, distance[i], parent[i]);
    }

    return 0;
}
