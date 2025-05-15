#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *left, *right;
};
struct node *list = NULL;
void insertnode(struct node *pred, int val)
{
    struct node *ins = (struct node *)malloc(sizeof(struct node));
    ins->info = val;
    ins->left = NULL;
    ins->right = NULL;
    if (pred == NULL)
    {
        ins->right = list;
        list = ins;
        struct node *succ = ins->right;
        if (succ != NULL)
            succ->left = ins;
    }
    else
    {
        ins->right = pred->right;
        pred->right = ins;
        struct node *succ = ins->right;
        if (succ != NULL)
            succ->left = ins;
        ins->left = pred;
    }
}
void deletenode(struct node *del)
{
    if (del == list)
    {
        struct node *succ = del->right;
        list = succ;
        if (succ != NULL)
            succ->left = NULL;
    }
    else
    {
        struct node *pred = del->left;
        pred->right = del->right;
        struct node *succ = del->right;
        if (succ != NULL)
            succ->left = pred;
    }
    free(del);
}
void display()
{
    struct node *temp = list;
    while (temp != NULL)
    {
        printf("%d\t", temp->info);
        temp = temp->right;
    }
}

int main()
{
    insertnode(NULL, 7);
    insertnode(list, 10);
    insertnode(list, 16);
    deletenode(list->right);
    display();
}
