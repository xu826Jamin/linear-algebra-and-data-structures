#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include "Questions.h"



void add_vectors(double vector1[],double vector2[],double vector3[],int size)
{
    /*vector3 should store the sum of vector1 and vector2. 
	You may assume that all three arrays have the size equal to the input parameter "size"
	*/
	//write your code below
	int counter;
	// Add corresponding elements
	for(counter = 0; counter < size; ) {
		// Sum the elements at current position
		vector3[counter] = vector1[counter] + vector2[counter];
		counter++;
	}
}

double scalar_prod(double vector1[],double vector2[],int size)
{
	// this is the variable holding the scalar product of the two vectors
    double result = 0.0;
	int index;

	//write your code below to calculate the prod value
	for(index = 0; index < size; index += 1) {
		// Multiply corresponding elements and accumulate
		double temp = vector1[index] * vector2[index];
		result = result + temp;
	}
	
	// return the result
    return result;
}

double norm2(double vector1[], int size)
{
	//this is the variable holding the L2 norm of the passed vector
    double magnitude;
	    
	//write your code here
	// you should call function scalar_prod().
	// Calculate the dot product with itself
	double squared_sum = scalar_prod(vector1, vector1, size);
	
	// Take the square root to get the magnitude
	magnitude = sqrt(squared_sum);
	
	//finally, return the L2 norm 
    return magnitude;
}