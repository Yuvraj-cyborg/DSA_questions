#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int adj[MAX][MAX], color[MAX], parent[MAX];
int discovery_time[MAX], finish_time[MAX];
int time = 0, n;

void DFSVisit(int u) {
    color[u] = GRAY; 
    discovery_time[u] = ++time;

    for (int v = 0; v < n; v++) {
        if (adj[u][v] && color[v] == WHITE) {
            parent[v] = u;
            DFSVisit(v);
        }
    }

    color[u] = BLACK;
    finish_time[u] = ++time;
}

void DFS() {
    for (int u = 0; u < n; u++) {
        color[u] = WHITE;
        parent[u] = -1;
    }

    time = 0;
    for (int u = 0; u < n; u++) {
        if (color[u] == WHITE) {
            DFSVisit(u);
        }
    }
}

int main() {
    int edges, u, v;

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
    }

    DFS();

    printf("Vertex\tDiscovery\tFinish\tParent\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t%d\n", i, discovery_time[i], finish_time[i], parent[i]);
    }

    return 0;
}
