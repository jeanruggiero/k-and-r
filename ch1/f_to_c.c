#include <stdio.h>

/* Convert a temperature from deg Fahrenheit to deg Celsius. */
double f_to_c(double fahrenheit) {
	return (fahrenheit - 32) * 5 / 9;
}

/* Print a conversion table for temperatures in deg F and deg C */
int main() {
	double fahrenheit;

	printf("Fahrenheit  Celsius\n");
	for (fahrenheit = 0; fahrenheit <= 300; fahrenheit += 10) {
		printf("%10.2f  %7.2f\n", fahrenheit, f_to_c(fahrenheit));
	}
}   
