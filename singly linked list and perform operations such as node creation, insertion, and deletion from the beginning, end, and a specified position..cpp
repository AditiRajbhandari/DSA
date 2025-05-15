#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *list = NULL;

// Insert node at the beginning
void insertAtBeginning(int val) {
    struct node *ins = (struct node *)malloc(sizeof(struct node));
    ins->info = val;
    ins->next = list;
    list = ins;
}

// Insert node at the end
void insertAtEnd(int val) {
    struct node *ins = (struct node *)malloc(sizeof(struct node));
    ins->info = val;
    ins->next = NULL;
    if (list == NULL) {
        list = ins;
    } else {
        struct node *temp = list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ins;
    }
}

// Insert node at a specified position
void insertAtPosition(int pos, int val) {
    if (pos == 0) {
        insertAtBeginning(val);
        return;
    }
    struct node *ins = (struct node *)malloc(sizeof(struct node));
    ins->info = val;
    ins->next = NULL;
    struct node *temp = list;
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds!\n");
        free(ins);
        return;
    }
    ins->next = temp->next;
    temp->next = ins;
}

// Delete node from the beginning
void deleteFromBeginning() {
    if (list == NULL) return;
    struct node *temp = list;
    list = list->next;
    free(temp);
}

// Delete node from the end
void deleteFromEnd() {
    if (list == NULL) return;
    if (list->next == NULL) {
        free(list);
        list = NULL;
        return;
    }
    struct node *temp = list;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Delete node from a specified position
void deleteFromPosition(int pos) {
    if (list == NULL) return;
    if (pos == 0) {
        deleteFromBeginning();
        return;
    }
    struct node *temp = list, *prev = NULL;
    for (int i = 0; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Display the list
void display() {
    struct node *temp = list;
    while (temp != NULL) {
        printf("%d\t", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insertAtBeginning(7);
    insertAtEnd(10);
    insertAtEnd(16);
    insertAtPosition(1, 12);
    display();
    deleteFromBeginning();
    deleteFromEnd();
    deleteFromPosition(1);
    display();
       getchar();
    getchar();
    return 0;
}

