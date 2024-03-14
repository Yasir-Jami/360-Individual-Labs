// Yasir Jami (3077942)
// CMPT360 Lab 7 

#ifndef PILIB_H
#define PILIB_H

/*
 * pi_serial
 * Calculates and returns the value of pi to an error (decimal places) of e using a specified equation.
 * x - Initially a number given that approaches pi as the loops continue and stores the current value of pi.
 * e - the error to which to calculate pi to - for this lab, functions must work for at least an error of 1E-7
 * return: the value of pi
 */
double pi_serial(double *x, double e);

/*
 * pi_mutex
 * Calculates and returns the value of pi to an error (decimal places) of e using pthread mutexes and a specified equation. 
 * x - stores the value of pi. 
 * e - the error to which to calculate pi to
 * int - number of threads to run on
 * return: the value of pi
 */
double pi_mutex(double *x, double e, int threads);

/*
 * pi_semaphore
 * Calculates and returns the value of pi to an error (decimal places) of e using the semaphore library and a specified equation.
 * x - stores the value of pi. 
 * e - the error to which to calculate pi to
 * int - number of threads to run on
 * return: the value of pi
 */
double pi_semaphore(double *x, double e, int threads);

// Struct for Q2 and Q3
struct data{
        double* y;
        double* error;
	double* numerator;
	double* denominator;
	int* n;
	double e;
};

#endif 
