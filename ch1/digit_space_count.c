#include <stdio.h>

/* This program keeps track of the count of each digit, each whitespace character,
   and all other characters. */
int main() {

	int c, i;
	int digits[10];
	int blanks = 0, tabs = 0, newlines = 0, chars = 0;

	for (i = 0; i < 10; i++) {
		digits[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		switch (c) {
			case ' ':
				blanks++;
				break;
			case '\t':
				tabs++;
				break;
			case '\n':
				newlines++;
				break;
			case '0': case '1': case '2': case '3': case '4': 
			case '5': case '6': case '7': case '8': case '9':
				digits[c - '0']++;
				break;
			default: 
				chars++;
		}
	}	
	
	printf("There are %d blanks, %d tabs, and %d newlines.\n", blanks, tabs, newlines);
	printf("The number counts are:\n");
	for (i = 0; i < 10; i++) {
		printf("\t%d: %d\n", i, digits[i]);
	}

	printf("There are %d other characters.\n", chars);

}
