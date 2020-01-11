#include <stdio.h>

/* This program counts blanks in a file. */
int main() {

	int c;
	int blanks = 0;

	while ((c = getchar()) != EOF) {
		if ((c == ' ') || (c == '\n') || (c == '\t')) {
			blanks++;
		}
	}

	printf("There are %d blanks in this text.\n", blanks);
}
