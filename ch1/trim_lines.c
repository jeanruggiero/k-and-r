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

/* This program removes trailing blanks and tabs from each line of text and prints
 * the line to standard output. Entirely blank lines are deleted. */
int main() {
	
	int i, j, length = 0;
	char line[MAXLINE];

	while ((length = getline_new(line, MAXLINE)) > 0) {
		for (i = length-2; (line[i] == ' ') || (line[i] == '\t'); i--) {
			;
		}

		for (j = 0; j <= i; j++) {
			putchar(line[j]);
		}
		putchar('\n');
	}
}

