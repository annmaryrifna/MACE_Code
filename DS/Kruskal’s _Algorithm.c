#include <stdio.h> 
#define MAX 20  
int n, i, j, cost[MAX][MAX], u, v, parent[MAX], ne = 1, min, mincost = 0; 
 
// Function to find the root of a node 
int find(int i)  
{ 
    while (parent[i]) 
        i = parent[i]; 
    return i; 
} 
 
// Function to union two subsets 
int uni(int i, int j) 
 { 
    if (i != j)  
    { 
        parent[j] = i; 
        return 1; 
    } 
    return 0; 
} 
 
int main()  
{ 
    printf("Enter number of vertices: "); 
    scanf("%d", &n); 
 
    printf("Enter the cost adjacency matrix:\n"); 
    for (i = 1; i <= n; i++) 
     { 
        for (j = 1; j <= n; j++)  
        { 
            scanf("%d", &cost[i][j]); 
            if (cost[i][j] == 0) 
                cost[i][j] = 999; 
        } 
    } 
    for (i = 1; i <= n; i++) 
     { 
        parent[i] = 0; 
     } 
    printf("Edges in the Minimum Spanning Tree are:\n"); 
    while (ne < n)  
    { 
        min = 999; 
        for (i = 1; i <= n; i++)  
        { 
            for (j = 1; j <= n; j++)  
            { 
                if (cost[i][j] < min) 
                 { 
                    min = cost[i][j]; 
                    u = i; 
                    v = j; 
                } 
            } 
        } 
        int root_u = find(u); 
        int root_v = find(v); 
        if (uni(root_u, root_v))  
        { 
            printf(“edge is (%d, %d) = %d\n", u, v, min); 
            mincost += min; 
        }  
        cost[u][v] = cost[v][u] = 999; 
    } 
 
    printf("Minimum cost of the spanning tree is %d\n", mincost); 
    return 0; 
}
