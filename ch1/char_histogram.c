#include <stdio.h>

/* This program prints a histogram of letter frequencies from the input. */
int main() {

	int c, i, j, word_length = 0;
	int max_count = 0;

	int counts[26];

	for (i = 0; i < 26; i++) {
		counts[i] = 0;
	}

	/* Determine frequency of each letter (case insensitive). */
	while ((c = getchar()) != EOF) {
		if ((c >= 'A') && (c <= 'Z')) {
			counts[c - 'A']++;
		} else if ((c >= 'a') && (c <= 'z')) {
			counts[c - 'a']++;
		}
	}

	/* Determine the maximum frequency value. */
	for (i = 1; i < 26; i++) {
		if (counts[i] > max_count) {
			max_count = counts[i];
		}
	}

	/* Draw histogram. */
	while (max_count > 0) {
		for (j = 0; j < 26; j++) {
			if (counts[j] >= max_count) {
				putchar('+');
			} else {
				putchar(' ');
			}
			putchar(' ');
		}
		putchar('\n');
		max_count--;
	}

	/* Label histogram. */
	for (i = 0; i < 26; i++) {
		putchar(i + 'A');
		putchar(' ');
	}
	putchar('\n');
}
