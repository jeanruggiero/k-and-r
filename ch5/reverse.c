#include <stdio.h>

/* This function recursively reverses a string in place. */
void reverse(char *string) {

	char first;
	char * substring;
	int i;

	if (string[0] == '\0') {
		return;
	}

	first = string[0];
	reverse(substring = &string[1]);

	/* Copy contents of the reversed substring into the start of the string. */
	for (i = 0; substring[i] != '\0'; i++) {
		string[i] = substring[i];
	}

	/* Add the first element onto the end of the reversed substring. */
	string[i] = first;
}

int main() {
	char string[] = "I'm a string, reverse me!";

	reverse(string);
	printf("%s\n", string);
}
