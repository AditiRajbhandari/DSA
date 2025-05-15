#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct node
{
    int info;
    struct node *next;
};

struct node *list = NULL;

void insertNode(int pos, struct node *pred, int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = val;
    newNode->next = NULL;

    if (pos == 0)  
    {
        newNode->next = list;
        list = newNode;
    }
    else if (pred != NULL)  
    {
        newNode->next = pred->next;
        pred->next = newNode;
    }
    else  
    {
        struct node *temp = list;
        int count = 0;
        while (temp != NULL && count < pos - 1)
        {
            temp = temp->next;
            count++;
        }
        if (temp == NULL)  
        {
            printf("Position out of bounds.\n");
            free(newNode);
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to delete a node at a specific position
void deletenodeatposition(int pos)
{
    if (list == NULL)  
    {
        printf("List is empty.\n");
        return;
    }

    if (pos == 0)  
    {
        struct node *temp = list;
        list = list->next;
        free(temp);
        return;
    }

    struct node *temp = list;
    struct node *prev = NULL;
    int count = 0;

    while (temp != NULL && count < pos)
    {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == NULL)  // Position is out of bounds
    {
        printf("Position out of bounds.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to display the linked list
void display()
{
    struct node *temp = list;
    while (temp != NULL)
    {
        printf("%d\t", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    // Insert nodes
    insertNode(0, NULL, 7);   // Insert 7 at the beginning
    insertNode(0, list, 10);  // Insert 10 after the first node
    insertNode(0, list, 16);  // Insert 16 after the second node

    printf("Original list: ");
    display();  // Display the original list

    // Delete the node at position 1 (which is '10')
    deletenodeatposition(1);

    printf("List after deletion at position 1: ");
    display();  // Display the list after deletion

    // Insert 12 at position 2
    insertNode(2, NULL, 12);
    printf("List after inserting 12 at position 2: ");
    display();  // Display the list after insertion at position 2

    // Delete node at position 3
    deletenodeatposition(3);
    printf("List after deleting node at position 3: ");
    display();

    return 0;
}

