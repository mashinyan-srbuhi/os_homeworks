#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void function1(void) {
        printf("A long time ago\n");
}
void function2(void) {
	printf("In a galaxy far, far away...\n");
}

int main(void) {
	
	int func2 = atexit(function2);
	if (func2 != 0) {
		fprintf(stderr, "atexit(function2) failed\n");
	} 

	printf("Star Wars\n");

	int func1 = atexit(function1);
        if (func1 != 0) {
                fprintf(stderr, "atexit(function1) failed\n");
        }

	printf("Episode III\n");

	if (true) {
		printf("Revenge of the Sith\n");
		exit(0);
	}

	return 0;
}
