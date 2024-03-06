#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "piLib.h"

// Example input: e = 0.001 (1x10^-3)
// y in one case is numerator, and y in another case is the denominator
// Keep adding to pi by adding (or maybe multiplying) smaller and smaller values (5/8, 1/2, 1/4, 9/180)
// Start at n=1

// The equation used is:
// 1 + (1/(4n^2 - 1)) / (1/(4n^2 - 1))

//So for n = 1, 2, 3... 

// 1 + (1/4 - 1) / (1/4 -1) n = 1
// 1 + (1/16 - 1) / (1/16 -1) n = 2
// 1 + (1/36 - 1) / (1/36 -1) n = 3

// (Product of y)/(summation of y)

// Dave's results for his pi_serial function:
// n = 1, pi = 4
// n = 2, pi = 3.55
// As long as my function follows this kind of path i'll be good

// Error is defined as y = |y - yold| (absolute value of our current iteration of y - our previous iteration of y)
// While error is <= to the precision defined at the start, e, we should keep going

// Will require thousands of loops to reach our number
double pi_serial(double *x, double e){
	double y = *x;
	double yOld;
	double error;
	double a = 1.0; // Constant 1 in formula
	double b = 4.0; // Constant 2 in formula
	double c = 2.0; // Constant 3 in formula (power)
	int n = 1; // For numerator and denominator
	int i = 0;	
	double numerator = (a + (a/(b*pow((double) n, c)-a))) * (a + (a/(b*pow((double) n, c)-a)));
	double denominator = (a/(b*pow((double) n, c)-a)) + (a/(b*pow((double) n, c)-a));
	y = (numerator/denominator);
	printf("Current pi: %f\nCurrent n: %d\n", y, n);

	// Continue until error >= e
	while (1){
		yOld = y;
		n++;
		numerator = (a + (a/(b*pow((double) n, c)-a))) * (a + (a/(b*pow((double) n, c)-a)));
		denominator = (a/(b*pow((double) n, c)-a)) + (a/(b*pow((double) n, c)-a));
		y = (numerator/denominator);
		error = fabs(y-yOld);
		printf("Current pi: %f at iteration %d\nCurrent error: %f\n", y, n, error);
		
		// Continue while current error is less than the precision we set 
		// if (error <= e)
		if (n == 100){ // Arbitrary, just want to see what it prints at n=10	
			break;
		}
	}
	yOld = y;

	printf("4*(3)^2 = %f\n", 4.0*pow(3.0, 2.0));
	printf("4*(1)^2 = %f\n", 4.0*pow(1.0, 2.0));		
	return yOld;
}

// Test
int main(void){
	double a = 4.0;
	pi_serial(&a, 0.0001);
}

/*
double pi_mutex(double x, double e, int threads);

double pi_semaphore(double x, double e, int threads);
*/
