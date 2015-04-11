#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/**
 * Perform a binary search in a portion of 'array' from 'lower' to 'upper' elements,
 * trying to find the number 'target'
 */
int binarySearch(int **array, int lower, int upper, int target){

	int middle = lower + ((upper-lower)/2); //middle of the range

	printf("set[%d-%d] - target:%d - middle:%d - ", lower, upper, target, (*array)[middle]);

	if ((*array)[middle]>target){
		printf("lower\n");
		return binarySearch(array, lower, middle, target);
	}else if ((*array)[middle]<target){
		printf("upper\n");
		return binarySearch(array, middle, upper, target);
	}else{
		printf("DONE!\n");
		return middle;
	}
}

/**
 * Build a sorted array of size 'size' filled with integers.
 */
void buildArray(int **array, int size){
	int i,j;
	(*array) = (int*)malloc(size*sizeof(int));
	
	(*array)[0] = 0;
	
	for (i=1;i<size;i++){
		(*array)[i] = (*array)[i-1] + rand()%10;
	}
}


int main(int argc, char *argv[]){
	int i, j, size, n = 10;
	int *results;
	
	printf("Lets perform a Binary Search over an ordered array:\n");
	//random number generator
	srand(time(NULL));

	size = pow(2,n);
	buildArray(&results, size);

	printf("We have an array of size %d, which element do you want to look for?\n", size);
	scanf("%d", &i);

	printf("The element in position %d is %d\n",i,results[i]);
	
	j = binarySearch(&results, 0, size-1, results[i]);
	printf("The Binary search returned: array[%d] = %d\n", j, results[j]);
	
}




















