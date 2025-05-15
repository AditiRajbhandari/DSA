#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void initStack(struct Stack* stack) {
    stack->top = NULL;
}

int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void push(struct Stack* stack, int data) {
    struct Node* ins = (struct Node*)malloc(sizeof(struct Node));
    if (ins == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    ins->data = data;
    ins->next = stack->top;
    stack->top = ins;
    printf("%d pushed to stack\n", data);
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    }
    struct Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return poppedValue;
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->top->data;
}

void printStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    struct Node* temp = stack->top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initStack(&stack);

    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    printStack(&stack);

    printf("%d popped from stack\n", pop(&stack));

    printStack(&stack);

    printf("Top element is %d\n", peek(&stack));

    return 0;
}

