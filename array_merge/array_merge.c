#include "array_merge.h"
#include <stdlib.h>
#include "mergesort.h"

int* array_merge(int num_arrays, int* sizes, int** values){
	
	int allElementsLength = 0;	
	//the following for loop sorts all the elements in each subarray
	//in the matrix.
	for(int i = 0; i < num_arrays; i++){
		allElementsLength += sizes[i];
	}
	//do gross thing that checks the number of unique numbers to get
	//size for the calloc, then calloc two arrays, one for the used unique
	//numbers, and an array with the total number of elements.  
	//
	//EASIER SOLUTION, add all elements into one big array of size
	//num_arrays*(sum of sizes), then do aformentioned steps.
	int* allElements = calloc(allElementsLength, sizeof(int));
	int allElementCounter = 0;
	for(int i = 0; i < num_arrays; i++){
		allElementCounter++;
		for(int p = 0; p < sizes[i]; p++){
			allElements[allElementCounter] = values[i][p];
			printf(values[i][p]);
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
	int returnArrCounter = 0;
	int* returnArr = calloc(uniqueNum, sizeof(int));
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



