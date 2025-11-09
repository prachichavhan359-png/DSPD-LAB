#include <stdio.h>

struct Edge {
    int u, v, weight;
};

int findParent(int parent[], int i) {
    if(parent[i] == i) return i;
    return findParent(parent, parent[i]);
}

void unionSets(int parent[], int x, int y) {
    int setX = findParent(parent, x);
    int setY = findParent(parent, y);
    parent[setY] = setX;
}

void sortEdges(struct Edge edges[], int e) {
    for(int i = 0; i < e-1; i++) {
        for(int j = 0; j < e-i-1; j++) {
            if(edges[j].weight > edges[j+1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);
    struct Edge edges[e];
    for(int i = 0; i < e; i++) scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    sortEdges(edges, e);
    int parent[n+1];
    for(int i = 1; i <= n; i++) parent[i] = i;
    int mstWeight = 0;
    for(int i = 0; i < e; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int setU = findParent(parent, u);
        int setV = findParent(parent, v);
        if(setU != setV) {
            printf("%d - %d : %d\n", u, v, edges[i].weight);
            mstWeight += edges[i].weight;
            unionSets(parent, setU, setV);
        }
    }
    printf("Total weight of MST: %d\n", mstWeight);
    return 0;
}
