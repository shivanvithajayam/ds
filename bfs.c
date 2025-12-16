#include <stdio.h>
#define MAX 20
void bfs(int a[MAX][MAX], int n, int src) {
    int visited[MAX] = {0};
    int q[MAX], front = 0, rear = 0;

    visited[src] = 1;
    q[rear++] = src;        
    printf("\nBFS Traversal: ");
    while (front < rear) {
        int u = q[front++]; 
        printf("%d ", u);   

        for (int v = 0; v < n; v++) {
            if (a[u][v] == 1 && !visited[v]) {
                visited[v] = 1;
                q[rear++] = v;  
            }
        }
    }
}
int main() {
    int n, a[MAX][MAX], src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);
    bfs(a, n, src);

    printf("\n");
    return 0;
}
