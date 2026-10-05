#include <stdio.h>
#include <stdlib.h>

int main() {

	char **arr_string;
	arr_string = (char **)malloc(3 * sizeof(char *));
	if (arr_string == NULL) {
		perror("Memory allocation 0 failed.");
		return 1;
	}

	for (int i = 0; i < 3; i++) {
		arr_string[i] = malloc(51 * sizeof(char));
		if (arr_string[i] == NULL) {
			perror("Memory allocation failed.");
			for (int j = 0; j < i; j++) {
				free(arr_string[j]);
			}
			free(arr_string);
			return 1;
		}
	}

	printf("Enter 3 strings: ");
	for (int i = 0; i < 3; i++) {
		scanf("%50s", arr_string[i]);
	}

	printf("Strings entered (for checking): ");
	for (int i = 0; i < 3; i++) {
		printf("%s ", arr_string[i]);	
	}
	printf("\n");

	char **temp = realloc(arr_string, 5 * sizeof(char *));
	if (temp == NULL) {
		perror("Memory reallocation failed.");
		for (int i = 0; i < 3; i++) {
			free(arr_string[i]);
		}
		free(arr_string);
		return 1;
	}
	arr_string = temp;

	for (int i = 3; i < 5; i++) {
		arr_string[i] = malloc(51 * sizeof(char));

		if (arr_string[i] == NULL) {
			perror("Memory allocation failed.");
			for (int j = 0; j < i; j++) {
				free(arr_string[j]);
			}
			free(arr_string);
			return 1;
		}
	}

	printf("Enter 2 more strings: ");
	for (int i = 3; i < 5; i++) {
		scanf("%50s", arr_string[i]);
	}

	printf("All strings: ");
	for (int i = 0; i < 5; i++) {
		printf("%s ", arr_string[i]);
	}
	printf("\n");

	for (int i = 0; i < 5; i++) {
		free(arr_string[i]);
	}

	free(arr_string);
	arr_string = NULL;

	return 0;
}
