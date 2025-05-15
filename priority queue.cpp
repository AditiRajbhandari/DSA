#include <stdio.h>
#define MAXSIZE 5

typedef struct {
    int data;
    int priority;
} Element;

Element queue[MAXSIZE];
int rear = -1;
int front = -1;

// Function to check if the queue is empty
int isempty() {
    return front == -1 || front > rear;
}

// Function to check if the queue is full
int isfull() {
    return rear == MAXSIZE - 1;
}

// Function to enqueue data into the queue with priority
void enqueue() {
    if (isfull()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    int data, priority;
    printf("Enter the data to enqueue: ");
    scanf("%d", &data);
    printf("Enter the priority (higher number means higher priority): ");
    scanf("%d", &priority);

    // Insert data with priority
    if (isempty()) {
        front = 0;
        queue[++rear].data = data;
        queue[rear].priority = priority;
        printf("Data Enqueued: %d with priority %d\n", data, priority);
    } else {
        int i = rear;
        while (i >= front && queue[i].priority < priority) {
            queue[i + 1] = queue[i]; // Shift elements down to make room
            i--;
        }
        queue[i + 1].data = data;
        queue[i + 1].priority = priority;
        rear++;
        printf("Data Enqueued: %d with priority %d\n", data, priority);
    }
}

// Function to dequeue data from the queue based on priority
void dequeue() {
    if (isempty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    int data = queue[front].data;
    int priority = queue[front].priority;
    front++;

    // Reset front and rear if the queue is empty after dequeue
    if (front > rear) {
        front = rear = -1;
    }

    printf("Dequeued element: %d with priority %d\n", data, priority);
}

// Function to peek at the front element of the queue
void peek() {
    if (isempty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front element: %d with priority %d\n", queue[front].data, queue[front].priority);
}

// Function to display the elements of the queue
void display() {
    if (isempty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements:\n");
    for (int i = front; i <= rear; i++) {
        printf("Data: %d, Priority: %d\n", queue[i].data, queue[i].priority);
    }
}

int main() {
    // Manually calling the functions without using a loop or switch case
    enqueue(); // Enqueue data with priority
    enqueue(); // Enqueue data with priority
    display(); // Display queue
    dequeue(); // Dequeue data based on priority
    peek();    // Peek front element
    dequeue(); // Dequeue data based on priority
    display(); // Display queue again

    return 0;
}

