#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};
struct node *list = NULL;

void insertnode(struct node *pred, int val)
{
    struct node *ins = (struct node *)malloc(sizeof(struct node));
    ins->info = val;
    ins->next = NULL;

    if (pred == NULL)
    {
        ins->next = list;
        list = ins;
    }
    else
    {
        ins->next = pred->next;
        pred->next = ins;
    }
}

void deletenode(struct node *del)
{
    if (del == list)
    {
        list = del->next;
        free(del);
    }
    else
    {
        struct node *pred = list;
        while (pred != NULL && pred->next != del)
        {
            pred = pred->next;
        }
        if (pred != NULL)
        {
            pred->next = del->next;
            free(del);
        }
    }
}

void display()
{
    struct node *temp = list;
    while (temp != NULL)
    {
        printf("%d\t", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    insertnode(NULL, 5);
    insertnode(list, 15);
    insertnode(list->next, 25);

    printf("After Insertion:\n");
    display();

    deletenode(list->next); // delete node with info 15
    printf("After Deletion:\n");
    display();

    return 0;
}

