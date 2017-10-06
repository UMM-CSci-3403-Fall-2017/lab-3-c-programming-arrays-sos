#include "mergesort.h"
#include <stdlib.h>
#include <stdio.h>

// This is a main method which simply makes a sample array of numbers,
// sorts it, and then makes an array of characters to be printed.
int main(int argc, char* argv[]) {
	int line[5] = {8,4,9,4,3};
	char* returnStr = calloc(100, sizeof(char));
	//returnStr[0] = '[';
	printf("%s\n",returnStr);
	mergesort(5, line);

	for(int i = 0; i < 5; i++){
		printf("%d\n",line[i]);
        }
	returnStr = returnStr + '\0';
	printf("%s\n", returnStr);
	printf("%s\n","asdf");
	
	



}



