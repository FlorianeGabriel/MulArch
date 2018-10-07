/*
============================================================================
Filename    : integral.c
Author      : Your names goes here
SCIPER		: Your SCIPER numbers
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "utility.h"
#include "function.c"

double integrate (int num_threads, int samples, int a, int b, double (*f)(double));

int main (int argc, const char *argv[]) {

    int num_threads, num_samples, a, b;
    double integral;

    if (argc != 5) {
		printf("Invalid input! Usage: ./integral <num_threads> <num_samples> <a> <b>\n");
		return 1;
	} else {
        num_threads = atoi(argv[1]);
        num_samples = atoi(argv[2]);
        a = atoi(argv[3]);
        b = atoi(argv[4]);
	}

    set_clock();

    /* You can use your self-defined funtions by replacing identity_f. */
    integral = integrate (num_threads, num_samples, a, b, identity_f);

    printf("- Using %d threads: integral on [%d,%d] = %.15g computed in %.4gs.\n", num_threads, a, b, integral, elapsed_time());

    return 0;
}


double integrate (int num_threads, int samples, int a, int b, double (*f)(double)) {
    double integral;
    double sum = 0;

	omp_set_num_threads(num_threads);
	
	//the minimum to do for each thread
	int splitSamples = samples / num_threads;
	
	#pragma omp parallel 
	{
		//since the division samples / num_threads isnt a complete division
		//we need to take the modulo to add them to one thread
		int id = omp_get_thread_num();
		//we add them to the main thread ( where the id is 0)
		if(id == 0) splitSamples += samples % num_threads;
		
		double sumThread = 0;
		rand_gen genThread = init_rand();
	    
		for(int i = 0; i < splitSamples; i++){
			double g = next_rand(genThread);
			double x = a*(1-g) + g*b;
			sumThread += f(x)*(b-a);

		}
    #pragma omp atomic
	sum += sumThread; //need to be atomic since all thread can add at the same time
	}
	
	
	integral = sum/samples;
    

    return integral;
}
