#include <stdio.h>
#include <stdlib.h>

int graph[10][10], visited[10];

void bfs(int start, int n) {
    int queue[20], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;
    while(front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        for(int i = 1; i <= n; i++) {
            if(graph[node][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void dfs(int node, int n) {
    printf("%d ", node);
    visited[node] = 1;
    for(int i = 1; i <= n; i++) {
        if(graph[node][i] && !visited[i]) dfs(i, n);
    }
}

int main() {
    int n, edges, u, v;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    for(int i = 0; i < edges; i++) {
        printf("Enter edge %d (u v): ", i+1);
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    for(int i = 1; i <= n; i++) visited[i] = 0;
    printf("BFS: ");
    bfs(1, n);

    for(int i = 1; i <= n; i++) visited[i] = 0;
    printf("DFS: ");
    dfs(1, n);
    printf("\n");

    return 0;
}
