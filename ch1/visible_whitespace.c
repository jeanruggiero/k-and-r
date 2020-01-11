#include <stdio.h>

/* This program replaces tabs with \t, newlines with \n, and backslashes with \\. */
int main() {
	int c;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			putchar('\\');
			putchar('t');
		} else if (c == '\n') {
			putchar('\\');
			putchar('n');
		} else if (c == '\\') {
			putchar('\\');
			putchar('\\');
		} else {
			putchar(c);
		}
	}
}
