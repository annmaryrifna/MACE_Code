#include <stdio.h> 
#define MAX 100 
#define INF 999 
void primsAlgo(int graph[MAX][MAX], int n) 
 { 
    int i, j, u, v, mincost = 0; 
    int parent[MAX], key[MAX], mstSet[MAX]; 
    for (i = 0; i < n; i++) 
    { 
        key[i] = INF; 
        mstSet[i] = 0; 
    } 
    key[0] = 0; 
    parent[0] = -1; 
    for (int c = 0; c < n - 1; c++)  
    { 
        int minKey = INF, minIndex=-1; 
        for (v = 0; v < n; v++) 
       { 
            if (!mstSet[v] && key[v] < minKey) 
           { 
                minKey = key[v]; 
                minIndex = v; 
            } 
        } 
 
        u = minIndex; 
        mstSet[u] = 1; 
        for (v = 0; v < n; v++)  
       { 
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) 
           { 
                parent[v] = u; 
                key[v] = graph[u][v]; 
            } 
        } 
     } 
    printf("Edge\tWeight\n"); 
    for (i = 1; i < n; i++)  
    { 
        printf("%d - %d\t%d\n", parent[i] + 1, i + 1, graph[i][parent[i]]); 
        mincost += graph[i][parent[i]]; 
    } 
    printf("Minimum Cost = %d\n", mincost); 
} 
 
int main() 
 { 
    int graph[MAX][MAX], n, i, j; 
    printf("Enter the number of vertices: "); 
    scanf("%d", &n); 
    printf("Enter the adjacency matrix”); 
    for (i = 0; i < n; i++)  
    { 
        for (j = 0; j < n; j++)  
        { 
            scanf("%d", &graph[i][j]); 
        } 
    } 
    primsAlgo(graph, n); 
    return 0; 
} 
 
