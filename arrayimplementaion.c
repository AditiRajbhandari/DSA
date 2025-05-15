#include <stdio.h>
#define MAX_SIZE 100 
int list[MAX_SIZE];
int size = 0;

void insert(int index, int value) {
    if (index < 0 || index > size || size >= MAX_SIZE) {
        printf("Invalid index or list is full.\n");
        return;
    }

    for (int i = size; i > index; i--) {
        list[i] = list[i - 1];
    }

    list[index] = value;
    size++; 
}

int main() {
    list[0] = 10;
    list[1] = 20;
    list[2] = 30;
    size = 3; 

    printf("Original list: ");
    insert(-1, 15);  
    printf("List after inserting 15 at index 1: ");

    insert(0, 5);   
    printf("List after inserting 5 at index 0: ");

    return 0;
}
