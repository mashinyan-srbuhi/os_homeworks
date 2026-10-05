#include <stdio.h>

int main() {
    int arr[5] = {5, 10, 15, 20, 25};
    int *a = arr;

    printf("Original array (using pointer):\n");
    for (int i = 0; i < 5; i++) {
        printf("Element %d: %d\n", i, *(a + i));
    }

    for (int i = 0; i < 5; i++) {
        *(a + i) = *(a + i) + 100;
    }

    printf("\nModified array (using pointer):\n");
    for (int i = 0; i < 5; i++) {
        printf("Element %d: %d\n", i, *(a + i));
    }

    printf("\nModified array (using array name):\n");
    for (int i = 0; i < 5; i++) {
        printf("Element %d: %d\n", i, arr[i]);
    }

    return 0;
}

