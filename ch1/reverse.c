#include <stdio.h>

/* This function reverses a string. */
void reverse(char string[]) {
	int i, j;
	char temp;

	/* Determine the length of the string. */
	for (j = 0; string[j] != '\0'; j++) {
		;
	}
	j--;

	/* Reverse the string in place. */
	for (i = 0; i < j; i++, j--) {
		temp = string[i];
		string[i] = string[j];
		string[j] = temp;
	}
}

int main() {
	char string[] = "Here is a string.";

	reverse(string);

	printf("%s\n", string);
}
