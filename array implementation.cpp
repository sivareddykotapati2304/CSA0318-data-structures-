#include <stdio.h>

#define SIZE 100

int arr[SIZE];
int n = 0; // current size of the array

// Insert at given position
void insert(int value, int pos) {
    if (n >= SIZE) {
        printf("Array is full!\n");
        return;
    }
    if (pos < 0 || pos > n) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    n++;
    printf("Inserted %d at position %d\n", value, pos);
}

// Delete element at given position
void deleteElement(int pos) {
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }
    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return;
    }

    int deleted = arr[pos];
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    printf("Deleted element %d from position %d\n", deleted, pos);
}

// Display the array
void display() {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function with a simple menu
int main() {
    int choice, value, pos;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insert(value, pos);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteElement(pos);
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}

