#include <stdio.h>

int main() {
	int c;

	printf("The value of EOF is: %d\n\n", EOF);

	while ((c = getchar()) != EOF) {
		putchar(c);
	}
}

