#include <stdio.h>

int main() {
    int a[] = {10, 20, 30, 40, 50};
    int n = 5;
    int key, low = 0, high = n - 1, mid;

    printf("Enter element to search: ");
    scanf("%d", &key);

    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == key) {
            printf("Element found at position %d\n", mid + 1);
            return 0;
        }
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("Element not found\n");
}
