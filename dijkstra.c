#include<stdio.h>
#include<limits.h>
#define MAX 100
#define INF INT_MAX

int adj[MAX][MAX],distance[MAX], visited[MAX];
int n;

void dijkstra(int start) {
    for(int i=0;i<n;i++) {
        distance[i] = INF;
        visited[i] = 0;
    }    
    distance[start] = 0;
    for(int count = 0; count < n-1; count++) {
        int min = INF;
        int u = -1;
        for(int v = 0; v < n; v++) {
            if(!visited[v] && distance[v] <= min) {
                min = distance[v];
                u = v;
            }
        }
        if(u == -1) 
        break;
        visited[u] = 1;
        for(int v = 0; v < n; v++) {
            if(!visited[v] && adj[u][v] && distance[u] != INF) {
                int new_distance = distance[u] + adj[u][v];
                if(new_distance < distance[v]) {
                    distance[v] = new_distance;
                }
            }
        }
    }    
}

int main() {
    int edges, u, v, weight;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter edges (u v weight):\n");
    for(int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &weight);
        adj[u][v] = weight;
        adj[v][u] = weight; 
    }

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    dijkstra(start);

    printf("Vertex Distance from Source\n");
    for(int i = 0; i < n; i++) {
        printf("%d \t\t %d\n", i, distance[i]);
    }
    
    return 0;
}

