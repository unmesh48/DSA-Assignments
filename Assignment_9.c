#include <stdio.h>

#define MAX 5

struct Job {
    int id;
    char title[100];
};

struct Job q[MAX];
int front = -1, rear = -1;

void enqueue() {
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow! Print queue is full.\n");
        return;
    }

    struct Job j;
    printf("Enter Job ID and Document Title: ");
    scanf("%d %99s", &j.id, j.title);

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    q[rear] = j;

    printf("Print job added successfully.\n");
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow! No print jobs available.\n");
        return;
    }

    printf("Processing: %d %s\n", q[front].id, q[front].title);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display() {
    if (front == -1) {
        printf("No Pending Print Jobs.\n");
        return;
    }

    int i = front;

    while (1) {
        printf("%d %s\n", q[i].id, q[i].title);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
}

int main() {
    int ch;

    do {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: break;
            default: printf("Invalid choice.\n");
        }
    } while (ch != 4);

    return 0;
}