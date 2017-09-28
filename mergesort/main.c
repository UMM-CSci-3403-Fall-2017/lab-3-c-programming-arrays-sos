#include "mergesort.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	int line[5] = {8,4,9,4,3};
	char* returnStr = "[";

	mergesort(5, line);

	for(int i = 0; i < 5; i++){
		returnStr = returnStr + line[i] + ',' + ' ';
		if(i == 4){
                        returnStr = returnStr + line[i] + ']';
                }
        }

	printf(returnStr,"\n");
	
	



}



