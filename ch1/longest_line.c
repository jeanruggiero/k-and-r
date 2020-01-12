#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1024

/* This program reads a series of lines of text from standard input
   and prints the longest one to standard output. */
int main() {
	
	size_t len;
	int i, max_length = 0;

	/* Assume the longest line will be less than 1024 charactrs. */
	char * line = NULL;
	char * longest_line = (char *) malloc(sizeof(char) * MAXLINE);

	do {
		len = 0;
		getline(&line, &len, stdin);

		if (len > max_length) {
			max_length = len;

			/* Copy contents of line into longest_line. */
			for (i = 0; line[i] != '\0'; i++) {
				longest_line[i] = line[i];
			}
		}

	/* Return from the loop when the line is zero characters long, which
	   indicates the end of the file/buffer. getline() allocates one extra
	   byte to accomodate the null terminator, so len will be 1 when the
	   line length is zero. */

	} while (len > 1);

	printf("The longest line was: %s", longest_line);
}
