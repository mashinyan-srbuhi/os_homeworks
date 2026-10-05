#include <stdio.h>
#include "math_utils.h"

#define PI 3.14159

int main(void) {
	int radius = 5;
	double area = PI * square(radius);
	printf("Area of a circle with radius %d is %.2f\n", 
			radius, area);


	return 0;
}
