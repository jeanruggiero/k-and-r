#include <stdio.h>

#define IN   1
#define OUT  0
int main() {


	int words = 0, lines = 0, chars = 0;
	int in_word = OUT;
	int c;

	while ((c = getchar()) != EOF) {
		chars++;
		if ((c == ' ') || (c == '\n') || (c == '\t'))  {
			if (in_word == IN) {
				in_word = OUT;
			}

			if (c == '\n') {
				lines++;
			}
		} else if (in_word == OUT) {
			words++;
			in_word = IN;
		}
	}

	printf("The word count is: %d\n", words);
	printf("The line count is: %d\n", lines);
	printf("The character count is: %d\n", chars);
}
