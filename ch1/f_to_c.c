#include <stdio.h>

/* Print a conversion table for temperatures in deg F and deg C */

int main() {
	double fahrenheit;

	printf("Fahrenheit  Celsius\n");
	for (fahrenheit = 0; fahrenheit <= 300; fahrenheit += 10) {
		printf("%10.2f  %7.2f\n", fahrenheit, (fahrenheit - 32) * 5/9);
	}
}   
