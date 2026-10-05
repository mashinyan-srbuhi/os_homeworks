#include <stdio.h>

int main() {
    int num = 7;
    int *p = &num;

    printf("Value of num: %d\n", num);
    
    printf("Address of num (using variable): %p\n", &num); 
    printf("Address of num (using pointer): %p\n", p);

    *p = num + 20;
    printf("New value of num: %d\n", num);
    
    return 0;
}

