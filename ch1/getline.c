#include <stdio.h>

#define MAXLINE 1024

/* This function gets one line of text from the input buffer. */
int getline_new(char line[], int limit) {
	int c, len;

	for (len = 0; ((c = getchar()) != '\n') && (c != EOF) && (len < limit); len++) {
		line[len] = c;
	}

	/* Add null terminator to end the string. */
        line[len] = '\0';
	
	/* The newline is a character, so if one exists, include it in the line length. */
	if (c == '\n') {
		len++;
	}

	return len;
}

/* This function copies the contents from one array into another.
   It is assumed that the destination array has enough space for
   the contents. The null teriminator is copied over. */
void copy(char origin[], char destination[]) {
	int i;

	for (i = 0; ((destination[i] = origin[i]) != '\0'); i++) {
		;
	}
}

/* This program reads lines of text from the input buffer and then prints
   the longest one to the output buffer. */
int main() {

	int i, length = 0, max_length = 0;
	char line[MAXLINE];
	char longest_line[MAXLINE];

	/* Line length will always be greater than zero unless the line consists
	   solely of EOF. */
	while ((length = getline_new(line, MAXLINE)) > 0) {
		if (length > max_length) {
			max_length = length;
			copy(line, longest_line);	
		}
	}

	/* Print the longest line to standard output. */
	for (i = 0; longest_line[i] != '\0'; i++) {
		putchar(longest_line[i]);
	}
	putchar('\n');
}
		
