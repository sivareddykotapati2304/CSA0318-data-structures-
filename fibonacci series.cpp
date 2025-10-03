#include <stdio.h>

int main() {
    int n = 10, j;
    int a = 0, b = 1, c;

    if (n <= 0)
        return 0;
    else if (n == 1) {
        printf("%d\n", a);
        return 0;
    }

    printf("%d %d ", a, b);

    for (j = 2; j < n; j++) {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }

    printf("\n");
}
