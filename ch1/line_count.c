#include <stdio.h>

int main() {
	int lines = 0;
	int c;

	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			lines++;
		}
	}

	printf("The line count is: %d\n", lines);
}
