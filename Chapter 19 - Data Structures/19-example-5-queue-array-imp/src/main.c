/**
 * @file main.c
 * @author Yusuf Savas
 * @brief Linear Queue implementation using arrays.
 * @version 0.1
 * @date 2022-09-15
 * 
 * @warning Note: If you queue items and dequeue them because that front moves
 *          you will not be able to add new items. You have to clean the entire 
 *          queue or add some mechanism. The best way to overcome this problem is 
 *          just by using a circular queue. Not a linear queue. 
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

#define MAX 50

void enqueue();
void dequeue();
void display();

int queue_array[MAX];
int rear = -1;
int front = -1;

int main(void)
{
    int choice;
    while (1)
    {
        printf("1.Insert element to queue.\n");
        printf("2.Delete element from queue.\n");
        printf("2.Delete element from queue.\n");
        printf("3.Display all elements of queue.\n");
        printf("4.Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
            break;
        default:
            printf("Wrong choice \n");
        }
    }
}

void enqueue()
{
    int add_item = 0;
    if (rear == MAX - 1)
        printf("Queue Overflow \n");
    else
    {
        if (front == -1)
        {
            front = 0; // make the front zero because indexes starts from the zero.
        }
        printf("Insert the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow \n");
    }
    else
    {
        printf("Element deleted from queue is: %d\n", queue_array[front]);
        front++;
    }
}

void display()
{
    int i;
    if (front == -1)
    {
        printf("Queue is empty.");
    }
    else
    {
        printf("Queue is: \n");
        for (i = front; i <= rear; i++)
        {
            printf("%d", queue_array[i]);
        }
        printf("\n");
    }
}
