#include <stdio.h>
#define MAXSIZE 5

int queue[MAXSIZE];
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

// Function to enqueue data into the queue
void enqueue() {
    if (isfull()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    int data;
    printf("Enter the data to enqueue: ");
    scanf("%d", &data);

    if (isempty()) {
        front = 0; // Initialize front for the first element
    }
    queue[++rear] = data;
    printf("Data Enqueued: %d\n", data);
}

// Function to dequeue data from the queue
void dequeue() {
    if (isempty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    int data = queue[front++];
    printf("Dequeued element: %d\n", data);

    // Reset front and rear if the queue is empty after dequeue
    if (front > rear) {
        front = rear = -1;
    }
}

// Function to peek at the front element of the queue
void peek() {
    if (isempty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}

// Function to display the elements of the queue
void display() {
    if (isempty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    // Manually calling the functions without using a loop or switch case
    enqueue(); // Enqueue data
    enqueue(); // Enqueue data
    display(); // Display queue
    dequeue(); // Dequeue data
    peek();    // Peek front element
    dequeue(); // Dequeue data
    display(); // Display queue again

    return 0;
}

