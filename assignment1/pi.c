/*
============================================================================
Filename    : pi.c
Author      : Your names goes here
SCIPER		: Your SCIPER numbers
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

double calculate_pi (int num_threads, int samples);

int main (int argc, const char *argv[]) {

    int num_threads, num_samples;
    double pi;

    if (argc != 3) {
		printf("Invalid input! Usage: ./pi <num_threads> <num_samples> \n");
		return 1;
	} else {
        num_threads = atoi(argv[1]);
        num_samples = atoi(argv[2]);
	}

    set_clock();
    pi = calculate_pi (num_threads, num_samples);

    printf("- Using %d threads: pi = %.15g computed in %.4gs.\n", num_threads, pi, elapsed_time());

    return 0;
}


double calculate_pi (int num_threads, int samples) {
    double pi;
	int sum = 0;

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
	    
		for(int i = 0 ; i < splitSamples; i++){
			double x = next_rand(genThread);
			double y = next_rand(genThread);
			if(x*x + y*y <= 1) {
				sumThread++;
			}
		}
		#pragma omp atomic
		sum += sumThread;
	}
	
	pi = 4.0 * (double)sum / samples;

    return pi;
}
