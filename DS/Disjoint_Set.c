#include <stdio.h> 
#include <stdlib.h> 
#define MAX 100  
 
int parent[MAX]; 
int rank[MAX]; 
void makeSet(int n)  
{ 
    for (int i = 0; i < n; i++) 
     { 
        parent[i] = i;  
        rank[i] = 0;    
    } 
} 
int find(int x)  
{ 
    if (parent[x] != x)  
    { 
        parent[x] = find(parent[x]);  
    } 
    return parent[x]; 
} 
void unionSets(int x, int y) 
 { 
    int rootX = find(x); 
    int rootY = find(y); 
 
    if (rootX != rootY)  
    { 
        if (rank[rootX] > rank[rootY]) 
         { 
            parent[rootY] = rootX; 
         }  
         else if (rank[rootX] < rank[rootY])  
         { 
            parent[rootX] = rootY; 
         } 
       else  
        { 
            parent[rootY] = rootX; 
            rank[rootX]++; 
        } 
        printf("Union of %d and %d performed.\n", x, y); 
    }  
 
 
    else 
     { 
        printf("%d and %d are already in the same set.\n", x, y); 
    } 
} 
void checkDisjoint(int x, int y) 
 { 
    if (find(x) == find(y)) 
     { 
        printf("Elements %d and %d are in same sets.\n", x, y); 
    }  
    else 
     { 
        printf("Elements %d and %d are in disjoint sets.\n", x, y); 
     } 
} 
int main()  
{ 
    int n, ch, x, y; 
    printf("Enter the number of elements: "); 
    scanf("%d", &n); 
    makeSet(n); 
    while (1)  
    { 
        printf("\nMenu:\n1. Find\n2. Union\n3. Check Disjoint\n4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &ch); 
        switch (ch)  
        { 
        case 1: 
            printf("Enter element to find its root: "); 
            scanf("%d", &x); 
            if (x >= 0 && x < n)  
            { 
                printf("Root of %d is %d.\n", x, find(x)); 
            }  
            else  
            { 
             printf("Invalid element! Enter a value between 0 and %d.\n", n - 1); 
            } 
            break; 
        case 2: 
            printf("Enter two elements to perform union: "); 
            scanf("%d %d", &x, &y); 
            if (x >= 0 && x < n && y >= 0 && y < n)  
 
 
            { 
                unionSets(x, y); 
            }  
             else 
             { 
             printf("Invalid elements! Enter values between 0 and %d.\n", n - 1); 
            } 
            break; 
        case 3: 
            printf("Enter two elements to check if their sets are disjoint: "); 
            scanf("%d %d", &x, &y); 
            if (x >= 0 && x < n && y >= 0 && y < n)  
            { 
                checkDisjoint(x, y); 
            }  
            else  
            { 
             printf("Invalid elements! Enter values between 0 and %d.\n", n - 1); 
            } 
            break; 
        case 4: 
            exit(0); 
            break; 
        default: 
            printf("Invalid choice! Please try again.\n"); 
        } 
    } 
 
    return 0; 
}
