#include <stdio.h>
#include <stdlib.h>

int main() {

	int n = 0;
	printf("Enter the number of students: ");
	scanf("%d", &n);

	if (n <= 0) {
		printf("Number must be greater than 0.\n");
		return 1;
	}

	int *grades;
	grades = (int *)malloc(n * sizeof(int));
	if (grades == NULL) {
		perror("Memory allocation 0 failed.");
		return 1;
	}

	printf("Enter the grades: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &grades[i]);
		if (grades[i] < 0 || grades[i] > 100) {
			printf("The number must be between 0 and 100.\n");
			free(grades);
			return 1;
		}
	}


	int max = grades[0];
	int min = grades[0];
	for (int i = 0; i < n; i++) {
		if (grades[i] > max) { max = grades[i]; }
		if (grades[i] < min) { min = grades[i]; }
	}

	printf("Highest grade:%d\n", max);
	printf("Lowest grade:%d\n", min);
	
	free(grades);
	grades = NULL;

	return 0;
}
