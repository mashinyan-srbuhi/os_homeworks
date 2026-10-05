#include <stdio.h>

int main() {
    
    int num = 10;
    int *p = &num;
    int **p2 = &p;

    printf("Value of num (using pointer): %d\n", *p);
    printf("Value of num (using double-pointer): %d\n", **p2);
    
    return 0;
}
