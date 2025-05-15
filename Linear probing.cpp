#include <stdio.h>
#include <time.h>
#define TABLE_SIZE 100003 // Large prime number for better distribution
#define DATA_SIZE 50000 // Large dataset size

int hashTable[TABLE_SIZE];

// Initialize hash table
void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = -1;
}

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert using Linear Probing
void insert(int key) {
    int index = hashFunction(key);
    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE; // Move to next slot
    }
    hashTable[index] = key;
}

// Search for a key
int search(int key) {
    int index = hashFunction(key);
    while (hashTable[index] != -1) {
        if (hashTable[index] == key)
            return 1; // Key found
        index = (index + 1) % TABLE_SIZE;
    }
    return 0; // Key not found
}

int main() {
    initTable();
    clock_t start, end;
    
    // Insert elements and measure time
    start = clock();
    for (int i = 0; i < DATA_SIZE; i++) {
        insert(i);
    }
    end = clock();
    double insert_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Search elements and measure time
    int found = 0;
    start = clock();
    for (int i = 0; i < DATA_SIZE; i++) {
        found += search(i);
    }
    end = clock();
    double search_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Inserted %d elements in %.5f seconds.\n", DATA_SIZE, insert_time);
    printf("Found %d elements in %.5f seconds.\n", found, search_time);
    
    return 0;
}

