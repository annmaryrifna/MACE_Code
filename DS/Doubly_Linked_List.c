#include <stdio.h> 
#include <stdlib.h> 
 
struct node { 
    int data; 
    struct node *prev; 
    struct node *next; 
}; 
 
struct node *start = NULL;  // Start of the doubly linked list 
 
// Function to create a new node 
struct node* createNode(int x) { 
    struct node* ptr = (struct node*)malloc(sizeof(struct node)); 
    if (ptr == NULL) { 
        printf("\nOverflow\n"); 
        return NULL; 
    } 
    ptr->data = x; 
    ptr->prev = NULL; 
    ptr->next = NULL; 
    return ptr; 
} 
 
// Function to insert at the beginning of the list 
void beginsert() { 
    int x; 
    struct node* ptr; 
    printf("\nEnter value: "); 
    scanf("%d", &x); 
    ptr = createNode(x);  // Create a new node 
     
    if (ptr == NULL) return;  // Check if node creation failed 
     
    if (start == NULL) { 
        start = ptr;  // If list is empty, point start to the new node 
    } else { 
        ptr->next = start; 
        start->prev = ptr; 
        start = ptr; 
    } 
    printf("\n%d inserted at the beginning\n", x); 
} 
 
// Function to insert at the last of the list 
void lastinsert() { 
    int x; 
    struct node *ptr, *temp; 
    printf("\nEnter value: "); 
    scanf("%d", &x); 
    ptr = createNode(x);  // Create a new node 
     
    if (ptr == NULL) return;  // Check if node creation failed 
     
    if (start == NULL) { 
        start = ptr;  // If list is empty, point start to the new node 
    } else { 
        temp = start; 
        while (temp->next != NULL) { 
            temp = temp->next; 
        } 
        temp->next = ptr; 
        ptr->prev = temp; 
    } 
    printf("\n%d inserted at the last\n", x); 
} 
 
// Function to insert at a specific position in the list 
void posinsert() { 
    int pos, i, x; 
    struct node *ptr, *temp; 
    printf("\nEnter value: "); 
    scanf("%d", &x); 
    ptr = createNode(x);  // Create a new node 
     
    if (ptr == NULL) return;  // Check if node creation failed 
     
    printf("\nEnter position: "); 
    scanf("%d", &pos); 
     
    if (pos == 1) { 
        // Insert at the beginning 
        if (start == NULL) { 
            start = ptr; 
        } else { 
            ptr->next = start; 
            start->prev = ptr; 
            start = ptr; 
        } 
    } else { 
        temp = start; 
        for (i = 1; i < pos - 1 && temp != NULL; i++) { 
            temp = temp->next; 
        } 
        if (temp == NULL) { 
            printf("\nPosition out of bounds\n"); 
        } else { 
            ptr->next = temp->next; 
            ptr->prev = temp; 
            if (temp->next != NULL) { 
                temp->next->prev = ptr; 
            } 
            temp->next = ptr; 
        } 
    } 
    printf("\n%d inserted at position %d\n", x, pos); 
} 
 
// Function to delete from the beginning of the list 
void begdel() { 
    int x; 
    struct node *ptr; 
    if (start == NULL) { 
        printf("\nList is empty\n"); 
    } else { 
        ptr = start; 
        start = ptr->next; 
        if (start != NULL) { 
            start->prev = NULL; 
        } 
        x = ptr->data; 
        free(ptr); 
        printf("\n%d deleted from the beginning\n", x); 
    } 
} 
 
// Function to delete from the last of the list 
void lastdel() { 
    int x; 
    struct node *ptr, *temp; 
    if (start == NULL) { 
        printf("\nList is empty\n"); 
    } else { 
        temp = start; 
        while (temp->next != NULL) { 
            temp = temp->next; 
        } 
        x = temp->data; 
        if (temp->prev != NULL) { 
            temp->prev->next = NULL; 
        } else { 
            start = NULL;  // If only one node exists 
        } 
        free(temp); 
        printf("\n%d deleted from the last\n", x); 
    } 
} 
 
// Function to delete from a specific position in the list 
void posdel() { 
    struct node *ptr, *ptr1; 
    int pos, i, x; 
    if (start == NULL) { 
        printf("\nList is empty\n"); 
        return; 
    } 
    printf("\nEnter position: "); 
    scanf("%d", &pos); 
     
    ptr = start; 
    if (pos == 1) { 
        // Delete from the beginning 
        start = ptr->next; 
        if (start != NULL) { 
            start->prev = NULL; 
        } 
        x = ptr->data; 
        free(ptr); 
        printf("\n%d deleted from position %d\n", x, pos); 
    } else { 
        for (i = 1; i < pos && ptr != NULL; i++) { 
            ptr1 = ptr; 
            ptr = ptr->next; 
        } 
        if (ptr == NULL) { 
            printf("\nPosition out of bounds\n"); 
        } else { 
            ptr1->next = ptr->next; 
            if (ptr->next != NULL) { 
                ptr->next->prev = ptr1; 
            } 
            x = ptr->data; 
            free(ptr); 
            printf("\n%d deleted from position %d\n", x, pos); 
        } 
    } 
} 
 
// Function to search for an element in the list 
void search() { 
    struct node *ptr; 
    int x, i = 1, found = 0; 
    if (start == NULL) { 
        printf("\nList is empty\n"); 
        return; 
    } 
    printf("\nEnter element to search: "); 
    scanf("%d", &x); 
     
    ptr = start; 
    while (ptr != NULL) { 
        if (ptr->data == x) { 
            printf("\nItem found at position %d\n", i); 
            found = 1; 
            break; 
        } 
        i++; 
        ptr = ptr->next; 
    } 
    if (!found) { 
        printf("\nItem not found\n"); 
    } 
} 
 
// Function to count the number of elements in the list 
int countElements() { 
    int count = 0; 
    struct node* temp = start; 
    while (temp != NULL) { 
        count++; 
        temp = temp->next; 
    } 
    return count; 
} 
 
// Function to find the maximum value in the list 
int findMax() { 
    if (start == NULL) { 
        printf("\nList is empty\n"); 
        return -1;  // Return -1 if the list is empty 
    } 
 
    struct node* temp = start; 
    int max = temp->data; 
    temp = temp->next; 
 
    while (temp != NULL) { 
        if (temp->data > max) { 
            max = temp->data; 
        } 
        temp = temp->next; 
    } 
 
    return max; 
} 
 
// Function to display the list 
void display() { 
    struct node* temp = start; 
    if (temp == NULL) { 
        printf("\nList is empty\n"); 
        return; 
    } 
 
    while (temp != NULL) { 
        printf("%d <-> ", temp->data); 
        temp = temp->next; 
    } 
    printf("NULL\n"); 
} 
 
void main() { 
    int ch; 
    while (1) { 
        printf("\nMenu:\n"); 
        printf("1. Insert at beginning\n"); 
        printf("2. Insert at last\n"); 
        printf("3. Insert at position\n"); 
        printf("4. Delete from beginning\n"); 
        printf("5. Delete from last\n"); 
        printf("6. Delete from position\n"); 
        printf("7. Search\n"); 
        printf("8. Display\n"); 
        printf("9. Count elements\n"); 
        printf("10. Find max value\n"); 
        printf("11. Exit\n"); 
        printf("\nEnter your choice: "); 
        scanf("%d", &ch); 
 
        switch (ch) { 
            case 1: 
                beginsert(); 
                break; 
            case 2: 
                lastinsert(); 
                break; 
            case 3: 
                posinsert(); 
                break; 
            case 4: 
                begdel(); 
                break; 
            case 5: 
                lastdel(); 
                break; 
            case 6: 
                posdel(); 
                break; 
            case 7: 
                search(); 
                break; 
            case 8: 
                display(); 
                break; 
            case 9: 
                printf("\nNumber of elements: %d\n", countElements()); 
                break; 
            case 10: 
                printf("\nMax value: %d\n", findMax()); 
                break; 
            case 11: 
                exit(0); 
                break; 
            default: 
                printf("\nInvalid choice\n"); 
        } 
    } 
}
