#include <stdio.h>

/* This program replaces sequences of one or more blanks with a 
   single blank and prints the result. */ 
int main() {
	int c;
	int blank = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			if (blank == 0) {
				putchar(c);
				blank = 1;
			}
		} else {
			putchar(c);
			blank = 0;
		}		
	}
}
