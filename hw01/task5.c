#include <stdio.h>
	
	int main() {
		char str[] = "Hello";
		char *p = str;
		for (int i = 0; i < 5; i++) {
			printf("%c", *p);
			p++;
		}
		printf("\n");
		
		char *str_start = str;
		char *str_end = str;
		while(*str_end != '\0') {
			str_end++;
		}
		int str_length = str_end - str_start;

		printf("str length: %d\n", str_length);

		return 0;
	}
