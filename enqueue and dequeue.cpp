#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1)
        printf("Overflow\n");
    else {
        if (front == -1) front = 0;
        queue[++rear] = x;
        printf("%d enqueued\n", x);
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        printf("Underflow\n");
    else
        printf("%d dequeued\n", queue[front++]);
}

void display() {
    if (front == -1 || front > rear)
        printf("Empty\n");
    else {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, val;
    while (1) {
        printf("\n1.ENQUEUE 2.DEQUEUE 3.DISPLAY 4.EXIT\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: scanf("%d", &val); enqueue(val); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid\n");
        }
    }
}

