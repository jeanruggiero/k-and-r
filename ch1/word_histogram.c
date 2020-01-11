#include <stdio.h>

/* This program prints a histogram of word lengths from the input. */
int main() {

	int c, i, j, word_length = 0;
	int max_count = 0;

	/* Assume words are shorter than 20 characters. */
	int counts[20];

	for (i = 0; i < 20; i++) {
		counts[i] = 0;
	}

	/* Determine frequency of each word length. */
	while ((c = getchar()) != EOF) {
		if ((c == ' ') || (c == '\n') || (c == '\t')) {
			counts[word_length]++;
			word_length = 0;
		} else {
			word_length++;
		}
	}

	/* Determine the maximum frequency value. */
	for (i = 1; i < 20; i++) {
		if (counts[i] > max_count) {
			max_count = counts[i];
		}
	}

	/* Draw histogram. */
	while (max_count > 0) {
		for (j = 1; j < 20; j++) {
			if (counts[j] >= max_count) {
				putchar('+');
			} else {
				putchar(' ');
			}
			putchar(' ');
			putchar(' ');
		}
		putchar('\n');
		max_count--;
	}

	/* Label histogram. */
	for (i = 1; i < 10; i++) {
		putchar(i + '0');
		putchar(' ');
		putchar(' ');
	}
	
	for (i = 0; i < 10; i++) {
		putchar('1');
                putchar(i + '0');
                putchar(' ');
        }

	putchar('\n');

}
