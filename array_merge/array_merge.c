#include "array_merge.h"
#include <stdlib.h>
#include "../mergesort/mergesort.h"
#include <stdio.h>

int* array_merge(int num_arrays, int* sizes, int** values){
	int allElementsLength = 0;	
	//the following for loop returns the number of all the elements
	//in every array.
	for(int i = 0; i < num_arrays; i++){
		allElementsLength += sizes[i];
	}
	//A new array is created to store every element in each subarray.
	int* allElements = (int*)calloc(allElementsLength, sizeof(int));
	int allElementCounter = 0;
	//This for loop adds each element from each subarray into the newly
	//defined array
	for(int i = 0; i < num_arrays; i++){
		for(int p = 0; p < sizes[i]; p++){
			allElements[allElementCounter] = values[i][p];
			allElementCounter++;
		}
	}		
	int uniqueNum = 0;
	//The array of every element is sorted
	mergesort(allElementsLength, allElements);
	//The sorted array of every element is checked for unique elements
	//which when sorted will simply be the next new element.  This number
	//of unique elements is stored in variable uniqueNum.
	for (int i = 0;i<allElementsLength; i++) {
		if(i == 0){
			uniqueNum++;
		}
		else if(allElements[i-1]!=allElements[i]){
			uniqueNum++;
		}
	}
	//The following conditionals check for scenarios that need special
	//return values.
	int* returnArr;
	int returnArrCounter = 0;
	//This condition is met with a single array of one element
	//only the size and element are returned.
	if(num_arrays == 1 && sizes[0] == 1){
		returnArr =(int*) calloc(2, sizeof(int));
		returnArr[0] = 1;
		returnArr[1] = values[0][0];
        }
	//This condition is met when an empty array is passed in, only
	//the size is returned.
        else if(num_arrays == 0){
		returnArr =(int*) calloc(1, sizeof(int));
		returnArr[0] = 0;
	}
	//This condition is met when the previous two conditions are not,
	//a return array is stored in memory, and each unique element is 
	//added to the return array from the already sorted allElements list
	//thus returning a sorted array of unique elements.
	else{
		returnArr =(int*) calloc(uniqueNum + 1, sizeof(int));
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



