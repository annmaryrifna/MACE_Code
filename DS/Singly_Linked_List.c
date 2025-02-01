#include <stdio.h> 
#include <stdlib.h> 
struct node { 
    int data; 
    struct node *next; 
}; 
struct node *start = NULL; 
 
// Function to create a new node with data 
struct node* createNode(int item) { 
    struct node *newNode = (struct node *)malloc(sizeof(struct node)); 
    if (newNode == NULL) { 
        printf("\nOverflow"); 
        return NULL; 
    } 
    newNode->data = item; 
    newNode->next = NULL; 
    return newNode; 
} 
 
void beginsert() { 
    int item; 
    printf("\nEnter value: "); 
    scanf("%d", &item); 
 
    struct node *newNode = createNode(item); 
    if (newNode == NULL) return; 
 
    newNode->next = start; 
    start = newNode; 
} 
 
// Function to insert at the end 
void lastinsert() { 
    int item; 
    struct node* temp; 
    printf("\nEnter value: "); 
    scanf("%d", &item); 
    struct node *newNode = createNode(item); 
    if (newNode == NULL) return; 
 
    if (start == NULL) { 
        start = newNode; 
    } else 
     { 
        temp = start; 
        while (temp->next != NULL)  
        { 
            temp = temp->next; 
        } 
        temp->next = newNode; 
    } 
} 
 
// Function to insert at a given position 
void posinsert() { 
    int pos, i, item; 
    printf("\nEnter value: "); 
    scanf("%d", &item); 
    printf("\nEnter the position: "); 
    scanf("%d", &pos); 
 
    struct node *newNode = createNode(item); 
    if (newNode == NULL) return; 
 
    if (pos == 1) { 
        newNode->next = start; 
        start = newNode; 
    } else { 
        struct node *temp = start; 
        for (i = 2; i < pos; i++) { 
            if (temp == NULL) { 
                printf("\nCan't insert"); 
                return; 
            } 
            temp = temp->next; 
        } 
        newNode->next = temp->next; 
        temp->next = newNode; 
    } 
} 
 
// Function to delete from the beginning 
void begdel() { 
    if (start == NULL) { 
        printf("\nList is empty"); 
    } else { 
        struct node *newNode = start; 
        start = newNode->next; 
        printf("\n%d deleted", newNode->data); 
        free(newNode); 
    } 
} 
 
// Function to delete from the end 
void lastdel() { 
    if (start == NULL) { 
        printf("\nList is empty"); 
    } else if (start->next == NULL) { 
        printf("\n%d deleted", start->data); 
        free(start); 
        start = NULL; 
    } else { 
        struct node *newNode = start; 
        struct node *newNode1 = NULL; 
        while (newNode->next != NULL) { 
            newNode1 = newNode; 
            newNode = newNode->next; 
        } 
        newNode1->next = NULL; 
        printf("\n%d deleted", newNode->data); 
        free(newNode); 
    } 
} 
 
// Function to delete from a given position 
void posdel() { 
    int pos, i; 
    printf("\nEnter position: "); 
    scanf("%d", &pos); 
 
    if (start == NULL) { 
        printf("\nList is empty"); 
    } else if (pos == 1) { 
        struct node *newNode = start; 
        start = newNode->next; 
        printf("\n%d deleted", newNode->data); 
        free(newNode); 
    } else { 
        struct node *newNode = start; 
        struct node *newNode1 = NULL; 
        for (i = 1; i < pos; i++) { 
            newNode1 = newNode; 
            newNode = newNode->next; 
            if (newNode == NULL) { 
                printf("\nCan't delete"); 
                return; 
            } 
        } 
        newNode1->next = newNode->next; 
        printf("\n%d deleted", newNode->data); 
        free(newNode); 
    } 
} 
 
// Function to display the linked list 
void display() { 
    struct node *newNode = start; 
    if (newNode == NULL) { 
        printf("\nList is empty"); 
    } else  
    { 
        while (newNode != NULL)  
        { 
            printf("%d -> ", newNode->data); 
            newNode = newNode->next; 
        } 
        printf("NULL\n"); 
    } 
} 
 
// Function to count the elements in the linked list 
int count() { 
    int count = 0; 
    struct node *newNode = start; 
    while (newNode != NULL) { 
        count++; 
        newNode = newNode->next; 
    } 
    return count; 
} 
 
// Function to find the maitemimum element in the linked list 
int findMaxitem()  
{ 
    if (start == NULL) { 
        printf("\nList is empty"); 
        return -1; // or any indication of an empty list 
    } 
    int maxitem = start->data; 
    struct node *newNode = start->next; 
    while (newNode != NULL)  
    { 
        if (newNode->data > maxitem) 
        { 
            maxitem = newNode->data; 
        } 
        newNode = newNode->next; 
    } 
    return maxitem; 
} 
 
void main() { 
    int ch; 
    while (1)  
    { 
        printf("\n\n1: Insert at beginning"); 
        printf("\n2: Insert at end"); 
        printf("\n3: Insert at position"); 
        printf("\n4: Delete from beginning"); 
        printf("\n5: Delete from end"); 
        printf("\n6: Delete from position"); 
        printf("\n8: Display"); 
        printf("\n9: Count elements"); 
        printf("\n10: Find maxitem element"); 
        printf("\nEnter your choice: "); 
        scanf("%d", &ch); 
 
        switch (ch) 
         { 
            case 1: beginsert(); break; 
            case 2: lastinsert(); break; 
            case 3: posinsert(); break; 
            case 4: begdel(); break; 
            case 5: lastdel(); break; 
            case 6: posdel(); break; 
            case 8: display(); break; 
            case 9: printf("\nCount: %d", count()); break; 
            case 10: printf("\nMaitem element: %d", findMaxitem()); break; 
            default: printf("\nInvalid choice"); 
        } 
    } 
}
