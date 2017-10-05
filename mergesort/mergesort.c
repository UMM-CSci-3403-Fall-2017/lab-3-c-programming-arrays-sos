#include "mergesort.h"
#include <stdlib.h>

//function that returns a boolean determining if the range is less than or equal to two.
bool needsSorting(int rangeSize) {
        return rangeSize >= 2;
}

//This method is recursively called in ordeer to sort any given array segments.
void mergeRanges(int* values, int start, int mid, int end){
	int rangeSize = end - start;
	int* destination = (int*) calloc(rangeSize+1, sizeof(int));
	int firstIndex = start;
	int secondIndex = mid;
	int copyIndex = 0;
	// This checks to see if the first index is less than the second index, and if so is added to the 'destination' array, if not then the second index is added. This goes until one of the indexes exceeds beyond its segment. 
	while (firstIndex < mid && secondIndex < end){
		if(values[firstIndex] < values[secondIndex]) {
			destination[copyIndex] = values[firstIndex];
			++firstIndex;	
		}
		else{
			destination[copyIndex] = values[secondIndex];
			++secondIndex;
		}
		++copyIndex;
	}
	// These next two while loops are for whichever segment did not get fully copied over yet from the last loop. At this point, the values left over simply get added on to the destination array.
	while (firstIndex < mid) {
		destination[copyIndex] = values[firstIndex];
		++copyIndex;
		++firstIndex;
	}
	while (secondIndex < end) {
		destination[copyIndex] = values[secondIndex];
		++copyIndex;
		++secondIndex;
	}
	// This for loop copies over values from the destination array to the values array for the extent of the given range.
	for (int i = 0; i < rangeSize; ++i) {
		values[i + start] = destination[i];
	}
	//This is the last time destination is used within any given use of this method, so it is freed at this point
	free(destination);
}

//mergesortRange takes an array of integers, a start position, and an end postion
//to represent the subarrays in mergesort, this is recursed on both sides until each
//subarray is of length two or less, and mergeRanges is run on each subarray until the array is sorted
void mergesortRange(int* values, int start, int end) {
        int rangeSize = end - start;
        if(needsSorting(rangeSize)) {
                int mid = (start + end)/2;
                mergesortRange(values, start, mid);
                mergesortRange(values, mid, end);
		mergeRanges(values, start, mid, end);

        }
}

// main method that calls mergesortRange for recursive reasons.
void mergesort(int size, int* values){
        mergesortRange(values, 0, size);
}


