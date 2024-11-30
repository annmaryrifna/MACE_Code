#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

void primsAlgorithm(int graph[MAX][MAX], int n) 
{
    int parent[MAX]; // Array to store constructed MST
    int key[MAX];    // Key values used to pick minimum weight edge
    int mstSet[MAX]; // To represent the set of vertices included in MST
    int totalCost = 0; // Variable to store the total cost of the MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < n; i++)
     {
        key[i] = INF;
        mstSet[i] = 0;
    }

    // Start with the first vertex (arbitrary)
    key[0] = 0;     
    parent[0] = -1; // First node is always the root of the MST

    for (int count = 0; count < n - 1; count++)
     {
        // Find the minimum key value among the vertices not yet included in MST
        int minKey = INF, minIndex;
        for (int v = 0; v < n; v++) 
        {
            if (!mstSet[v] && key[v] < minKey) 
            {
                minKey = key[v];
                minIndex = v;
            }
        }

        // Include the selected vertex in the MST
        int u = minIndex;
        mstSet[u] = 1;

        // Update key values and parent index of the adjacent vertices
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) 
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Calculate the total cost and print the constructed MST
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++) 
    {
        printf("%d - %d \t%d\n", parent[i]+1, i+1, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }

    printf("Total cost of the Minimum Spanning Tree: %d\n", totalCost);
}

int main() {
    int n; // Number of vertices
    int graph[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use %d for infinity):\n", INF);
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    primsAlgorithm(graph, n);

    return 0;
}
