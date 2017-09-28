#include "mergesort.h"
#include <stdlib.h>

bool needsSorting(int rangeSize) {
        return rangeSize >= 2;
}

void mergeRanges(int* values, int start, int mid, int end){
	int rangeSize = end - start;
	int* destination = (int*) calloc(rangeSize+1, sizeof(int));
	int firstIndex = start;
	int secondIndex = mid;
	int copyIndex = 0;
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
	for (int i = 0; i < rangeSize; ++i) {
		values[i + start] = destination[i];
	}
	free(destination);
}

void mergesortRange(int* values, int start, int end) {
        int rangeSize = end - start;
        if(needsSorting(rangeSize)) {
                int mid = (start + end)/2;
                mergesortRange(values, start, mid);
                mergesortRange(values, mid, end);
		mergeRanges(values, start, mid, end);

        }
}


void mergesort(int size, int* values){
        mergesortRange(values, 0, size);
}


