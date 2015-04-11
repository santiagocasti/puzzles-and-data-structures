/**
 * Calculating factorial numbers recursively.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

//Recursive method for doing the actual factorial calculations
int calculateFactorials(int n, int **results){
	if (n>1){
		//recursive case
		(*results)[n] = n * calculateFactorials(n-1, results);
		return (*results)[n];
	}else{
		//base case
		(*results)[0] = 1;
		(*results)[1] = 1;
		return 1;
	}
}

//Method for allocating memory and initiate the calculations
int *allFactorials(int n){
	int *results = (int*)malloc(sizeof(int)*n);
	calculateFactorials(n, &results);
	return results;
}

int main(int argc, char *argv[]){
	int n; //biggest factorial to calculate
	int i;
	int *results;

	if (argc>1){
		n = atoi(argv[1]) + 1;
	}else{
		n = 10;
	}
	printf("Lets calculate some Factorials: from 0! to %d!:\n", n);
	results = allFactorials(n);
	for (i = 0; i<n; i++){
		printf("%d! = %d", i, results[i]);
		printf("\n");
	}
}