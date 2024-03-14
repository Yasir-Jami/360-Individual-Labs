// Yasir Jami (3077942)
// CMPT360 Lab 7

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h> 
#include "piLib.h"

// Q4 - testing the functions
int main(void){
	printf("[Function], [Error], [# of threads]\n");
        // TEST 1: error = 1E-7, 4 threads
        double a = 5.0;
        double e = 0.0000001; // 1E-7
	int threads = 4;
        double pi_ser = pi_serial(&a, e);
        double pi_mut = pi_mutex(&a, e, threads);
        double pi_sem = pi_semaphore(&a, e, threads);

	clock_t start_ser, start_mut, start_sem, end_ser, end_mut, end_sem;
     	double ser_time, mut_time, sem_time;
	
	printf("pi_serial, 1E-7: %f\n", pi_ser); 	
	printf("pi_mutex, 1E-7, %d threads: %f\n", threads, pi_mut);		
	printf("pi_semaphore, 1E-7, %d threads: %f\n\n", threads, pi_sem);
	
        // TEST 2: error = 1E-9, 4 threads
        e = 0.000000001; // 1E-9
        pi_ser = pi_serial(&a, e);
        pi_mut = pi_mutex(&a, e, threads);
        pi_sem = pi_semaphore(&a, e, threads);
        printf("pi_serial, 1E-9: %f\n", pi_ser);
        printf("pi_mutex, 1E-9, %d threads: %f\n", threads, pi_mut);
        printf("pi_semaphore, 1E-9, %d threads: %f\n\n", threads, pi_mut);

        // TEST 3: error = 1E-13, 4 threads
        e = 0.000000000001; // 1E-13
        start_ser = clock();
	pi_ser = pi_serial(&a, e);
	end_ser = clock();
	ser_time = ((double) (end_ser - start_ser)) / CLOCKS_PER_SEC;
	
	start_mut = clock();
        pi_mut = pi_mutex(&a, e, 4);
        end_mut = clock();
	mut_time = ((double) (end_mut - start_mut)) / CLOCKS_PER_SEC;
	
	start_sem = clock();
	pi_sem = pi_semaphore(&a, e, 4);
	end_sem = clock();
	sem_time = ((double) (end_sem - start_sem)) / CLOCKS_PER_SEC; 
	
	printf("pi_serial, 1E-13: %f\n", pi_ser);
        printf("pi_mutex, 1E-13, %d threads: %f\n", threads, pi_mut);
        printf("pi_semaphore, 1E-13, %d threads: %f\n", threads, pi_sem);

	printf("ser_time: %f\n", ser_time);
	printf("mut_time: %f\n", mut_time);
	printf("sem_time: %f\n", sem_time);

}
