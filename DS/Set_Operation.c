#include <stdio.h> 
#include <stdlib.h> 
  int main() 
 { 
    int u[20], a[20], b[20], n, i, j, item, found; 
     printf("Enter the size of the universal set: "); 
    scanf("%d", &n); 
    printf("Enter the elements of the universal set:\n"); 
    for (i = 0; i < n; i++) 
       { 
        scanf("%d", &u[i]); 
       } 
    for (i = 0; i < n; i++)  
        { 
        a[i] = 0;   
        b[i] = 0; 
        } 
    printf("Enter the elements of Set A (enter -1 to stop):\n"); 
    for (i = 0; i < n; i++)  
    { 
        while (1) 
        { 
            scanf("%d", &item); 
            if (item == -1) 
             { 
                break; 
             } 
            found = 0; 
            for (j = 0; j < n; j++)  
            { 
                if (u[j] == item) 
                  { 
                    found = 1; 
                    break; 
                  } 
            } 
            if (found) 
             { 
                a[j] = 1;  
                break;    
             }  
            else  
               {   
                printf("Error: Element %d is not in the universal set. Please re
enter.\n", item); 
              } 
        } 
        if (item == -1)  
        { 
            break; 
        } 
    } 
    printf("Enter the elements of Set B (enter -1 to stop):\n"); 
    for (i = 0; i < n; i++)  
    { 
        while (1) 
      { 
            scanf("%d", &item); 
            if (item == -1)  
              { 
                break; 
            } 
            found = 0; 
            for (j = 0; j < n; j++) 
           { 
                if (u[j] == item)  
            { 
                    found = 1; 
                    break; 
                } 
            } 
            if (found)  
            { 
                b[j] = 1;
                break;    
            } else { 
                printf("Error: Element %d is not in the universal set. Please re
enter.\n", item); 
            } 
        } 
        if (item == -1) { 
            break; 
        } 
    } 
    printf("\nUniversal Set:\t"); 
    for (i = 0; i < n; i++) { 
        printf("%d\t", u[i]); 
    } 
    printf("\nSet A: \t\t"); 
    for (i = 0; i < n; i++) { 
        printf("%d \t ", a[i]); 
    } 
    printf("\nSet B:\t \t "); 
    for (i = 0; i < n; i++) { 
        printf("%d \t", b[i]); 
    } 
 
    printf("\nSet A ∪ B: \t "); 
    for (i = 0; i < n; i++) { 
        printf("%d \t", a[i] | b[i]); 
    } 
 
    printf("\nSet A ∩ B: \t"); 
    for (i = 0; i < n; i++) { 
        printf("%d \t", a[i] & b[i]); 
    } 
 
    printf("\nSet A - B: \t"); 
    for (i = 0; i < n; i++) { 
        printf("%d \t", a[i] & ~b[i]); 
    } 
    return 0; 
} 
 
