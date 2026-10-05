#include <stdio.h>
#include <stdlib.h> 

int main() {
	int n;
	int *arr;
	
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	
	if (n <= 0) {
		printf("Number of elements must be greater than 0.\n");
		return 1;
	}
	
	arr = (int *)malloc(n * sizeof(int));
	if (arr == NULL) {
		perror("Memory allocation failed!\n");
		return 1;
	}
	
	printf("Enter %d integers: ", n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	printf("Sum of the array: %d\n", sum);
	
	free(arr);
	arr = NULL;
	
	return 0;
}

