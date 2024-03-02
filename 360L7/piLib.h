#ifndef PILIB_H
#define PILIB_H

/*
 * pi_serial
 * Calculates and returns the value of pi to an error (decimal places) of e using a specified equation.
 * Parameters: 
 * x - Initially a number given that approaches pi as the loops continue and stores the current value of pi.
 * e - the number of decimal places to calculate pi
 * return: the value of pi
 */
double pi_serial(double *x, double e);

/*
 * pi_mutex
 * Calculates and returns the value of pi to an error (decimal places) of e using pthread mutexes and a specified equation.
 * Parameters: 
 * x - stores the value of pi. 
 * e - the number of decimal places to calculate pi
 * int - number of threads to run on
 * return: the value of pi
 */
double pi_mutex(double y, double e, int threads);

/*
 * pi_semaphore
 * Calculates and returns the value of pi to an error (decimal places) of e using the semaphore library and a specified equation.
 * Parameters: 
 * x - stores the value of pi. 
 * e - the number of decimal places to calculate pi
 * int - number of threads to run on
 * return: the value of pi
 */
double pi_semaphore(double y, double e, int threads);

#endif 
