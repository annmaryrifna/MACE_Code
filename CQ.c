#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int front = -1, rear = -1, cq[20], item, n = 5;
void insert()
{
    int item;
    if ((front == 0) && (rear == n - 1))
    {
        printf("Overflow");
    }
    else
    {
        printf("enter the item:");
        scanf("%d", &item);
        if (rear == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else if ((rear == n - 1) && (front != 0))
            rear = 0;
        else
            rear = (rear + 1) % n;
        cq[rear] = item;
    }
}
void deletion()
{
    if ((front == -1) && (rear == -1))
    {
        printf("underflow");
    }
    else
    {
        item = cq[front];
        printf("%d is deleted", item);
        if (front == rear)
            front = rear = -1;
        else
        {
            if (front == n - 1)
                front = 0;
            else
                front = front + 1;
        }
    }
}
void display()
{
    int i;
    printf("Front = %d\nRear = %d\n", front, rear);
    if (front == -1)
        printf("\nQueue is empty");
    else if (front <= rear)
    {
        for (i = front; i <= rear; i++)
            printf("%d ", cq[i]);
    }
    else
    {
        for (i = front; i < n; i++)
            printf("%d ", cq[i]);
        for (i = 0; i <= rear; i++)
            printf("%d", cq[i]);
    }
}

int main()
{
    int ch;
    clrscr();
    while (1)
    {
        printf("\nMENU\n1.1 Insertion \n 2.Deletion\n 3 Display \n 4.Exit \n Enter the choice:");
        scanf("%d", &ch);
        switch (ch)
        {
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
            exit(0);
            break;
        default:
            printf("invalid choice");
        }
    }
}