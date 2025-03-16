#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double getDouble(void);

int main() {
	double n1;
	double n2;
	double sum;
	printf("Enter two floating point numbers to calcualte the sum: \n");
	
	n1 = getDouble();
	n2 = getDouble();

	sum = n1 + n2;
	
	printf("The sum of %lf and %lf is %lf", n1, n2, sum);


	return 0;
}
double getDouble(void) {
	double theValue;
	scanf("%lf", &theValue);
	return theValue;
}