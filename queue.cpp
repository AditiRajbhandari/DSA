#include<stdio.h>
#include<stdlib.h>

int *queue; // Pointer to dynamically allocate memory for the queue
int front = 0, rear = -1, MAXSIZE;

int isempty() {
    if (rear == -1)
        return 1;
    else
        return 0;
}

int isfull() {
    if (rear == MAXSIZE - 1)
        return 1;
    else
        return 0;
}

void enqueue(int data) {
    if (isfull())
        printf("Queue is full.\n");
    else {
        rear++;
        queue[rear] = data;
        printf("Enqueued %d\n", data);
    }
}

void dequeue() {
    int data, i, temp = 0;
    if (isempty())
        printf("Queue is empty.\n");
    else {
        data = queue[front];
        for (i = front + 1; i <= rear; i++) {
            if (data > queue[i]) {
                temp = i;
                data = queue[i];
            }
        }
        for (i = temp; i < rear; i++) {
            queue[i] = queue[i + 1];
        }
        rear--;
        printf("Dequeued element: %d\n", data);
    }
}

void peek() {
    if (isempty())
        printf("Queue is empty.\n");
    else
        printf("Element at front: %d\n", queue[front]);
}

void display() {
    if (isempty())
        printf("Queue is empty.\n");
    else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d\t", queue[i]);
        printf("\n");
    }
}

int main() {
    // Get the max size of the queue from the user
    printf("Enter the maximum size of the queue: ");
    scanf("%d", &MAXSIZE);

    // Dynamically allocate memory for the queue based on the user input
    queue = (int *)malloc(MAXSIZE * sizeof(int));
    if (queue == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }

    int choice, data;

    // Menu for queue operations
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                free(queue); // Free allocated memory for the queue
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

