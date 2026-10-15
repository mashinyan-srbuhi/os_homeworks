#include <stdio.h> 

struct task2_struct1 {
	char a;
	int b;
	double c;
};

struct task2_struct2 {
        double c;
	int b;
        char a;
};

int main() {
	struct task2_struct1 s1;
	struct task2_struct2 s2;

        printf("sizeof(char): %zu\n", sizeof(char));
        printf("sizeof(int): %zu\n", sizeof(int));
        printf("sizeof(double): %zu\n", sizeof(double));
        printf("\n");

	printf("Size of struct1: %lu bytes\n", sizeof(s1));
        printf("Address of char a: %p\n", &s1.a);
	printf("Address of int b: %p\n", &s1.b);
        printf("Address of double c: %p\n", &s1.c);
	printf("\n");

        printf("Size of struct2: %lu bytes\n", sizeof(s2));
        printf("Address of char a: %p\n", &s2.a);
        printf("Address of int b: %p\n", &s2.b);
        printf("Address of double c: %p\n", &s2.c);


	return 0;
}
