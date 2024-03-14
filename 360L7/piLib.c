#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/sysinfo.h>
#include "piLib.h"

// mutex and semaphore variables
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
sem_t sem_lock;

// Example input: e = 0.001 (1x10^-3)

// Equation used:
// 1 + (1/(4n^2 - 1)) / (1/(4n^2 - 1))

// Error is defined as y = |y - yold| (absolute value of our current iteration of y - our previous iteration of y)
// While error is <= to the precision defined at the start, e, we should keep going

double pi_serial(double *x, double e){
	double y = *x;
	double yOld;
	double error;
	double a = 1.0; // Constant 1 in formula
	double b = 4.0; // Constant 2 in formula
	double c = 2.0; // Constant 3 in formula (power)
	int n = 1;
	double numerator = (a + (a/(b*pow((double) n, c)-a)));
	double denominator = (a/(b*pow((double) n, c)-a));
	y = numerator/denominator;

	// Continue until error <= e
	while (1){
		yOld = y;
		n++;
		numerator = numerator * (a + (a/(b*pow((double) n, c)-a)));
		denominator = denominator + (a/(b*pow((double) n, c)-a));
		y = numerator/denominator;
		error = fabs(y-yOld);	
		if (error <= e){
			break;
		}
	}
	yOld = y;
	return yOld;
}

// pi_mutex helper function - what each thread will run 
void* mutexfun(void* args){
	struct data* d = (struct data*) args;
	double yOld;
	double a = 1.0; // Constant 1 in formula
	double b = 4.0; // Constant 2 in formula
	double c = 2.0; // Constant 3 in formula (power)

	// Each thread will iterate 500 times before mutex unlocks 
	pthread_mutex_lock(&lock);
        while (1){
		yOld = *(d->y);
		++*(d->n);
		*(d->numerator) = *(d->numerator) * (a + (a/(b*pow((double) *(d->n), c)-a)));
		*(d->denominator) = *(d->denominator) + (a/(b*pow((double) *(d->n), c)-a));
		*(d->y) = *(d->numerator)/(*(d->denominator));
		*(d->error) = fabs(*(d->y)-yOld);	
		if (*(d->error) <= d->e){
			break;
		}
		if (*(d->n)%500 == 0){
			break;
		}
	}
	pthread_mutex_unlock(&lock);
        return(NULL);
}

double pi_mutex(double *x, double e, int threads){
	double y = *x;
	double error = 1.0;
	double a = 1.0; // Constant 1 in formula
	double b = 4.0; // Constant 2 in formula
	double c = 2.0; // Constant 3 in formula (power)
	int n = 1; // For numerator and denominator	
	double numerator = (a + (a/(b*pow((double) n, c)-a)));
	double denominator = (a/(b*pow((double) n, c)-a));
	y = (numerator/denominator);
	
	// pthread variables and struct
	int nprocs = threads;
	pthread_t tid[nprocs];
	struct data pidata[nprocs];

	// Continue making and remaking threads until reaching set error
	while (error > e){
		// Create threads
	        for (int i=0; i<nprocs; i++){
			pidata[i].y = &y;
			pidata[i].error = &error;
			pidata[i].numerator = &numerator;
			pidata[i].denominator = &denominator;
			pidata[i].n = &n;
			pidata[i].e = e;
               		pthread_create(&tid[i], NULL, mutexfun, &pidata[i]);
	       	}
        
		// Join - Wait for thread to finish
        	for(int i=0; i<nprocs; i++){
			pthread_join(tid[i], NULL);
       	 	}
	}
	return y;
}

void* semaphorefun(void* args){
	struct data* d = (struct data*) args;
	double yOld;
	double a = 1.0; // Constant 1 in formula
	double b = 4.0; // Constant 2 in formula
	double c = 2.0; // Constant 3 in formula (power)

	// Each thread will iterate 500 times before mutex unlocks 
        sem_wait(&sem_lock);	
        while (1){
		yOld = *(d->y);
		++*(d->n);
		*(d->numerator) = *(d->numerator) * (a + (a/(b*pow((double) *(d->n), c)-a)));
		*(d->denominator) = *(d->denominator) + (a/(b*pow((double) *(d->n), c)-a));
		*(d->y) = *(d->numerator)/(*(d->denominator));
		*(d->error) = fabs(*(d->y)-yOld);	
		if (*(d->error) <= d->e){
			break;
		}
		if (*(d->n)%500 == 0){
			break;
		}
	}
	sem_post(&sem_lock);
	
        return(NULL);
}

double pi_semaphore(double *x, double e, int threads){
	double y = *x;
	double error = 1.0;
	double a = 1.0; // Constant 1 in formula
	double b = 4.0; // Constant 2 in formula
	double c = 2.0; // Constant 3 in formula (power)
	int n = 1; // For numerator and denominator	
	double numerator = (a + (a/(b*pow((double) n, c)-a)));
	double denominator = (a/(b*pow((double) n, c)-a));
	y = (numerator/denominator);
	
	// pthread variables and struct
	int nprocs = threads;
	pthread_t tid[nprocs];
	struct data pidata[nprocs];
	sem_init(&sem_lock, 0, nprocs); // Initialize to number of threads

	// Continue making and remaking threads until reaching set error
	while (error > e){
		// Create threads
	        for (int i=0; i<nprocs; i++){
			pidata[i].y = &y;
			pidata[i].error = &error;
			pidata[i].numerator = &numerator;
			pidata[i].denominator = &denominator;
			pidata[i].n = &n;
			pidata[i].e = e;
               		pthread_create(&tid[i], NULL, semaphorefun, &pidata[i]);
	       	}
        
		// Join - Wait for thread to finish
        	for(int i=0; i<nprocs; i++){
			pthread_join(tid[i], NULL);
       	 	}
	}
	return y;
}

