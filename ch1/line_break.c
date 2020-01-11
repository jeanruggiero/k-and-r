#include <stdio.h>

/* This program prints its input one word per line. */
int main() {
	
	int c;

	while ((c = getchar()) != EOF) {
		if ((c == ' ') || (c == '\t')) {
			putchar('\n');
		} else {
			putchar(c);
		}
	} 
}
