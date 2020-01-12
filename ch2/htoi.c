#include <stdio.h>

/* This function calculates base to the power n and returns it as an integer */
int power(int base, int n) {
	int result = 1;
	int i;

	for (i = 0; i < n; i++) {
		result *= base;
	}

	return result;
}

/* This function converts a string of hexadecimal digits with an optional 
 * leading 0x or 0X into its integer representation and returns an
 * intger. */
int htoi(char hex[]) {

	int i = 0, k = 0, j;
	int length, result = 0;

	for (length = 0; hex[length] != '\0'; length++) {
		;
	}


	/* If the first two characters are 0x or 0X, skip them in the
	 * second loop. */
	if ((length >= 2) && (hex[0] == '0')) {
		if ((hex[1] == 'x') || (hex[1] == 'X')) {
			i = 2;
		}
	}

	/* Compute integer representation. Supports uppercase or lower
	 * case letters. */
	for (j = length - 1; j >= i; j--, k++) {
	       if ((hex[j] >= '0') && (hex[j] <= '9')) {
		       result += (hex[j] - '0') * power(16, k);
		} else if ((hex[j] >= 'a') && (hex[j] <= 'f')) {
			result += (hex[j] - 'a' + 10) * power(16, k);
		} else if ((hex[j] >= 'A') && (hex[j] <= 'F')) {
			result += (hex[j] - 'A' + 10) * power(16, k);
		}
	}

	return result;
}

int main() {
	printf("ffff: %d\n", htoi("ffff"));
	printf("0xffff: %d\n", htoi("0xffff"));
	printf("0Xffff: %d\n", htoi("0Xffff"));
	printf("0ffff: %d\n", htoi("0ffff"));
	printf("FFFF: %d\n", htoi("FFFF"));
	printf("8: %d\n", htoi("8"));
	printf("A: %d\n", htoi("A"));
	printf("a: %d\n", htoi("a"));
}
