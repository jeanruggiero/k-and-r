#include <stdio.h>

/* This function raises the base to the integer power n and returns the result. */
double power(double base, int n) {

	int i;
	int result = 1;

	for (i = 0; i < n; i++) {
		result *= base;
	}

	return result;
}

int main() {
	
	int i;

	/* Print powers of 2 for n = 0 through n = 10. */
	for (i = 0; i < 10; i++) {
		printf("2^%d = %f\n", i, power(2, i));
	}
}
