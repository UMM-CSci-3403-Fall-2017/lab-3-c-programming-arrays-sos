#include "array_merge.h"
#include <stdlib.h>
#include "../mergesort/mergesort.h"
#include <stdio.h>

int* array_merge(int num_arrays, int* sizes, int** values){
	int allElementsLength = 0;	
	//the following for loop sorts all the elements in each subarray
	//in the matrix.
	if((num_arrays < 2 && sizes[0] == 1) || num_arrays == 0){
		allElementsLength = 1;
	} else{
	for(int i = 0; i < num_arrays; i++){
		allElementsLength += sizes[i];
	}
	}
	//do gross thing that checks the number of unique numbers to get
	//size for the calloc, then calloc two arrays, one for the used unique
	//numbers, and an array with the total number of elements.  
	//
	//EASIER SOLUTION, add all elements into one big array of size
	//num_arrays*(sum of sizes), then do aformentioned steps.
	int* allElements = (int*)calloc(allElementsLength, sizeof(int));
	int allElementCounter = 0;
	for(int i = 0; i < num_arrays; i++){
		for(int p = 0; p < sizes[i]; p++){
			allElements[allElementCounter] = values[i][p];
			allElementCounter++;
		}
	}		
	int uniqueNum = 0;
	mergesort(allElementsLength, allElements);
	for (int i = 0;i<allElementsLength; i++) {
		if(i == 0){
			uniqueNum++;
		}
		else if(allElements[i-1]!=allElements[i]){
			uniqueNum++;
		}
	}
	
	int* returnArr;
	int returnArrCounter = 0;
	if(num_arrays == 1 && sizes[0] == 1){
		returnArr =(int*) calloc(2, sizeof(int));
		returnArr[0] = 1;
		returnArr[1] = values[0][0];
        }
        else if(num_arrays == 0){
		returnArr =(int*) calloc(1, sizeof(int));
		returnArr[0] = 0;
	}
	else{
		returnArr =(int*) calloc(uniqueNum, sizeof(int));
		for (int i = 0;i<allElementsLength; i++) {
                	if(i == 0){
                        	returnArr[returnArrCounter] = uniqueNum;
				returnArrCounter++;
                	}
			else if(i == 1){
				returnArr[returnArrCounter] = allElements[0];
				returnArrCounter++;
			}
			else if(allElements[i-1]!=allElements[i]){
                        	returnArr[returnArrCounter] = allElements[i];
				returnArrCounter++;
                	}

        	}
	}
	free(allElements);
	return returnArr;
}



