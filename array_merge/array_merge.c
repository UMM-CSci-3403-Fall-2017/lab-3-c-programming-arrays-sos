#include "array_merge.h"
#include <stdlib.h>
#include "mergesort.h"

int* array_merge(int num_arrays, int* sizes, int** values){
	
	//the following for loop sorts all the elements in each subarray
	//in the matrix.
	for(int i = 0; i < num_arrays; i++){
		mergesort(sizes[i], values[i]);
	}

}



