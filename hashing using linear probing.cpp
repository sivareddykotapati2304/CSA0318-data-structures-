#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++) hashTable[i] = -1;
}

void insert(int key) {
    int i = key % SIZE;
    while (hashTable[i] != -1) i = (i + 1) % SIZE;
    hashTable[i] = key;
}

void display() {
    for (int i = 0; i < SIZE; i++)
        printf("%d -> %d\n", i, hashTable[i]);
}

int main() {
    init();
    insert(23);
    insert(43);
    insert(13);
    insert(27);
    insert(39);
    insert(10);

    display();
    return 0;
}

