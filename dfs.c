#include <stdio.h>

void dfs(int n, int cost[10][10], int u, int visited[]) {
    int v;
    visited[u] = 1;   
    for (v = 0; v < n; v++) {
        if (cost[u][v] == 1 && visited[v] == 0) {
            dfs(n, cost, v, visited);
        }
    }
}
int main() {
    int n, i, j;
    int cost[10][10], visited[10];
    printf("Enter number of nodes (max 10): ");
    scanf("%d", &n);
    if (n <= 0 || n > 10) {
        printf("Invalid number of nodes\n");
        return 1;
    }
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    dfs(n, cost, 0, visited);
    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            printf("Graph is NOT connected\n");
            return 0;
        }
    }
    printf("Graph is CONNECTED\n");
    return 0;
}
