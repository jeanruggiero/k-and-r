#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>


/* This function computes large integer exponentials using the long type. */
long power(int base, int n) {
	long result = 1;
	int i;

	for(i = 0; i < n; i++) {
		result *= base;
	}

	return result;
}

/* This program prints the sizes of all integral types, along with their
 * minimum and maximum values. */
int main() {
	printf("Type     Size (bits)        Max Value                 Min Value\n");
	printf("-----------------------------------------------------------------\n");
	printf("Int      %11lu  %25d  %25d\n", sizeof(int)*8, INT_MAX, INT_MIN);
	printf("Int      %11lu  %25.0f  %25.0f\n", sizeof(int)*8, 
			pow(2,sizeof(int)*8)/2 - 1, -pow(2, sizeof(int)*8)/2);

	printf("Char     %11lu  %25d  %25d\n", sizeof(char)*8, CHAR_MAX, CHAR_MIN);
	printf("Char     %11lu  %25.0f  %25.0f\n", sizeof(char)*8, 
			pow(2, sizeof(char)*8)/2 - 1, -pow(2, sizeof(char)*8)/2);


	

	printf("Long     %11lu  %25ld  %25ld\n", sizeof(long)*8, LONG_MAX, LONG_MIN);
	printf("Long     %11lu  %25ld  %25.0f\n", sizeof(long)*8,
			power(2, sizeof(long)*8-2) + (power(2, sizeof(long)*8-2) -1), -pow(2, sizeof(long)*8)/2);


	printf("Double   %11lu\n", sizeof(double)*8);
	printf("Float    %11lu\n", sizeof(float)*8);

}
