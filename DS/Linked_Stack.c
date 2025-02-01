#include <stdio.h> 
#include <stdlib.h> 
 
struct node { 
    int data; 
    struct node *next; 
}; 
 
struct node *temp, *top = NULL; 
 
void insertion(); 
void deletion(); 
void display(); 
int countNodes(); 
int findMax(); 
int findMin(); 
 
void insertion() { 
    struct node* ptr = (struct node*)malloc(sizeof(struct node)); 
    int item; 
    printf("Enter the item: "); 
    scanf("%d", &item); 
    ptr->data = item; 
    ptr->next = top; 
    top = ptr; 
    printf("%d inserted\n", item); 
} 
 
void deletion() { 
    if (top == NULL) 
        printf("Stack empty\n"); 
    else { 
        temp = top; 
        top = top->next; 
        printf("%d is deleted\n", temp->data); 
        free(temp); 
    } 
} 
 
void display() { 
    if (top == NULL) { 
        printf("Stack empty\n"); 
    } else { 
        temp = top; 
        while (temp != NULL) { 
            printf("%d -> ", temp->data); 
            temp = temp->next; 
        } 
        printf("NULL\n"); 
    } 
} 
 
// Function to count nodes in the stack 
int countNodes() { 
    int count = 0; 
    temp = top; 
    while (temp != NULL) { 
        count++; 
        temp = temp->next; 
    } 
    return count; 
} 
 
// Function to find the maximum element in the stack 
int findMax() { 
    if (top == NULL) { 
        printf("Stack is empty\n"); 
        return -1;  // or any indication of an empty stack 
    } 
    int max = top->data; 
    temp = top->next; 
    while (temp != NULL) { 
        if (temp->data > max) 
            max = temp->data; 
        temp = temp->next; 
    } 
    return max; 
} 
 
// Function to find the minimum element in the stack 
int findMin() { 
    if (top == NULL) { 
        printf("Stack is empty\n"); 
        return -1;  // or any indication of an empty stack 
    } 
    int min = top->data; 
    temp = top->next; 
    while (temp != NULL) { 
        if (temp->data < min) 
            min = temp->data; 
        temp = temp->next; 
    } 
    return min; 
} 
 
void main() { 
    int ch; 
    while (1) { 
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Count Nodes\n5. Find 
Max\n6. Find Min\n7. Exit\n"); 
        printf("Enter choice: "); 
        scanf("%d", &ch); 
        switch (ch) { 
            case 1: 
                insertion(); 
                break; 
            case 2: 
                deletion(); 
                break; 
            case 3: 
                display(); 
                break; 
            case 4: 
                printf("Node count: %d\n", countNodes()); 
                break; 
            case 5: 
                printf("Max value: %d\n", findMax()); 
                break; 
            case 6: 
                printf("Min value: %d\n", findMin()); 
                break; 
            case 7: 
                exit(0); 
            default: 
                printf("Wrong choice\n"); 
        } 
    } 
} 
