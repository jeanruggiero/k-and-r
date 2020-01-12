
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

/* This program reads lines of text from standard input and prints ones longer than 80 
   characters. */
int main() {

	int i, length = 0;
	char line[MAXLINE];

	while ((length = getline_new(line, MAXLINE)) > 0) {
		if (length > 80) {
			for (i = 0; line[i] != '\0'; i++) {
				putchar(line[i]);
			}
			putchar('\n');
		}
	}
} 
