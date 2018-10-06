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
	double sum = 0;

	omp_set_num_threads(num_threads);
	        
    rand_gen gen[num_threads];
    
    /*We thought about parallelising this loop but then thought it was not necessary as we don't have that many threads*/
    for(int i = 0; i < num_threads; i++){
		gen[i] = init_rand();
   }
   
    #pragma omp parallel for
    for(int i = 0 ; i < samples; i++){
		int id = omp_get_thread_num();
		double x = next_rand(gen[id]);
		double y = next_rand(gen[id]);
		if(x*x + y*y <= 1) {
			#pragma omp atomic
			sum++;
		}
	}
	
	pi = 4 * sum / samples;

    return pi;
}
