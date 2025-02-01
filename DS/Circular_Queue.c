#include <stdio.h> 
#include <stdlib.h>  
int front = -1, rear = -1, cq[20], item, n = 5; 
 
void insert() { 
    int item; 
    if ((front == 0 && rear == n - 1) || (rear == (front - 1) % (n - 1))) { 
        printf("Overflow\n"); 
    } else { 
        printf("Enter the item: "); 
        scanf("%d", &item); 
        if (front == -1) {   
            front = rear = 0; 
        } else if (rear == n - 1 && front != 0) { 
            rear = 0; 
        } else { 
            rear = (rear + 1) % n; 
        } 
        cq[rear] = item; 
        printf("%d inserted\n", item); 
    } 
} 
 
void deletion() { 
    if (front == -1) { 
        printf("Underflow\n"); 
    } else { 
        item = cq[front]; 
        printf("%d is deleted\n", item); 
        if (front == rear) {  
            front = rear = -1; 
        } else if (front == n - 1) { 
            front = 0;  
        } else { 
            front++; 
        } 
    } 
} 
 
void display() { 
    int i; 
    if (front == -1) { 
        printf("Queue is empty\n"); 
    } else { 
        printf("Queue elements are: "); 
        if (front <= rear) { 
            for (i = front; i <= rear; i++) 
                printf("%d ", cq[i]); 
        } else { 
            for (i = front; i < n; i++) 
                printf("%d ", cq[i]); 
            for (i = 0; i <= rear; i++) 
                printf("%d ", cq[i]); 
        } 
        printf("\nFront = %d\nRear = %d\n", front, rear); 
    } 
} 
 
int countElements() { 
    if (front == -1) return 0;  
    if (front <= rear) return rear - front + 1; 
    return (n - front) + (rear + 1); 
} 
int findMax()
{ 
    if (front == -1) 
    { 
        printf("Queue is empty\n"); 
        return -1;  
    } 
    int max = cq[front]; 
    if (front <= rear)
    { 
        for (int i = front; i <= rear; i++)
          { 
            if (cq[i] > max) max = cq[i]; 
        } 
    } 
    else
    { 
        for (int i = front; i < n; i++) 
        { 
            if (cq[i] > max) max = cq[i]; 
        } 
        for (int i = 0; i <= rear; i++)
          { 
            if (cq[i] > max) max = cq[i]; 
        } 
    } 
    return max; 
}
int findMin() { 
    if (front == -1) { 
        printf("Queue is empty\n"); 
        return -1; 
    } 
    int min = cq[front]; 
    if (front <= rear) { 
        for (int i = front; i <= rear; i++) { 
            if (cq[i] < min) min = cq[i]; 
        } 
    } else { 
        for (int i = front; i < n; i++) { 
            if (cq[i] < min) min = cq[i]; 
        } 
        for (int i = 0; i <= rear; i++) { 
            if (cq[i] < min) min = cq[i]; 
        } 
    } 
    return min; 
} 
int main() { 
    int ch; 
    while (1) { 
        printf("\nMENU\n1. Insertion\n2. Deletion\n3. Display\n4. Count 
Elements\n5. Find Max\n6. Find Min\n7. Exit\nEnter the choice: "); 
        scanf("%d", &ch); 
        switch (ch) { 
            case 1: 
                insert(); 
                break; 
            case 2: 
                deletion(); 
                break; 
            case 3: 
                display(); 
                break; 
            case 4: 
                printf("Count of elements: %d\n", countElements()); 
                break; 
            case 5: 
                printf("Max value: %d\n", findMax()); 
                break; 
            case 6: 
                printf("Min value: %d\n", findMin()); 
                break; 
            case 7: 
                exit(0); 
                break; 
            default: 
                printf("Invalid choice\n"); 
        } 
    } 
}
