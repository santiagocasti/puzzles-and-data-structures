/**
 * The problem goes more or less as follows:
 * 		Implement a function that finds in an array two numbers that
 *		add up to a certain value, if they exist.
 *
 * I extended the problem afterwards to the case of finding three numbers.
 */

#include<iostream>

using namespace std;

/**
 * Given an array of defined size, returns true when a sum of TWO numbers of
 * the array can add up to 'sum'.
 * Returns false in any other case.
 * Assumptions:
 * 		- 'array' is sorted
 *		- 'size' is the true size of 'array'
 */
bool canAddUpWithTwo(int *array, int size, int sum)
{
	int *start, *end;
	int startIndex = 0, endIndex = size-1;

	start = array;
	end = array + size - 1;

	while(start != end){
		if (*start + *end == sum){
			printf("The sum can add up to [%d] using position [%d]=%d and [%d]=%d\n", sum, startIndex, *start, endIndex, *end);
			return true;
		}

		if (*start + *end > sum){
			endIndex--;
			end--;
			continue;
		}

		if (*start + *end < sum){
			startIndex++;
			start++;
			continue;
		}
	}

	printf("The sum can't add up using two numbers.\n");

	return false;
}

/**
 * Given an array of defined size, the positions of two numbers in this array,
 * find out if there is a third number such that the sum of the three adds up to 'sum'.
 * Assumptions:
 * 		- 'array' is sorted
 *		- 'size' is the true size of 'array'
 */
bool canFindAThirdOne(int *array, int size, int sum, int startIndex, int endIndex){

	int i;
	for (i=0; i<size; ++i){

		// skip (start + start + end) and (start + end + end)
		// from the possible results
		if (i == startIndex ||
			i == endIndex){
			continue;
		}

		// check if the sum adds up
		if (array[i] + array[startIndex] + array[endIndex] == sum){
			printf(
				"The sum can add up to [%d] using position [%d]=%d, [%d]=%d and [%d]=%d\n",
				sum, startIndex, array[startIndex], endIndex, array[endIndex], i, array[i]);
			return true;
		}
	}

	return false;
}

/**
 * Given an array of defined size, returns true when a sum of THREE numbers of
 * the array can add up to 'sum'.
 * Returns false in any other case.
 * Assumptions:
 * 		- 'array' is sorted
 *		- 'size' is the true size of 'array'
 */
bool canAddUpWithThree(int *array, int size, int sum)
{
	int *start, *end;
	int startIndex = 0, endIndex = size-1;
	int iteration = 0;

	start = array;
	end = array + size - 1;


	while(start != end){

		// if we can find a third one, then we are done
		if (canFindAThirdOne(array, size, sum, startIndex, endIndex)){
			return true;
		}

		// move pointers one at a time in an ordered way
		if (iteration % 2 == 0){
			start++;
			startIndex++;
		}else{
			end--;
			endIndex--;
		}
	}

	printf("The sum can't add up using three numbers.\n");

	return false;
}


int main(int argc, char **argv)
{
	int sortedArray[] = {-9,-8,-5,-3,-1,1,1,3,4,7,10,12,17,18};
	int size = sizeof(sortedArray)/sizeof(*sortedArray);
	int sum = 6;

	canAddUpWithTwo(sortedArray, size, sum);
	canAddUpWithThree(sortedArray, size, sum);
}



