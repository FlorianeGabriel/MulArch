/*
============================================================================
Filename    : algorithm.c
Author      : Your names go here
SCIPER      : Your SCIPER numbers

============================================================================
*/
#include <math.h>

#define INPUT(I,J) input[(I)*length+(J)]
#define OUTPUT(I,J) output[(I)*length+(J)]

void simulate(double *input, double *output, int threads, int length, int iterations)
{
	omp_set_num_threads(threads);
	double *temp;
    
    const size_t block_size = length / threads;
    
    for(int n=0; n < iterations; n++)
    {
		#pragma omp parallel for collapse(2)

		for(int k = 1; k < length; k+= block_size){
			for(int l = 1; l < length; l += block_size){
					
				for(int i=k; i<length-1 && i < k + block_size; i++)
				{	
					for(int j=l; j<length-1 && l + block_size; j++)
					{

							OUTPUT(i,j) = (INPUT(i-1,j-1) + INPUT(i-1,j) + INPUT(i-1,j+1) +
										   INPUT(i,j-1)   + INPUT(i,j)   + INPUT(i,j+1)   +
										   INPUT(i+1,j-1) + INPUT(i+1,j) + INPUT(i+1,j+1) )/9;
					}
				}
				OUTPUT(length/2 - 1, length/2 - 1) = INPUT(length/2 - 1, length/2 - 1);
				OUTPUT(length/2 - 1, length/2) = INPUT(length/2 - 1, length/2);
				OUTPUT(length/2, length/2 - 1) = INPUT(length/2, length/2 - 1);
				OUTPUT(length/2, length/2) = INPUT(length/2, length/2);        

				temp = input;
				input = output;
				output = temp;
			}
		}
	}
}
