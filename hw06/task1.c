#include <stdio.h>

int main() {
	
	int type_int = 10;
	char type_char = 'a';
	double type_double = 10.25;
	short type_short = 20;
	
	printf("sizeof(int): %zu\n", sizeof(int));
	printf("sizeof(char): %zu\n", sizeof(char));
	printf("sizeof(double): %zu\n", sizeof(double));
	printf("sizeof(short): %zu\n", sizeof(short)); 
	
	printf("\n");

	printf("address of type_int: %p\n", &type_int);
        printf("address of type_char: %p\n", &type_char);
        printf("address of type_double: %p\n", &type_double);
        printf("address of type_short: %p\n", &type_short);

	printf("\n");

        printf("&type_char - &type_int: %td\n",
               (char *)&type_char - (char *)&type_int);
        printf("&type_double - &type_char: %td\n",
               (char *)&type_double - (char *)&type_char);
        printf("&type_short - &type_double: %td\n",
               (char *)&type_short - (char *)&type_double);

	return 0;
}
